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

#include "libcso/cso_object_c.h"

CSO_PUB_API_OPEN
void cso_object_initializer(cso_object_c obj, const char* class_type_name)
{
    if (!obj) return;
    if (!class_type_name)
    {
        obj->class_type_str = cso_toTypeNameStr(cso_object_c);
    }
    obj->class_type_str = class_type_name;
}

CSO_PUB_API_OPEN
const char* cso_object_getClassTypeStr(cso_object_c self)
{
    if (!self) return NULL;

    return self->class_type_str;
}


CSO_PUB_API_OPEN
void cso_object_uninitializer(cso_object_c obj){}
