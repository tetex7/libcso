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
// Created by tete on 06/30/2025.
//
#pragma once

#ifndef CSOTYPES_H
#define CSOTYPES_H
#include <stdint.h>
#include <stddef.h>
#include <libcso/csoattrs.h>
#include <libcso/cso_cpp_compat.h>
#include <libcso/csobool.h>

CSO_CPP_COMPAT_START

typedef const char* cso_thin_rtti_class_id_t;
typedef const char* cso_c_char_string_t;

typedef int8_t cso_sbyte;
typedef uint8_t cso_byte;

typedef int16_t cso_sword;
typedef uint16_t cso_word;

typedef int32_t cso_sdword;
typedef uint32_t cso_dword;

typedef int64_t cso_sqword;
typedef uint64_t cso_qword;

typedef int8_t cso_s8;
typedef uint8_t cso_u8;

typedef int16_t cso_s16;
typedef uint16_t cso_u16;

typedef int32_t cso_s32;
typedef uint32_t cso_u32;

typedef int64_t cso_s64;
typedef uint64_t cso_u64;

typedef size_t     cso_usize;
typedef ptrdiff_t  cso_ssize;

typedef cso_usize cso_index_t;
typedef cso_usize cso_capacity_t;
typedef cso_usize cso_offset_t;

typedef uintptr_t cso_address_t;
typedef intptr_t cso_saddress_t;

typedef volatile uintptr_t cso_vaddress_t;
typedef volatile intptr_t  cso_vsaddress_t;

typedef uint8_t  cso_bit8;   // single bits or bitfields
typedef uint16_t cso_bit16;
typedef uint32_t cso_bit32;
typedef uint64_t cso_bit64;

typedef void* cso_objptr_t;
typedef const void* cso_cobjptr_t;

typedef union CSO_NO_IMPLICIT_PADDING cso_qword_segmented_view_u
{
    struct CSO_NO_IMPLICIT_PADDING
    {
        cso_byte   b8;
        cso_word   w16;
        cso_dword  dw32;
        cso_qword  qw64;
    } segments;
    cso_byte full_byte_view[sizeof(cso_qword)];
    cso_qword full_qword;
} cso_qword_segmented_view_t;

CSO_CPP_COMPAT_END

#endif //CSOTYPES_H
