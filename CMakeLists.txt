cmake_minimum_required(VERSION 3.2)
project(MovingObject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(MovingObject ${SOURCE_FILES} QuadTree/quadtree.h QuadTree/quadtree.cpp QuadTree/object.h QuadTree/object.cpp QuadTree/node.h QuadTree/node.cpp QuadTree/leaf.h QuadTree/leaf.cpp QuadTree/entry.h QuadTree/entry.cpp QuadTree/Bucket.cpp QuadTree/Bucket.h)