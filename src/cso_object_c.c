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

#include "libcso/cso_instanceof.h"

#include <string.h>

CSO_PUB_API_OPEN
void cso_object_initializer(cso_object_c obj, cso_thin_rtti_class_id_t class_type_name, size_t class_type_size)
{
    if (!obj) return;
    if (!class_type_name)
    {
        obj->class_type_str = cso_toTypeNameStr(cso_object_c);
    }
    obj->class_type_str = class_type_name;
    obj->class_size = class_type_size;
    cso_thin_rtti_metadata_t* obj_meta_data = &obj->class_meta_data;
    obj_meta_data->ghost = 0;
    obj_meta_data->copyable = 1;
    obj_meta_data->moveable = 1;
    obj_meta_data->readOnly = 0;
}

CSO_PUB_API_OPEN
cso_thin_rtti_class_id_t cso_object_getClassTypeStr(cso_object_c self)
{
    if (!self) return NULL;

    return self->class_type_str;
}

CSO_PUB_API_OPEN
cso_object_c cso_object_ghost_copy(cso_object_c self)
{
    if (!self) return NULL;
    cso_object_c new_self = cso_plat_malloc(self->class_size);
    if (!new_self) return NULL;

    memcpy(new_self, self, self->class_size);
    cso_get_obj_metadata(new_self).ghost = 1;
    cso_get_obj_metadata(new_self).moveable = 0;
    cso_get_obj_metadata(new_self).copyable = 0;

    return new_self;
}

cso_flag cso_object_isReadOnly(cso_object_c self)
{
    if (!self) return 0;
    return self->class_meta_data.readOnly;
}

cso_flag cso_object_isGhost(cso_object_c self)
{
    if (!self) return 0;
    return self->class_meta_data.ghost;
}

cso_flag cso_object_isCopyable(cso_object_c self)
{
    if (!self) return 0;
    return self->class_meta_data.copyable;
}

cso_flag cso_object_isMoveable(cso_object_c self)
{
    if (!self) return 0;
    return self->class_meta_data.moveable;
}


CSO_PUB_API_OPEN
void cso_object_uninitializer(cso_object_c obj){}

CSO_PUB_API_OPEN
cso_object_c __cso_safe_ghost_copy_impl__(cso_object_c from, cso_thin_rtti_class_id_t class_id)
{
    if (!__cso_instanceof_impl__(from, class_id)) return NULL;
    return cso_object_ghost_copy(from);
}


