#!/bin/bash

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
source $SCRIPT_DIR/common.sh || exit $?

if [ $# != 2 ]; then
  echo "USAGE: $0 <Debug|Release> compiler"
  exit 1
fi

CONFIG=$1
COMPILER=$2


COMPILER_DIR=$(echo $COMPILER | sed 's/+/plus/g')
BUILD_DIR=$ROOT_DIR/build/ci/$OS/$CONFIG/$COMPILER_DIR
echo "Building and testing in '$BUILD_DIR' with COMPILER $COMPILER and CMAKE_BUILD_TYPE '$CONFIG'"
mkdir -p $BUILD_DIR || exit $?
cd $BUILD_DIR || exit $?
cmake --version || exit $?
cmake -Wdev  -Wdeprecated --warn-uninitialized --warn-unused-vars -S $SRC_DIR -GNinja -B $BUILD_DIR -DCMAKE_BUILD_TYPE=$CONFIG -DCMAKE_CXX_COMPILER=$COMPILER || exit $?
cmake --build $BUILD_DIR || exit $?
ctest --verbose || exit $?
