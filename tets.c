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


    if (cso_instanceof(string_view, cso_string_c))
    {
        cso_string_destroy(str);
    }
}
