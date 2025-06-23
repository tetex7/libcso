#!/bin/env bash
#
# Copyright (C) 2025 Tetex7
#
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


if [[ "$1" == "clean" ]]; then
    if [[ -f "./Makefile" ]]; then
        make clean
        rm -fv ./Makefile
    elif [[ -f "./build.ninja" ]]; then
        ninja clean
        rm -fv ./build.ninja
    fi
    rm -frv ./build
    rm -frv ./CMakeFiles
    rm -frv ./.cmake
    rm -fv ./compile_commands.json
    rm -fv ./CMakeCache.txt
    rm -fv ./.ninja_*
    rm -fv ./include/libcso/libcso_config.h
    rm -fv libcso-*-x86_64.pkg.tar.zst
else
#CC=/usr/bin/gcc
#Ninja
    cmake -G "Ninja" -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCSO_CONFIG_DEBUG=ON $@  .
fi
