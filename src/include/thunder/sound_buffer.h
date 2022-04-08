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
#ifndef thunder_sound_buffer_h
#define thunder_sound_buffer_h

#include "sound_types.h"

struct ImprintMemory;

typedef struct thunder_audio_buffer {
    int atom_size;
    int buffer_count;
    ThunderSampleOutputS16** buffers;
    ThunderSampleOutputS16* read_buffer;
    int read_buffer_samples_left;
    int write_index;
    int read_index;
} thunder_audio_buffer;

void thunder_audio_buffer_write(thunder_audio_buffer* self, const ThunderSample* samples, int sample_count);

void thunder_audio_buffer_read(thunder_audio_buffer* self, ThunderSampleOutputS16* output, int sample_count);

void thunder_audio_buffer_init(thunder_audio_buffer* self, struct ImprintMemory* memory, int atom_count,
                               int atom_size);

void thunder_audio_buffer_free(thunder_audio_buffer* self);

float thunder_audio_buffer_percentage_full(thunder_audio_buffer* self);
int thunder_audio_buffer_atoms_full(thunder_audio_buffer* self);

#endif
