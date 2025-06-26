#!/usr/bin/env bash

#
# Copyright (C) 2025  tete
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

if [ -e "/usr/bin/pacman" ] ; then
    echo "no pac-man installed please use arch"
    exit 1
fi

if [ -e "/usr/bin/doas" ] ; then
    DOAS=doas
else
    DOAS=sudo
fi
PKG_NAME="libcso"

rm -vf ./${PKG_NAME}-*-1-x86_64.pkg.tar.zst

yes | ${DOAS} pacman -R ${PKG_NAME}
makepkg -f
yes | ${DOAS} pacman -U ./${PKG_NAME}-*-1-x86_64.pkg.tar.zst
rm -vf ./${PKG_NAME}-*-1-x86_64.pkg.tar.zst