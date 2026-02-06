cmake_minimum_required(VERSION 3.13)

# Always export compile commands for tools like eglot and clang-tidy.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Default to Debug builds if there is a local git repository, RelWithDebInfo otherwise.
set(default_build_type "RelWithDebInfo")
if(EXISTS "${CMAKE_SOURCE_DIR}/.git")
  set(default_build_type "Debug")
endif()

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPE)
  message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
  set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE STRING "Choose type of build." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

# Default board type to pico2 if none specified.
if(NOT PICO_BOARD)
  set(PICO_BOARD "pico2")
  message(STATUS "Setting board type to '${PICO_BOARD}' as none was specified.")
endif()

# Include the Pico SDK CMake support.  This MUST happen before project().
if(NOT DEFINED ENV{PICO_SDK_PATH} OR "$ENV{PICO_SDK_PATH}" STREQUAL "")
  message(FATAL_ERROR "Environment variable PICO_SDK_PATH is missing or empty.")
endif()
include("$ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake")

project(pico2_basic_cmake C CXX ASM)
pico_sdk_init()

add_executable("${PROJECT_NAME}" pico2_basic_cmake.c)
target_compile_features("${PROJECT_NAME}" PRIVATE c_std_17)
target_compile_options("${PROJECT_NAME}" PRIVATE -Wall -Wextra)
target_link_libraries("${PROJECT_NAME}" pico_stdlib)

# Set stdio to use the USB connector and not the UART.
pico_enable_stdio_usb("${PROJECT_NAME}" 1)
pico_enable_stdio_uart("${PROJECT_NAME}" 0)

# Create the extra output files.
pico_add_extra_outputs("${PROJECT_NAME}")

