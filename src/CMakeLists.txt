# Add Intel Quantum Simulator as submodule

execute_process (
    COMMAND bash -c "git submodule add -b master git@github.com:iqusoft/intel-qs.git ${PROJECT_SOURCE_DIR}/extern/intel-qs"
    COMMAND bash -c "git submodule update --init"
)

# Build external project without MPI, unit tests, and Python bindings.
set(IqsMPI OFF CACHE INTERNAL "")
set(IqsUtest OFF CACHE INTERNAL "")
set(IqsPython OFF CACHE INTERNAL "")

# Create directory <repo>/extern
# and set the corresponding binary to <repo>/build/extern/intel-qs
add_subdirectory(${PROJECT_SOURCE_DIR}/extern/intel-qs ${PROJECT_BINARY_DIR}/extern/intel-qs)

# Suppress warnings when building external project
# NOTE: the IQS library as a CMake target is called 'iqs'.
target_compile_options(iqs INTERFACE -w)

message(STATUS "CMAKE_BINARY_DIR = ${CMAKE_BINARY_DIR}")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR = ${CMAKE_CURRENT_SOURCE_DIR}")

################################################################################
# Main executable of this repo, possibly including other .cpp files in <repo>/src/

add_executable(gearbox src/main_gearbox.cpp)
target_link_libraries(gearbox PUBLIC iqs)
target_include_directories(gearbox PRIVATE
                           "${PROJECT_SOURCE_DIR}/include"
                           "${PROJECT_BINARY_DIR}/extern/intel-qs/include"
                          )
#                           "${PROJECT_BINARY_DIR}"

set_target_properties(gearbox PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

#target_include_directories(gearbox
#    PUBLIC
#        $<INSTALL_INTERFACE:${CMAKE_SOURCE_DIR}/include>
#        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
#    PRIVATE
#    ${CMAKE_CURRENT_SOURCE_DIR}
#)

################################################################################

