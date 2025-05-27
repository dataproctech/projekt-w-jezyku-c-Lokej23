cmake_minimum_required(VERSION 3.10)
project(PongGame C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall -Wextra -pedantic -g")
    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O2")
endif()

if(WIN32)
    set(SDL2_TTF_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/deps/SDL2_ttf-2.22.0/x86_64-w64-mingw32/include")
    set(SDL2_TTF_LIBRARY "${CMAKE_SOURCE_DIR}/deps/SDL2_ttf-2.22.0/x86_64-w64-mingw32/lib/libSDL2_ttf.dll.a")
# else()
#     set(SDL2_TTF_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/deps/SDL2_ttf-2.22.0/linux/include")
#     set(SDL2_TTF_LIBRARY "${CMAKE_SOURCE_DIR}/deps/SDL2_ttf-2.22.0/linux/lib/libSDL2_ttf.a")  # lub .so
endif()

find_package(SDL2 REQUIRED)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${SDL2_INCLUDE_DIRS}
    ${SDL2_IMAGE_INCLUDE_DIRS}
    ${SDL2_TTF_INCLUDE_DIR}
    ${SDL2_MIXER_INCLUDE_DIRS}
)

file(GLOB SOURCES "src/*.c")

add_executable(pong ${SOURCES})

target_link_libraries(pong
    ${SDL2_LIBRARIES}
    ${SDL2_IMAGE_LIBRARIES}
    ${SDL2_TTF_LIBRARIES}
    ${SDL2_MIXER_LIBRARIES}
)

install(TARGETS pong DESTINATION bin)

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/build)
