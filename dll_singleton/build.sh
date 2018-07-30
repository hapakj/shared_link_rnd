#!/bin/bash

: ${PLATFORM?"not set"}
: ${CONFIG?"not set"}
: ${LIB_TYPE?"not set"}
: ${INLINED?"not set"}


function create_and_go_to_out_dir {
	mkdir -p $1
	cd $1

	if [ $? -ne 0 ] ; then
		echo "unable to create output directory."
		exit 1
	fi
}


case $PLATFORM in
	vs2015-x64)
		create_and_go_to_out_dir out_"$PLATFORM"_"$LIB_TYPE"_"$INLINED"
		
		cmake -G"Visual Studio 14 Win64" -DLIB_TYPE=$LIB_TYPE -DINLINED=$INLINED -DCMAKE_INSTALL_PREFIX=../install ../ 
		cmake --build . --config $CONFIG
    ;;
	linux-gcc)
		create_and_go_to_out_dir out_"$PLATFORM"_"$CONFIG"_"$LIB_TYPE"_"$INLINED"

		export CC=/usr/bin/gcc
		export CXX=/usr/bin/g++		
		
		cmake -DCMAKE_BUILD_TYPE=$CONFIG -DLIB_TYPE=$LIB_TYPE -DINLINED=$INLINED -DCMAKE_INSTALL_PREFIX=../install ../
		cmake --build .
    ;;
	linux-clang)
		create_and_go_to_out_dir out_"$PLATFORM"_"$CONFIG"_"$LIB_TYPE"_"$INLINED"

		export CC=/usr/bin/clang-5.0
		export CXX=/usr/bin/clang++-5.0
		
		cmake -DCMAKE_BUILD_TYPE=$CONFIG -DLIB_TYPE=$LIB_TYPE -DINLINED=$INLINED -DCMAKE_INSTALL_PREFIX=../install ../
		cmake --build .
    ;;
    *)
        echo "Unknown/unsupported platform: $PLATFORM"
        exit 1
    ;;
esac

