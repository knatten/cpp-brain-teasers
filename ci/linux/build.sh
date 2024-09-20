#!/bin/bash

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
source $SCRIPT_DIR/common.sh || exit $?

if [ $# != 3 ]; then
  echo "USAGE: $0 <Debug|Release> compiler <ninja|make>"
  exit 1
fi

CONFIG=$1
COMPILER=$2
GENERATOR=$3
if [ "$GENERATOR" == "make" ]; then
    GENERATOR_ARG="Unix Makefiles"
elif [ "$GENERATOR" == "ninja" ]; then
    GENERATOR_ARG="Ninja"
else
    echo "Unknown generator $GENERATOR"
    exit 1
fi

COMPILER_DIR=$(echo $COMPILER | sed 's/+/plus/g')
BUILD_DIR=$ROOT_DIR/build/ci/$OS/$CONFIG/$GENERATOR/$COMPILER_DIR
echo "Building and testing in '$BUILD_DIR' with COMPILER $COMPILER and CMAKE_BUILD_TYPE '$CONFIG'"
mkdir -p $BUILD_DIR || exit $?
cd $BUILD_DIR || exit $?
cmake --version || exit $?
cmake -Wdev -Wdeprecated --warn-uninitialized --warn-unused-vars -S $SRC_DIR -G"$GENERATOR_ARG" -B $BUILD_DIR -DCMAKE_BUILD_TYPE=$CONFIG -DCMAKE_CXX_COMPILER=$COMPILER || exit $?
cmake --build $BUILD_DIR --parallel || exit $?
ctest --verbose || exit $?
