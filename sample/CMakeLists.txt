cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME "sample")
project(${PROJECT_NAME}) 

set(SOURCE_FILES
	main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
												   
target_link_libraries(${PROJECT_NAME} PRIVATE static_lib_a)

