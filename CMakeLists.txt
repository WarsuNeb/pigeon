cmake_minimum_required(VERSION 3.3)
project(pigeon)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(.)

aux_source_directory(. SRC_ROOT)
aux_source_directory(aio SRC_AIO)
aux_source_directory(core SRC_CORE)
aux_source_directory(utils SRC_UTILS)

add_library(pigeon ${SRC_ROOT} ${SRC_AIO} ${SRC_CORE} ${SRC_UTILS})
