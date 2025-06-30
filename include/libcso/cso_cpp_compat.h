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

/**
 * Simple compatibility macros for C++
 */


#ifndef CSO_CPP_COMPAT_H
#define CSO_CPP_COMPAT_H

#ifdef __cplusplus
#define CSO_CPP_COMPAT_START extern "C" {
#define CSO_CPP_COMPAT_END }
#define CSO_CPP_COMPAT_MODE __cplusplus
#else
#define CSO_CPP_COMPAT_START
#define CSO_CPP_COMPAT_END
#endif

#endif //CSO_CPP_COMPAT_H
