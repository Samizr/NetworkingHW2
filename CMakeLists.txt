cmake_minimum_required(VERSION 3.9)
project(NetworkingHW2)

set(CMAKE_CXX_STANDARD 11)

add_executable(NetworkingHW2 main.cpp Package.cpp WaitQueue.cpp Event.cpp Event.h Package.h Simulator.cpp DynamicArray.h MinHeap.h Simulator.h InputChannel.cpp InputChannel.h)