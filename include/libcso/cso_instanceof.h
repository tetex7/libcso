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

#ifndef CSO_INSTANCEOF_H
#define CSO_INSTANCEOF_H
#include <libcso/csodefs.h>
#include <libcso/cso_object_c.h>

CSO_CPP_COMPAT_START

CSO_PUB_API_OPEN
cso_bool __cso_instanceof_impl__(cso_object_c inst, cso_thin_rtti_class_id_t type_name);

/**
 * @brief Checks if an object instance matches a specific class type.
 * @param inst A valid object instance (must not be NULL).
 * @param type The class type to check against (use the *_c type).
 * @note This only compares the declared type of the object.
 *       It does NOT account for inheritance or parent types.
 */
#define cso_instanceof(inst, type) (__cso_instanceof_impl__(cso_super_cast(cso_object_c, inst), cso_toTypeNameStr(type)))

CSO_CPP_COMPAT_END

#endif //CSO_INSTANCEOF_H
