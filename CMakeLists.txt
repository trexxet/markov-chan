cmake_minimum_required(VERSION 3.10)
project(markov_chan)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")


set(SRC main.cpp)

add_executable(markov_chan ${SRC})
