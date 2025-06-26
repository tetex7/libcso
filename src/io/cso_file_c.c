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
// Created by tete on 06/23/2025.
//

#include "libcso/io/cso_file_c.h"
#include "libcso/cso_error.h"

CSO_PUB_API_OPEN
void cso_file_initializer(cso_file_c obj, const char* path)
{
    if (!obj) return;


    obj->opened = 0;
    obj->open_attributes = NULL;
    obj->rawFile = NULL;
    obj->path = cso_string_new(path);

    cso_get_obj_metadata(obj->path).moveable = 0;
    cso_get_obj_metadata(obj->open_attributes).moveable = 0;
}

CSO_PUB_API_OPEN
void cso_file_uninitializer(cso_file_c obj)
{
    if (!obj) return;
    if (obj->opened) fclose(obj->rawFile);
    cso_string_destroy(obj->path);
    cso_string_destroy(obj->open_attributes);
}

CSO_PUB_API_OPEN
cso_file_c cso_file_new(const char* path)
{
    cso_file_c self = cso_plat_malloc(sizeof(cso_file_t));
    if (!self) return NULL;
    memset(self, 0, sizeof(cso_file_t));
    cso_object_initializer(cso_super_cast(cso_object_c, self), cso_toTypeNameStr(cso_file_c), sizeof(cso_file_t));
    cso_file_initializer(self, path);


    return self;
}

void cso_file_destroy(cso_file_c self)
{
    if (!self) return;
    if (cso_get_obj_metadata(self).ghost) return;
    cso_file_uninitializer(self);
    cso_object_uninitializer(cso_super_cast(cso_object_c, self));
    cso_plat_free(self);
}
