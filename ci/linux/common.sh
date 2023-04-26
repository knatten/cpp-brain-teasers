#!/bin/bash

if [[ "$OSTYPE" == "linux-gnu"* ]]; then
        OS=linux
elif [[ "$OSTYPE" == "darwin"* ]]; then
        OS=mac
else
  echo "Unknown OS $OSTYPE"
  exit 1
fi

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
ROOT_DIR=$SCRIPT_DIR/../..
SRC_DIR=$ROOT_DIR/src
CI_DIR=$ROOT_DIR/ci