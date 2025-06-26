#!/usr/bin/env bash

#
# Copyright (C) 2025  Tetex7
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.
#

OUTPUT_BINARY="temp_test_temp"  # Name of the compiled binary
LOG_FILE="valgrind_output.log" # Log file for Valgrind output
OID_LIB_PATH=$LD_LIBRARY_PATH
export LD_LIBRARY_PATH=${PWD}/build:$LD_LIBRARY_PATH

function cli_exit() {
    export LD_LIBRARY_PATH=$OID_LIB_PATH
    exit $1
}

rm -f test.bin

# Compile the source code
echo "Compiling test code"
gcc -g -Wall -Werror -std=c99 -O0 -L./build -I./include -lcso -o "$OUTPUT_BINARY" -x c - <<EOF
/*
 * Copyright (C) 2025  Tetex7
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

//
// Created by tete on 06/22/2025.
//

#include <stdio.h>
#include <libcso/cso_string_c.h>
#include <libcso/cso_instanceof.h>


int main()
{
    cso_string_c str = cso_string_new("test");
    cso_string_view_c string_view = cso_super_cast(cso_string_view_c, str);

    if (!cso_string_view_equals(string_view, "test"))
    {
        if (cso_instanceof(string_view, cso_string_c))
        {
            cso_string_destroy(str);
            return 1;
        }
    }

    printf("output: %s\n", cso_string_view_getRawString(string_view));

#ifndef CSO_CONFIG_USE_LIB_SAFENET // Let's see if libsafetynet actually auto frees memory
    if (cso_instanceof(string_view, cso_string_c))
    {
        cso_string_destroy(str);
    }
#endif
    return 0;
}
EOF

# Check if compilation was successful
if [ $? -ne 0 ]; then
  echo "Compilation failed! Exiting."
  cli_exit 44
fi

# Run the program with Valgrind and log errors if any
echo "Running Valgrind on $OUTPUT_BINARY..."
valgrind --leak-check=full --track-origins=yes ./"$OUTPUT_BINARY" 2>&1 | tee "$LOG_FILE"

if [ $? -ne 0 ]; then
    echo "errors in test code"
fi

# Check if Valgrind reported any errors
if grep -i "ERROR SUMMARY: 0 errors" "$LOG_FILE" > /dev/null; then
  echo "No memory errors detected."
  ecode=0
else
  echo "Memory errors found! Check $LOG_FILE for details."
  ecode=1
fi


rm -f ${OUTPUT_BINARY}
rm -f test.bin
cli_exit $ecode