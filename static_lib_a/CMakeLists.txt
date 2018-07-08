cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME "static_lib_a")
project(${PROJECT_NAME})

set(SOURCE_FILES
	static_a.h
	static_a.cpp
)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})

