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
#ifndef OBJECT_C_H
#define OBJECT_C_H
#include <libcso/csodefs.h>

CSO_CPP_COMPAT_START

typedef struct cso_object_s
{
    cso_thin_rtti_class_id_t class_type_str;
} cso_object_t;

/**
 * @brief This is the base class to which this library is built upon
 * @note Hold the thin pseudo RTTI data
 */
typedef cso_object_t* cso_object_c;

CSO_PUB_API_OPEN
void cso_object_initializer(cso_object_c obj, cso_thin_rtti_class_id_t class_type_name);

CSO_PUB_API_OPEN
cso_thin_rtti_class_id_t cso_object_getClassTypeStr(cso_object_c self);

CSO_PUB_API_OPEN
void cso_object_uninitializer(cso_object_c obj);

#define cso_typeid(obj) cso_object_getClassTypeStr(cso_super_cast(cso_object_c, obj))

CSO_CPP_COMPAT_END

#endif //OBJECT_C_H
