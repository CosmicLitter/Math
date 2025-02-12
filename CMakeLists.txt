cmake_minimum_required(VERSION 3.16)

project(Math 
  VERSION 0.0.1 
  LANGUAGES CXX 
  DESCRIPTION "A terrible vector math library"
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)
