#include <cstdlib>
#include "../include/line.h"

static const char* get_line_ptr(const char* const startPtr) {
   const char* ptr = startPtr;
   
   while (true) {
      if (*ptr != '\n')
         return ptr;
      
      ++ptr;
   }
}

static size_t get_line_size(const char* const startPtr) {
   const char* endPtr = startPtr;
   
   while (*endPtr != '\n' && *endPtr != '\0')
      ++endPtr;
   
   return endPtr - startPtr;
}

size_t get_lines_number(const char* const text) {
   /*
   size_t lines_number = 0,
          currentIndex = 0,
          nextIndex    = 0;
   char currentChar = text[0],
        nextChar    = '\0';
   
   while (!isalpha(currentChar)) {
      if (currentChar == '\0')
         return 0;
      else
         currentChar = text[++currentIndex];
   }
   
   nextIndex = currentIndex + 1;
   nextChar = text[nextIndex];
   
   while (true) {
      if (currentChar == '\n') {
         if (isalpha(nextChar))
            ++lines_number;
      }
      else if (currentChar == '\0')
         return lines_number + 1;
   
      currentChar = nextChar;
      nextChar    = text[++nextIndex];
   }
    */
   
   size_t lines_number = 0;
   const char* ptr = text;
   
   while (true) {
      if (*ptr == '\0')
         return 0;
      
      if (*ptr != '\n')
         break;
      
      ++ptr;
   }
   
   while (true) {
      if (*ptr == '\0') {
         if (*(ptr - 1) == '\n')
            return lines_number;
         else
            return lines_number + 1;
         // return lines_number + *(ptr + 1) != '\n'
      }
      
      if (*ptr == '\n' && *(ptr + 1) != '\n')
         ++lines_number;
      
      ++ptr;
   }
}

Line* get_lines(const char* const text, const size_t lines_number) {
   size_t size = 0;
   const char* ptr = text;
   
   Line* const lines = (Line*)calloc(lines_number, sizeof(Line));
   if (!lines)
      return nullptr;
   
   lines[0].ptr = ptr;
   lines[0].size = size;
   
   for (size_t line_index = 0; line_index < lines_number; ++line_index) {
      ptr = get_line_ptr(ptr + size);
      size = get_line_size(ptr);
   
      lines[line_index].ptr  = ptr;
      lines[line_index].size = size;
   }

   return lines;
}