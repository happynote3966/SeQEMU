#!/bin/sh

mkdir build_i386_linux_user
cd build_i386_linux_user

../qemu/configure --target-list=i386-linux-user --enable-debug-info --enable-debug --enable-debug-tcg

make -j2


cp -R ../resources ./
