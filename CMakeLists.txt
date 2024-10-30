cmake_minimum_required(VERSION 3.29)
project(libuniversesim
        VERSION 0.1.0
        LANGUAGES C
)

include(FetchContent)

message(STATUS "Building ${PROJECT_NAME} version ${PROJECT_VERSION}")
message(STATUS "CMake C compiler: ${CMAKE_C_COMPILER_ID}")
message(STATUS "CMake system name: ${CMAKE_SYSTEM_NAME}")
message(STATUS "CMake host system processor: ${CMAKE_HOST_SYSTEM_PROCESSOR}")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
option(BUILD_TESTS "Build with unit tests" OFF)

# Set C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Collect source and header files
file(GLOB_RECURSE SOURCE_FILES src/*.c)
file(GLOB_RECURSE PUBLIC_HEADER_FILES include/*.h)

# Add shared library target
#add_library(${PROJECT_NAME} ${SOURCE_FILES})
if (BUILD_SHARED_LIBS)
    add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
    target_compile_definitions(${PROJECT_NAME} PRIVATE BUILD_SHARED_LIBS)
else ()
    add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})
endif ()

# Include public headers in the target
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else ()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif ()

# Install the library and headers
install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}Targets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
)

# Install headers
install(DIRECTORY include/ DESTINATION include)

message("Building tests")
FetchContent_Declare(
        unity
        GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
        GIT_TAG v2.6.0
)
set(UNITY_STATIC ON)
FetchContent_MakeAvailable(unity)

# Add test executable
file(GLOB TEST_FILES tests/*.c)
add_executable(run_tests ${TEST_FILES})
target_link_libraries(run_tests unity ${PROJECT_NAME})

# Add a custom target to run the tests
add_custom_target(tests
        COMMAND run_tests
        DEPENDS run_tests
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
