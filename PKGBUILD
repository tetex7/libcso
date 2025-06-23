#
# Copyright (C) 2025  Tetex7
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

# Maintainer: tete <tetex7@outlook.com>
pkgname=libcso
pkgver=1.0.0
pkgrel=1
pkgdesc='Passive garbage collector for C and C++'
url='www.github.com/tetex7/libsafetynet'
provides=()
arch=('x86_64')
#PACKAGER="${USER}"
license=('GPL3')
makedepends=('gcc' 'binutils' 'valgrind')
depends=('glibc')
options=('!strip' 'docs' 'libtool' '!staticlibs' 'emptydirs' 'zipman' '!purge' '!debug' '!lto')

if [ -z "${PK_DEBUG}" ]; then
    PK_DEBUG=0
fi

minverN=${pkgver%%.*}        # major version before first dot
eminverN=$(echo $pkgver | cut -d '.' -f1,2)  # major.minor


prepare() {
cd ..
echo $PWD
./dev_setup.sh clean
./dev_setup.sh \
    -DCSO_CONFIG_STR_VERSION=${pkgver} \
    -DCSO_CONFIG_VERSION_MAJOR=${minverN}
}

build () {
    cd ..
    
    if [[ -f ./Makefile ]]; then
        make -j $(nproc)
    elif [[ -f ./build.ninja ]]; then
        ninja
    fi

    if [[ "${PK_NO_TEST}" != "1"  ]]; then
        #./test.sh
        #if [ ${?} == 0 ]; then
        ##    echo "Test passed no memory leaks"
        #elif [ ${?} == 44 ]; then
        #    echo "Test Compilation error"
        #    exit ${?}
        #else
        #    echo "Memory error detected: see valgrind_output.log"
        #    exit 1
        #fi

        if [[ -z "${PK_DEBUG}" || "${PK_DEBUG}" == "0" ]]; then
            echo "striping debug syms"
            strip -v --strip-debug -o ./build/${pkgname}.so ./build/${pkgname}.so
        fi
    fi
}

package() {
    cd ..
    install -Dm644 ./build/${pkgname}.so "${pkgdir}/usr/lib/${pkgname}.so.${pkgver}"

    mkdir -p ${pkgdir}/usr/include
    cp -rv "./include/${pkgname}" "${pkgdir}/usr/include/${pkgname}"


#    for i in $(ls ./manpages); do
#        install -Dm644 "./manpages/$i" "${pkgdir}/usr/man/man3/${i}"
#    done

    ln -s "/usr/lib/${pkgname}.so.${pkgver}" "${pkgdir}/usr/lib/${pkgname}.so"
    ln -s "/usr/lib/${pkgname}.so.${pkgver}" "${pkgdir}/usr/lib/${pkgname}.so.${minverN}"
    ln -s "/usr/lib/${pkgname}.so.${pkgver}" "${pkgdir}/usr/lib/${pkgname}.so.${eminverN}"
    mkdir -p "${pkgdir}/usr/lib/pkgconfig"
    cat >> "${pkgdir}/usr/lib/pkgconfig/${pkgname}.pc" <<_ACEOF
prefix=/usr
exec_prefix=\${prefix}
libdir=\${exec_prefix}/lib
includedir=\${prefix}/include

Name: ${pkgname}
Description: ${pkgdesc}
Version: ${pkgver}
Libs: -l${pkgname##lib}
_ACEOF

}
