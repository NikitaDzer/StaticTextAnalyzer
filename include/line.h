#ifndef LINE_H
#define LINE_H

#include <cstdio>

struct Line {
   const char* ptr;
   size_t size;
};

size_t get_lines_number(const char* const text);

Line* get_lines(const char* const text, const size_t lines_number);


#endif // LINE_H
