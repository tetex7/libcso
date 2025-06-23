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

#ifndef CSO_STRING_C_H
#define CSO_STRING_C_H
#include "libcso/csodefs.h"
#pragma once
#include <libcso/cso_string_view_c.h>

CSO_CPP_COMPAT_START

typedef struct cso_string_s
{
    cso_class_extends(cso_string_view_t);
} cso_string_t;

typedef cso_string_t* cso_string_c;

CSO_PUB_API_OPEN
cso_string_c cso_string_new(const char* string);

CSO_PUB_API_OPEN
void cso_string_destroy(cso_string_c self);

CSO_PUB_API_OPEN
cso_string_c cso_string_copy(cso_string_c self);

CSO_PUB_API_OPEN
cso_string_c cso_string_move(cso_string_c self);

CSO_CPP_COMPAT_END

#endif //CSO_STRING_C_H
