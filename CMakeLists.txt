cmake_minimum_required(VERSION 3.21.2)

project(VectorMath)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set( DEPS_DIR ${CMAKE_SOURCE_DIR}/external)

list(APPEND SDL2_PATH "${DEPS_DIR}/SDL2/")
list(APPEND SDL2_IMAGE_PATH "${DEPS_DIR}/SDL2_image/")
list(APPEND SDL2_TTF_PATH "${DEPS_DIR}/SDL2_ttf/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

file(GLOB LL_SOURCE_FILES src/*.cpp)
file(GLOB LL_HEADER_FILES include/*.h)

add_executable(VectorMath ${LL_SOURCE_FILES} ${LL_HEADER_FILES})

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT VectorMath)

target_include_directories(VectorMath PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR})

target_link_libraries(VectorMath PRIVATE ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY})

add_custom_command(TARGET VectorMath POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
                    "${DEPS_DIR}/SDL2/lib/x64/"
                    "${DEPS_DIR}/SDL2_image/lib/x64/"
                    "${DEPS_DIR}/SDL2_ttf/lib/x64/"
                    $<TARGET_FILE_DIR:VectorMath>)

add_custom_command(TARGET VectorMath POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:VectorMath>/res)