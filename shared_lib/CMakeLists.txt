cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME "shared_lib")
project(${PROJECT_NAME})

set(SOURCE_FILES
	shared.h
	shared.cpp
)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(${PROJECT_NAME} PUBLIC static_lib_a
                                             static_lib_b)

