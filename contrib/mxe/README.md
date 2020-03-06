Cross-compilation for Win32 on Linux with MXE


Execute the following commands:

cd /opt

git clone https://github.com/mxe/mxe.git

cd mxe

make MXE_TARGETS="i686-w64-mingw32.static" boost

make MXE_TARGETS="i686-w64-mingw32.static" qttools

make MXE_TARGETS="i686-w64-mingw32.static" miniupnpc


Download Berkeley DB (not supported by MXE) inside /opt, move compile-db.sh inside its folder, make it an executable and execute it.

When finished, download vDinar and move compile-vdn.sh inside its folder, make it an executable and execute it.


When finished, execute the following command to make the installer:

makensis ../share/setup.nsi

And copy share/vdinar-*-win32-setup.exe to your desired folder.
