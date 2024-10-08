cmake_minimum_required(VERSION 3.20)
project(CppBrainTeasers)
set(CMAKE_CXX_STANDARD 20)
enable_testing()

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

message(STATUS "CMAKE_CXX_COMPILER_ID is ${CMAKE_CXX_COMPILER_ID}")

# Memory sanitizer requires rebuilding the entire world, don't bother for now
set(VALID_SANITIZERS address thread undefined)
if(SANITIZER)
    if("${SANITIZER}" IN_LIST VALID_SANITIZERS)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=${SANITIZER}")
    else()
        message(FATAL_ERROR "Unknown SANITIZER option '${SANITIZER}', valid options are ${VALID_SANITIZERS}")
    endif()
endif()

function(add_puzzle NAME)
    add_executable(${NAME} ${NAME}.cpp)
    add_test(${NAME} ${NAME})
    if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "AppleClang")
        target_compile_options(${NAME} PRIVATE -Wall -Wextra -Wpedantic)
    elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
        target_compile_options(${NAME} PRIVATE /W4)
    else()
        message(FATAL_ERROR "Unknown compiler: ${CMAKE_CXX_COMPILER_ID}")
    endif()
endfunction()

add_puzzle(how-many-degrees)
add_puzzle(string-theory)
add_puzzle(counting-copies)
add_puzzle(hack-the-planet)
add_puzzle(going-global)
add_puzzle(a-destructive-relationship)
add_puzzle(whos-up-first)
add_puzzle(all-good-things-must-come-to-an-end)
add_puzzle(will-it-move)
add_puzzle(a-strange-assignment)
add_puzzle(whats-the-time-of-death)
add_puzzle(a-false-start)
add_puzzle(a-constant-struggle)
add_puzzle(aristotles-sum-of-parts)
add_puzzle(back-from-the-future)
target_link_libraries(back-from-the-future PRIVATE Threads::Threads)
add_puzzle(an-overloaded-container)
add_puzzle(a-strong-point)
add_puzzle(moving-out)
add_puzzle(a-little-sum-thing)
add_puzzle(monsters-on-the-move)
add_puzzle(sizing-up-some-characters)
add_puzzle(the-phantom-spaceship)
add_puzzle(off-to-a-good-start)
add_puzzle(a-specialized-string-theory)
add_puzzle(weakly-typed-strongly-puzzling)

add_subdirectory(examples)
