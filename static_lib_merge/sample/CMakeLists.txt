cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME "sample")
project(${PROJECT_NAME}) 

set(SOURCE_FILES
	main.cpp
)

add_executable(${PROJECT_NAME}_direct ${SOURCE_FILES})	   
target_link_libraries(${PROJECT_NAME}_direct PRIVATE main_lib)

add_executable(${PROJECT_NAME}_indirect ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME}_indirect PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../install/include)
target_link_libraries(${PROJECT_NAME}_indirect PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../install/lib/main_lib_comp.lib)
