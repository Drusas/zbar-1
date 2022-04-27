cmake_minimum_required(VERSION 3.23)

project(scan-image C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "--data-sections")

add_executable (${PROJECT_NAME} "")

target_include_directories(scan-image
	PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/../external/stb
    ${CMAKE_CURRENT_LIST_DIR}/../zbar
    ${CMAKE_CURRENT_LIST_DIR}/../include
)

target_sources(${PROJECT_NAME}
  PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/scan_image.cpp
)

# find_library(LIBZBAR zbar
#     PATHS ${CMAKE_CURRENT_LIST_DIR}/../zbar/
# )

# set(LIBZBAR ${CMAKE_CURRENT_LIST_DIR}/../zbar/libzbar)

target_link_libraries(scan-image
    zbar
    # $ENV{LIBGNUWIN32}/bin/jpeg62.dll
    # $ENV{LIBGNUWIN32}/bin/libpng3.dll
    # $ENV{LIBGNUWIN32}/bin/libpng12.dll
)