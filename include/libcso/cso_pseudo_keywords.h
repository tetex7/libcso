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

#ifndef CSO_PSEUDO_KEYWORDS_H
#define CSO_PSEUDO_KEYWORDS_H
#include <libcso/csotypes.h>
#include <libcso/csoattrs.h>
#include <libcso/csobool.h>
#include <libcso/cso_cpp_compat.h>

/**
 * @brief Turns a class type name into a string for the thin pseudo rtti system
 * @param type The class type to check against (use the *_c type).
 * @note Use the new cso_thin_rtti_id_of(...) Macro instead of this
 */
#define cso_toTypeNameStr(type) #type

/**
 * @brief A blind cast to an object type within the inheritance chain
 * @param type The class type to check against (use the *_c type).
 * @param obj A valid object instance (must not be NULL).
 * @note This does not verify the cast at runtime—use only when you're sure of the object's type.
 *       Unless you can determine it with cso_instanceof
 */
#define cso_super_cast(type, obj) ((type)obj)

/**
 * @brief Simple helper macro for setting up inheritance in a class
 * @param type The class type to check against (use the *_t type).
 */
#define cso_class_extends(type) type super

/**
 * @brief Gives you the address of a value in a cso_address_t
 * @param val A valid variable in memory
 */
#define cso_addressof(val) ((cso_address_t)&val)

#ifdef offsetof
#   define cso_offsetof(type, member) offsetof(type, member)
#else
#   warning "Compiler appears to not support offsetof Defaulting to stub"
#   define cso_offsetof(type, member)
#endif

/**
 * @brief Turns a class type name into a string for the thin pseudo rtti system
 * @param type The class type to check against (use the *_c type).
 */
#define cso_thin_rtti_id_of(type) ((cso_thin_rtti_class_id_t)cso_toTypeNameStr(type))

/**
 * @brief Gives you a live segmented view of If the value passed in
 * @param val A value that backs the live view preferably a 64 bit integer
 */
#define cso_live_qw_segmented_view_of(val) ((cso_qword_segmented_view_t*)&val)

#define CSO_UNUSED(x) ((void)(x))

#define cso_unused(x) CSO_UNUSED(x)

#endif //CSO_PSEUDO_KEYWORDS_H
