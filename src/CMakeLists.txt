cmake_minimum_required(VERSION 3.16.3)
project(thunder C)

add_subdirectory(deps/piot/basal-c/src/lib)
add_subdirectory(deps/piot/clog/src/lib)
add_subdirectory(deps/piot/tiny-libc/src/lib)
add_subdirectory(deps/piot/thunder-audio-buffer/src/lib)
add_subdirectory(deps/piot/imprint/src/lib)

add_subdirectory(lib)
