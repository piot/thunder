/*

MIT License

Copyright (c) 2012 Peter Bjorklund

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/
#if defined TORNADO_OS_WEBASSEMBLY || defined TORNADO_OS_MACOS || defined TORNADO_OS_LINUX

#ifndef thunder_sdl_sound_driver_h
#define thunder_sdl_sound_driver_h

struct thunder_audio_buffer;
#include <SDL2/SDL.h>
#include <tyran/tyran_types.h>

typedef struct thunder_sdl_sound_driver {
    struct thunder_audio_buffer* buffer;
    SDL_AudioDeviceID device_handle;
} thunder_sdl_sound_driver;

void thunder_sdl_sound_driver_init(thunder_sdl_sound_driver* self, struct thunder_audio_buffer* buffer, tyran_boolean use_floats);
void thunder_sdl_sound_driver_free(thunder_sdl_sound_driver* self);

#endif

#endif
