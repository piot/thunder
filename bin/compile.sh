clang ../src/lib/*.c  ../deps/imprint/src/lib/*.c ../deps/tiny-libc/src/lib/*.c ../src/platform/sdl/*.c    ../src/platform/sdl_common/*.c  ../deps/breathe/src/platform/sdl/sdl_main.c ../src/example/app.c  -I ../src/include/ -I ../deps/include -lm -lSDL2 -D TORNADO_OS_LINUX -D CONFIGURATION_DEBUG