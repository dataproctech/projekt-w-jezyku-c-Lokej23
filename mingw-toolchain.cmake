# mingw-toolchain.cmake
set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_PROCESSOR x86_64)

set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)
set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)

# Ścieżka do wypakowanej biblioteki SDL2 dla Windows
set(SDL2_ROOT "${CMAKE_SOURCE_DIR}/deps/SDL2-2.30.0/x86_64-w64-mingw32")
set(SDL2_TTF_ROOT "${CMAKE_SOURCE_DIR}/deps/SDL2_ttf-2.22.0/x86_64-w64-mingw32")

# Poprawne wyszukiwanie include/lib z SDL2
set(CMAKE_FIND_ROOT_PATH ${SDL2_ROOT} ${SDL2_TTF_ROOT})
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
