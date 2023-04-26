#!/bin/bash

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
source $SCRIPT_DIR/common.sh || exit $?

BUILD_DIR=$ROOT_DIR/build/ci/$OS/clang-tidy
echo "Building in '$BUILD_DIR'"
mkdir -p $BUILD_DIR || exit $?
cd $BUILD_DIR || exit $?
cmake -S $SRC_DIR -GNinja -B $BUILD_DIR -DCMAKE_BUILD_TYPE=$CONFIG -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_CXX_CLANG_TIDY="clang-tidy;-checks=*" || exit $?
cmake --build $BUILD_DIR || exit $?
echo "Done building"