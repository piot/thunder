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
#include <imprint/memory.h>
#include <thunder/audio_node.h>
#include <thunder/sound_compositor.h>
#include <thunder/sound_module.h>

#include <clog/clog.h>

#include <math.h>

void thunder_sound_module_update(thunder_sound_module* _self)
{
	thunder_sound_module* self = _self;

	thunder_sound_driver_update(&self->driver);

	float percentage = thunder_audio_buffer_percentage_full(&self->compositor.buffer);
	if (percentage > 0.60f) {
		return;
	}

	thunder_audio_compositor_update(&self->compositor);
	if (percentage < 0.40f) {
		thunder_audio_compositor_update(&self->compositor);
	}

	if (percentage < 0.2f) {
		thunder_audio_compositor_update(&self->compositor);
	}
}

void thunder_sound_module_add_node(thunder_sound_module* self, thunder_audio_node node)
{
	self->compositor.nodes[self->compositor.nodes_count++] = node;
}

void thunder_sound_module_init(thunder_sound_module* self, struct imprint_memory* memory)
{
	self->memory = memory;

	thunder_audio_compositor_init(&self->compositor, memory);

	thunder_audio_compositor_update(&self->compositor);
	thunder_audio_compositor_update(&self->compositor);
	thunder_audio_compositor_update(&self->compositor);
	thunder_sound_driver_init(&self->driver, &self->compositor.buffer);
	self->initialized = TYRAN_TRUE;
}
