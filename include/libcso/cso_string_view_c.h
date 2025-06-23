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
#pragma once

#include "libcso/csodefs.h"
#ifndef CSO_STRING_VIEW_C_H
#define CSO_STRING_VIEW_C_H
#include <libcso/cso_object_c.h>

CSO_CPP_COMPAT_START

typedef struct cso_string_view_s
{
    cso_class_extends(cso_object_t);

    const char* data;
    size_t length;
} cso_string_view_t;

/**
 * @brief A read only view of an ascii string including length metadata
 */
typedef cso_string_view_t* cso_string_view_c;

CSO_PUB_API_OPEN
void cso_string_view_initializer(cso_string_view_c obj, const char* char_string);

CSO_PUB_API_OPEN
void cso_string_view_uninitializer(cso_string_view_c obj);

CSO_PUB_API_OPEN
cso_string_view_c cso_string_view_new(const char* string);

CSO_PUB_API_OPEN
void cso_string_view_destroy(cso_string_view_c self);

CSO_PUB_API_OPEN
const char* cso_string_view_getRawString(cso_string_view_c self);

CSO_PUB_API_OPEN
size_t cso_string_view_getLength(cso_string_view_c self);

CSO_PUB_API_OPEN
cso_bool cso_string_view_equals(cso_string_view_c self, const char* right);

CSO_PUB_API_OPEN
cso_string_view_c cso_string_view_copy(cso_string_view_c self);

CSO_CPP_COMPAT_END

#endif
