Copyright (c) 2009-2013 Bitcoin Developers
Copyright (c) 2018-2020 vDinar Developers
Distributed under the MIT/X11 software license, see the accompanying
file COPYING or http://www.opensource.org/licenses/mit-license.php.
This product includes software developed by the OpenSSL Project for use in the [OpenSSL Toolkit](http://www.openssl.org/). This product includes
cryptographic software written by Eric Young ([eay@cryptsoft.com](mailto:eay@cryptsoft.com)), and UPnP software written by Thomas Bernard.

See readme-qt.rst for instructions on building vDinar-Qt, the
graphical user interface.

WINDOWS BUILD NOTES
===================

Compilers Supported
-------------------
TODO: What works?
Note: releases are cross-compiled using mingw running on Linux.


Dependencies
------------
Libraries you need to download separately and build:

                default path               download
OpenSSL         \openssl-1.1.1             http://www.openssl.org/source/
Berkeley DB     \db-18.1.32                https://www.oracle.com/database/technologies/related/berkeleydb-downloads.html
Boost           \boost-1.50.0              http://www.boost.org/users/download/
miniupnpc       \miniupnpc-2.1.20191224    http://miniupnp.tuxfamily.org/files/

Their licenses:

	OpenSSL        Old BSD license with the problematic advertising requirement
	Berkeley DB    New BSD license with additional requirement that linked software must be free open source
	Boost          MIT-like license
	miniupnpc      New (3-clause) BSD license

Versions used in this release:

	OpenSSL      1.1.1
	Berkeley DB  18.1.32
	Boost        1.50.0
	miniupnpc    2.1.20191224


OpenSSL
-------
MSYS shell:

un-tar sources with MSYS 'tar xfz' to avoid issue with symlinks (OpenSSL ticket 2377)
change 'MAKE' env. variable from 'C:\MinGW32\bin\mingw32-make.exe' to '/c/MinGW32/bin/mingw32-make.exe'

	cd /c/openssl-1.1.1
	./config
	make

Berkeley DB
-----------
MSYS shell:

	cd /c/db-18.1.32/build_unix
	sh ../dist/configure --enable-mingw --enable-cxx
	make

Boost
-----
MSYS shell:

	downloaded boost jam 3.1.18
	cd \boost-1.50.0
	bjam toolset=gcc --build-type=complete stage

MiniUPnPc
---------
UPnP support is optional, make with `USE_UPNP=` to disable it.

MSYS shell:

	cd /c/miniupnpc-2.1.20191224
	make -f Makefile.mingw
	mkdir miniupnpc
	cp *.h miniupnpc/

vDinar
-------
MSYS shell:

	cd \vDinar\src
	mingw32-make -f makefile.mingw
	strip vdinard.exe
