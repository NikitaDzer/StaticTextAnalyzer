cmake_minimum_required(VERSION 3.20)
project(staticTextAnalyzer)

set(CMAKE_CXX_STANDARD 17)


add_executable(staticTextAnalyzer main.cpp src/analyzer.cpp include/analyzer.h)
