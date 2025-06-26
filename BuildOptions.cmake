#
# Copyright (C) 2024  Tetex7
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.
#

execute_process(
        COMMAND ${CMAKE_C_COMPILER} -dumpmachine
        OUTPUT_VARIABLE PLATFORM_TRIPLE
        OUTPUT_STRIP_TRAILING_WHITESPACE
)

set(CMAKE_OBJCOPY "${PLATFORM_TRIPLE}-objcopy" CACHE STRING "Compiler's object copy")

if(NOT WIN32)
    option(CSO_CONFIG_STATIC_ONLY "If to produce a static only library" OFF)
else ()
    option(CSO_CONFIG_STATIC_ONLY "If to produce a static only library" ON)
endif ()

# Debug flag control
option(CSO_CONFIG_DEBUG "Enable debug mode" OFF)

option(CSO_CONFIG_USE_LIB_SAFENET "" OFF)
option(CSO_NO_STD_BOOL "" OFF)

option(CSO_CONFIG_THREAD_AWARE "Determine if the program should be built with thread awareness" ON)

set(CSO_CONFIG_STR_VERSION "0.0.0" CACHE STRING "Set the version being compiled")
set(CSO_CONFIG_VERSION_MAJOR 0 CACHE STRING "Set the major version being compiled")
set(CSO_CONFIG_VERSION_MINOR 0 CACHE STRING "Set the minor version being compiled")
set(CSO_CONFIG_VERSION_PATCH 0 CACHE STRING "Set the patch version being compiled")

option(CSO_CONFIG_ENABLE_MUTEX "Use thread safety mechanisms" ON)
