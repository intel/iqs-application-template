cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

if (NOT DEFINED ENV{CXX})
    set(ENV{CXX} gcc)
endif()

# set project name
project(iqs-app VERSION 1.0 LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

################################################################################

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# set the location of helper CMake modules in the source tree.
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

################################################################################
# Options for the build.
################################################################################

option(IqsAppUtest "Enable unit test for config-json project?" OFF)

################################################################################
# Main executables
################################################################################

# Add the main source file contained in /src.
add_subdirectory(src)

# Add the unit test contained in /unit_test
# If required, googletest framework is downloaded and configured.
if (IqsAppUtest)
    message(STATUS "Unit tests for iqs-app : enabled.")
    add_subdirectory(unit_test)
else()
    message(STATUS "Unit tests for iqs-app : disabled.")
endif()

################################################################################
