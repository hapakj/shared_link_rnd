cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME "main")
project(${PROJECT_NAME})

set(SOURCE_FILES
	main_lib.h
	main_lib.cpp
)

add_library(${PROJECT_NAME}_lib STATIC ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME}_lib PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(${PROJECT_NAME}_lib PUBLIC sub_lib_a
                                                 sub_lib_b)
											
install (FILES "main_lib.h" DESTINATION include)


function(merge_static_lib_with_deps out_target in_target)
    set(TEMP_SRC_DIR "${PROJECT_BINARY_DIR}/${in_target}_merge_src_temp")
    set(TEMP_LIB_DIR "${PROJECT_BINARY_DIR}/${in_target}_merge_lib_temp")
    
    file(WRITE ${TEMP_SRC_DIR}/dummy.cpp "")

    add_library(${out_target} STATIC ${TEMP_SRC_DIR}/dummy.cpp)
    
    get_target_property(linked_libs ${in_target} LINK_LIBRARIES)
    list(REMOVE_DUPLICATES linked_libs)
    
    list(APPEND commands COMMAND echo collect dependent libs)
    
    ## clear previous libs
    list(APPEND commands COMMAND ${CMAKE_COMMAND} -E remove_directory ${TEMP_LIB_DIR})
    list(APPEND commands COMMAND ${CMAKE_COMMAND} -E make_directory ${TEMP_LIB_DIR})
    
    ## copy in_target
    list(APPEND commands COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${in_target}> ${TEMP_LIB_DIR})
    
    ## copy other libs
    foreach(lib ${linked_libs})
        list(APPEND commands COMMAND echo "\t"$<TARGET_FILE:${lib}>)
        list(APPEND commands COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${lib}> ${TEMP_LIB_DIR})
    endforeach()
    
    list(APPEND commands COMMAND echo done)
    
    add_custom_command(TARGET ${out_target} PRE_BUILD ${commands})
    
    foreach(CONFIG_TYPE ${CMAKE_CONFIGURATION_TYPES})
        string(TOUPPER ${CONFIG_TYPE} CONFIG_TYPE)
        set_target_properties(${out_target} PROPERTIES STATIC_LIBRARY_FLAGS_${CONFIG_TYPE} "${TEMP_LIB_DIR}/*.lib")
    endforeach()
endfunction()


merge_static_lib_with_deps(${PROJECT_NAME}_lib_comp ${PROJECT_NAME}_lib)

install(TARGETS ${PROJECT_NAME}_lib_comp DESTINATION lib)

