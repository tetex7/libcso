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

#pragma once
#ifndef CSO_DNY_VTABLE_H
#define CSO_DNY_VTABLE_H
#include <libcso/csodefs.h>

CSO_CPP_COMPAT_START

typedef struct cso_dny_vtable_tuple_s
{
    cso_thin_rtti_class_id_t rclass;
    const char* function_name;
    void* function_ptr;
} cso_dny_vtable_tuple_t;

typedef struct cso_dny_vtable_s
{
    cso_dny_vtable_tuple_t* vtable;
    size_t length;
} cso_dny_vtable_t;


CSO_CPP_COMPAT_END
#endif