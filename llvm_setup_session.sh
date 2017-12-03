#!/bin/bash

# See: https://llvm.org/docs/GettingStarted.html
# Download this script onto your home directory, ie. whatever is $HOME for you.


# outputs all the commands run to stdout
#set -x

LLVM_DIR=compiler_session_llvm

ABS_PATH=$(pwd)

echo "LLVM will be built in $ABS_PATH/$LLVM_DIR/llvm/_build"
echo "LLVM will be installed in $ABS_PATH/$LLVM_DIR"

mkdir $LLVM_DIR && cd $LLVM_DIR

echo "Downloading the llvm source..."
svn co http://llvm.org/svn/llvm-project/llvm/trunk llvm

# Downloading the clang source and adding it to the right directory
cd llvm/tools
echo "Downloading the clang source..."
svn co http://llvm.org/svn/llvm-project/cfe/trunk clang

cd ../
mkdir _build && cd _build

echo "Generating Makefiles for llvm..."
cmake -G "Unix Makefiles" -DLLVM_TARGETS_TO_BUILD="X86" -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=$ABS_PATH/$LLVM_DIR ../

echo "Building llvm..."
# The `-j2` flag builds the project parallely across 2 cores
make -j2

echo "Installing llvm..."
make install
