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

#ifndef CSO_FILE_C_H
#define CSO_FILE_C_H
#include <libcso/csodefs.h>
#include <libcso/cso_object_c.h>
#include <libcso/cso_string_c.h>
#include <stdio.h>

CSO_CPP_COMPAT_START

typedef struct cso_file_s
{
    cso_class_extends(cso_object_t);
    FILE* rawFile;
    cso_string_c path;
    cso_string_c open_attributes;
    cso_flag opened;
    size_t file_size;
} cso_file_t;

typedef cso_file_t* cso_file_c;

CSO_PUB_API_OPEN
void cso_file_initializer(cso_file_c obj, const char* path);

CSO_PUB_API_OPEN
void cso_file_uninitializer(cso_file_c obj);

CSO_PUB_API_OPEN
cso_file_c cso_file_new(const char* path);

CSO_PUB_API_OPEN
void cso_file_destroy(cso_file_c self);

CSO_PUB_API_OPEN
cso_bool cso_file_exists(cso_file_c self);

CSO_PUB_API_OPEN
cso_flag cso_file_open(cso_file_c self, const char* attributes);

CSO_PUB_API_OPEN
cso_flag cso_file_close(cso_file_c self);

CSO_PUB_API_OPEN
cso_bool cso_file_isOpen(cso_file_c self);

CSO_PUB_API_OPEN
cso_bool cso_file_isReadOnly(cso_file_c self);

CSO_PUB_API_OPEN
FILE* cso_file_getRawFilePtr(cso_file_c self);

CSO_CPP_COMPAT_END
#endif
