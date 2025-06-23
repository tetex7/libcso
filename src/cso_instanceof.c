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

#include "libcso/cso_instanceof.h"
#include <string.h>

CSO_PUB_API_OPEN
cso_bool __cso_instanceof_impl__(cso_object_c inst, const char* type_name)
{
    const char* inst_type = cso_object_getClassTypeStr(inst);
    size_t inst_name_len = strlen(inst_type);
    if (inst_name_len != strlen(type_name)) return false;
    return !strncmp(inst_type, type_name, inst_name_len);
}
