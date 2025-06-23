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

#include "libcso/cso_string_c.h"
#include "libcso/cso_instanceof.h"
#include "libcso/cso_string_view_c.h"
#include "libcso/csodefs.h"

#include <stdlib.h>

CSO_PUB_API_OPEN
cso_string_c cso_string_new(const char* string)
{
    cso_string_c self = cso_plat_malloc(sizeof(cso_string_t));
    if (!self) return NULL;

    size_t len = strlen(string);
    char* buff = cso_plat_malloc(len + 1);

    if (!buff)
    {
        cso_plat_free(self);
        return NULL;
    }

    memcpy(buff, string, len + 1);

    cso_string_view_initializer(cso_super_cast(cso_string_view_c, self), buff);
    cso_object_initializer(cso_super_cast(cso_object_c, self), cso_toTypeNameStr(cso_string_c));
    return self;
}

void cso_string_destroy(cso_string_c self)
{
    if (!self) return;
    char* raw = (char*)cso_string_view_getRawString(cso_super_cast(cso_string_view_c, self));
    if (raw) cso_plat_free(raw);
    cso_string_view_uninitializer(cso_super_cast(cso_string_view_c, self));
    cso_object_uninitializer(cso_super_cast(cso_object_c, self));
}

CSO_PUB_API_OPEN
cso_string_c cso_string_copy(cso_string_c self)
{
    if(!cso_instanceof(self, cso_string_c)) return NULL;
    cso_string_c new_self = cso_string_new(cso_string_view_getRawString(cso_super_cast(cso_string_view_c, self)));

    return new_self;
}

CSO_PUB_API_OPEN
cso_string_c cso_string_move(cso_string_c self)
{
    if(!cso_instanceof(self, cso_string_c)) return NULL;

    cso_string_c new_self = cso_plat_malloc(sizeof(cso_string_t));
    if (!new_self) return NULL;

    cso_string_view_initializer(
        cso_super_cast(cso_string_view_c, self), 
        cso_string_view_getRawString(cso_super_cast(cso_string_view_c, self))
    );
    cso_object_initializer(cso_super_cast(cso_object_c, self), cso_toTypeNameStr(cso_string_c));

    cso_super_cast(cso_string_view_c, self)->data = NULL;
    cso_super_cast(cso_string_view_c, self)->length = 0;

    return new_self;
}
