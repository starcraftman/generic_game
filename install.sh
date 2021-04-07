#!/usr/bin/env bash
# Run this from the root of this project.
URL_GTEST="https://github.com/google/googletest/archive/refs/tags/release-1.10.0.tar.gz"
URL_BOOST="https://dl.bintray.com/boostorg/release/1.75.0/source/boost_1_75_0.tar.gz"
URL_SDL12="https://github.com/libsdl-org/SDL-1.2/archive/refs/tags/release-1.2.15.tar.gz"
URL_SDL20="https://www.libsdl.org/release/SDL2-2.0.14.tar.gz"
TOP=$(pwd)
DEPS_FOLDER="$(realpath ./deps)"

build_google_test() {
    local arc
    local folder
    arc="$(basename $URL_GTEST)"
    folder="googletest-${arc%.tar.gz}"

    wget $URL_GTEST
    tar -xvf "$arc"
    cd "$folder"

    mkdir build
    cd build
    cmake ..
    make

    cd ..
    cp ./build/lib/*.a "$DEPS_FOLDER/lib"
    cp -r ./googletest/include/gtest/ ./googlemock/include/gmock/ "$DEPS_FOLDER/include"

    cd $DEPS_FOLDER
    command rm -rf "$arc" "$folder"
}

build_boost() {
    local arc
    local folder
    arc="$(basename $URL_BOOST)"
    folder="${arc%.tar.gz}"

    wget $URL_BOOST
    tar -xvf "$arc"
    cd "$folder"

    ./bootstrap.sh
    ./b2 --prefix="$DEPS_FOLDER" -a install

    cd $DEPS_FOLDER
    command rm -rf "$arc" "$folder"
}

build_sdl12() {
    local arc
    local folder
    arc="$(basename $URL_SDL12)"
    folder="SDL-1.2-${arc%.tar.gz}"

    wget $URL_SDL12
    tar -xvf "$arc"
    cd "$folder"

    # patch needed
    local patch_str
    patch_str="
diff -ur ../SDL-1.2-release-1.2.15/src/video/x11/SDL_x11sym.h ./src/video/x11/SDL_x11sym.h
--- ../SDL-1.2-release-1.2.15/src/video/x11/SDL_x11sym.h	2012-01-20 19:49:48.000000000 -0500
+++ ./src/video/x11/SDL_x11sym.h	2021-04-07 07:22:57.195918036 -0400
@@ -163,11 +163,11 @@
  * Not required...these only exist in code in headers on some 64-bit platforms,
  *  and are removed via macros elsewhere, so it's safe for them to be missing.
  */
-#ifdef LONG64
-SDL_X11_MODULE(IO_32BIT)
-SDL_X11_SYM(int,_XData32,(Display *dpy,register long *data,unsigned len),(dpy,data,len),return)
-SDL_X11_SYM(void,_XRead32,(Display *dpy,register long *data,long len),(dpy,data,len),)
-#endif
+// #ifdef LONG64
+// SDL_X11_MODULE(IO_32BIT)
+// SDL_X11_SYM(int,_XData32,(Display *dpy,register long *data,unsigned len),(dpy,data,len),return)
+// SDL_X11_SYM(void,_XRead32,(Display *dpy,register long *data,long len),(dpy,data,len),)
+// #endif

 /*
  * libX11 1.4.99.1 added _XGetRequest, and macros use it behind the scenes.
"
    echo "$patch_str" | patch -p0

    ./autogen.sh
    ./configure --prefix="$DEPS_FOLDER"
    make install

    cd $DEPS_FOLDER
    command rm -rf "$arc" "$folder"
}

build_sdl20() {
    local arc
    local folder
    arc="$(basename $URL_SDL20)"
    folder="${arc%.tar.gz}"

    wget $URL_SDL20
    tar -xvf "$arc"
    cd "$folder"

    ./configure --prefix="$DEPS_FOLDER"
    make install

    cd $DEPS_FOLDER
    command rm -rf "$arc" "$folder"
}

entry() {
    mkdir -p "$DEPS_FOLDER/lib" "$DEPS_FOLDER/include"
    cd "$DEPS_FOLDER"

    build_google_test
    build_boost
    # build_sdl12
    # build_sdl20

    cd $TOP
}
entry
