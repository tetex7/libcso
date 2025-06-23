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

#include "libcso/cso_string_view_c.h"

#include <stdlib.h>
#include <string.h>

CSO_PUB_API_OPEN
void cso_string_view_initializer(cso_string_view_c obj, const char* char_string)
{
    if (!obj) return;
    cso_object_initializer(cso_super_cast(cso_object_c, obj), cso_toTypeNameStr(cso_object_c));

    obj->length = strlen(char_string);
    obj->data = char_string;
}

CSO_PUB_API_OPEN
void cso_string_view_uninitializer(cso_string_view_c obj)
{
    if (!obj) return;
    cso_object_uninitializer(cso_super_cast(cso_object_c, obj));
}

CSO_PUB_API_OPEN
cso_string_view_c cso_string_view_new(const char* string)
{
    if (!string) return NULL;
    cso_string_view_c self = cso_plat_malloc(sizeof(cso_string_view_t));
    if (!self) return NULL;

    cso_string_view_initializer(self, string);
    return self;
}

CSO_PUB_API_OPEN
void cso_string_view_destroy(cso_string_view_c self)
{
    if (!self) return;

    cso_string_view_uninitializer(self);
    cso_plat_free(self);
}

CSO_PUB_API_OPEN
const char* cso_string_view_getRawString(cso_string_view_c self)
{
    return self->data;
}

CSO_PUB_API_OPEN
size_t cso_string_view_getLength(cso_string_view_c self)
{
    return self->length;
}

CSO_PUB_API_OPEN
cso_bool cso_string_view_equals(cso_string_view_c self, const char* right)
{
    if (cso_string_view_getLength(self) != strlen(right)) return false;
    return !strncmp(cso_string_view_getRawString(self), right, cso_string_view_getLength(self));
}