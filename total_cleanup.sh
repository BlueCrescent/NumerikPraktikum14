#!/bin/sh

cd Release
make clean
cd ..

cd GTest
make clean
cd ..

cd Debug
make clean
cd ..

rm -r Output
