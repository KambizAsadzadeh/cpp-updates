cmake_minimum_required(VERSION 3.5)

project(cpp-updates LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cpp-updates
    main.cpp
    optional-01.cpp
    ranges-01.cpp
    ranges-02.cpp
    ranges-03.cpp
    ranges-04.cpp
    ranges-05.cpp
    ranges-06.cpp
    ranges-07.cpp
    ranges-08.cpp
    accumulate.cpp
    span-01.cpp
    concepts-01.cpp
    concepts-02.cpp
    concepts-03.cpp
    concepts-04.cpp
)

install(TARGETS cpp-updates
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
