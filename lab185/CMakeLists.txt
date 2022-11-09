cmake_minimum_required(VERSION 3.23)
project(mlita_labs_lab185)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        lab185
        src/main.cpp
        src/lib/BinaryHeap.h
        src/lib/WeightedGraph.h
        src/lib/Deijkstra.h
        src/lib/WeightedGraph.h)
