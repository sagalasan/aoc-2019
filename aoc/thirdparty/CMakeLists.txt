include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.8.0
)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

# see https://cmake.org/cmake/help/latest/module/FindBoost.html
find_package(Boost REQUIRED COMPONENTS)

include_directories(${Boost_INCLUDE_DIR})
# Note: a target should be already defined using 'add_executable' or 'add_library'
