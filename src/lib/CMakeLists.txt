# generated by cmake-generator
cmake_minimum_required(VERSION 3.16.3)

add_library(thunder STATIC
  audio_node.c
  circular_buffer.c
  debug_sine.c
  sound_compositor.c
  sound_module.c)

include(Tornado.cmake)
set_tornado(thunder)

target_include_directories(thunder PUBLIC ../include)


target_link_libraries(thunder PUBLIC
  thunder-audio-buffer
  basal)

