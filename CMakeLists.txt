cmake_minimum_required(VERSION 3.15)

# NOTE: update executable name in .github/workflows/cmake.yml when changing executable name in this file
# for now, the project name is used as the executable name
project(RPG)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


###############################################################################

# external dependencies
#include(FetchContent)
#
#FetchContent_Declare(
#        SomeLib
#        GIT_REPOSITORY https://github.com/<SomeUser>/<SomeLib>.git
#        GIT_TAG        <some_git_hash> # <which tag/branch @ <some_date>>
#)
#
#FetchContent_MakeAvailable(SomeLib)

###############################################################################

# NOTE: update executable name in .github/workflows/cmake.yml when changing name here
add_executable(${PROJECT_NAME} main.cpp Item.cpp Item.h Player.cpp Player.h Entity.cpp Entity.h Utility.cpp Utility.h Game.cpp Game.h Stats.cpp Stats.h Attack_type.h Ingredient.cpp Ingredient.h Equipment.cpp Equipment.h Weapon.cpp Weapon.h Sword.cpp Sword.h Bow.cpp Bow.h Monster.cpp Monster.h Exception.h History.h Record.cpp Record.h RecordAttack.cpp RecordAttack.h RecordAttackBuilder.cpp RecordAttackBuilder.h RecordFight.cpp RecordFight.h)

###############################################################################

# custom compiler flags
message("Compiler: ${CMAKE_CXX_COMPILER_ID} version ${CMAKE_CXX_COMPILER_VERSION}")
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX /permissive- /wd4244 /wd4267 /wd4101)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)

    if("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU")
    elseif("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
        target_compile_options(${PROJECT_NAME} PRIVATE -stdlib=libc++)
        target_link_options(${PROJECT_NAME} PRIVATE -stdlib=libc++)
    endif()
endif()

###############################################################################

# sanitizers
# should disable them when releasing executables
if(APPLE)
    # if("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    # first check Apple since Apple is also a kind of Unix
    target_compile_options(${PROJECT_NAME} PRIVATE -fsanitize=address,undefined)
    target_link_options(${PROJECT_NAME} PRIVATE -fsanitize=address,undefined)
    # endif()
elseif(UNIX)
    if("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU")
        # we cannot mix sanitizers with Valgrind
    elseif("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
        if("${CMAKE_CXX_COMPILER_VERSION}" MATCHES "12.")
            # check leaks on Linux since macOS does not support the leaks sanitizer yet
            # leaks sanitizer is enabled by default on Linux, so we do not need to enable it explicitly
            target_compile_options(${PROJECT_NAME} PRIVATE -fsanitize=address,undefined)
            target_link_options(${PROJECT_NAME} PRIVATE -fsanitize=address,undefined)
        else()
            target_compile_options(${PROJECT_NAME} PRIVATE -fsanitize=memory,undefined -fsanitize-memory-track-origins)
            target_link_options(${PROJECT_NAME} PRIVATE -fsanitize=memory,undefined -fsanitize-memory-track-origins -Wl,-rpath,tools/llvm-project/build/lib)
        endif()
    endif()
endif()

###############################################################################

# use SYSTEM so clang-tidy does not report warnings from these directories
#target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${<SomeLib>_SOURCE_DIR}/include)
#target_link_directories(${PROJECT_NAME} PRIVATE ${<SomeLib>_BINARY_DIR}/lib)
#target_link_libraries(${PROJECT_NAME} <SomeLib>)

###############################################################################

# copy binaries to bin folder; these are uploaded as artifacts on each release
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(DIRECTORY data/ DESTINATION bin/data)
# install(FILES some_file1.txt some_file2.md DESTINATION bin)
