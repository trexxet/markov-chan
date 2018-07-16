cmake_minimum_required(VERSION 3.10)
project(markov_chan)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
include_directories(include)

set(SRC
        src/main.cpp
        src/State.cpp
        src/Chain.cpp
        src/Learn.cpp
        src/Run.cpp)

add_executable(markov_chan ${SRC})
