#!/usr/bin/env bash
# Run this from the root of this project.
URL_GTEST="https://github.com/google/googletest/archive/refs/tags/release-1.10.0.tar.gz"
URL_BOOST="https://dl.bintray.com/boostorg/release/1.75.0/source/boost_1_75_0.tar.gz"
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
    # build_sdl20

    cd $TOP
}
entry
