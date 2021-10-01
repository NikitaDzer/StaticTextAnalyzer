cmake_minimum_required(VERSION 3.20)
project(staticTextAnalyzer)

set(CMAKE_CXX_STANDARD 17)


add_executable(staticTextAnalyzer src/main.cpp src/analyze.cpp include/analyze.h src/sort.cpp include/sort.h src/compare.cpp include/compare.h src/line.cpp include/line.h)
