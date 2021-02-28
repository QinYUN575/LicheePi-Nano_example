if [ ! -n "$CC" ]; then
    export CC=$(pwd)/../../output/host/bin/arm-linux-gcc
    # echo $CC
fi

if [ ! -d "build" ]; then
    mkdir build
else
    rm -rf build
    mkdir build
fi
cd build

cmake .. -D CMAKE_C_COMPILER=$(CC)
make
