#!/bin/bash
MXE_PATH=/opt/mxe
sed -i "s/WinIoCtl.h/winioctl.h/g" src/dbinc/win_db.h
mkdir build_mxe
cd build_mxe

CC=$MXE_PATH/usr/bin/i686-w64-mingw32.static-gcc \
CXX=$MXE_PATH/usr/bin/i686-w64-mingw32.static-g++ \
../dist/configure \
	--disable-replication \
	--enable-mingw \
	--enable-cxx \
        --with-mutex=x86/gcc-assembly \
	--host x86 \
	--prefix=$MXE_PATH/usr/i686-w64-mingw32.static

make

make install
