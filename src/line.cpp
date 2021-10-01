#include <cstdlib>
#include "../include/line.h"

static const char* get_line_ptr(const char* const startPtr) {
   const char* ptr = startPtr;
   
   // skip line
   while (true) {
      if (*ptr == '\0')
         return nullptr;

      if (*ptr == '\n')
         break;

      ++ptr;
   }
   
   // while ghost-line
   while (true) {
      // skip gaps after previous line
      while (*ptr == ' ')
         ++ptr;
      
      // skip line breaks
      while (*ptr == '\n')
         ++ptr;
   
      // text's end
      if (*ptr == '\0')
         return nullptr;
   
      // skip gaps before current line
      while (*ptr == ' ')
         ++ptr;
   
      if (*ptr != '\n')
         break;
      
      ++ptr;
   }
   
   return ptr;
}

static size_t get_line_size(const char* const startPtr) {
   const char* ptr = startPtr;
   const char* gapPtr = nullptr;
   
   while (true) {
      if (*ptr == '\n') {
         if (*(ptr - 1) != ' ')
            gapPtr = nullptr;
         
         break;
      }
      
      if (*ptr == ' ' && *(ptr - 1) != ' ')
         gapPtr = ptr;
      
      ++ptr;
   }
   
   if (gapPtr != nullptr)
      return gapPtr - startPtr;
   
   return ptr - startPtr;
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
      ptr = get_line_ptr(ptr);
      
      if (ptr != nullptr)
         ++lines_number;
      else
         break;
   }
   
   return lines_number;
}

Line* get_lines(const char* const text, const size_t lines_number) {
   size_t size = 0;
   const char* ptr = text;
   
   Line* const lines = (Line*)calloc(lines_number, sizeof(Line));
   if (!lines)
      return nullptr;
      
   for (size_t line_index = 0; line_index < lines_number; ++line_index) {
      ptr = get_line_ptr(ptr + size);
      size = get_line_size(ptr);
      
      lines[line_index].ptr  = ptr;
      lines[line_index].size = size;
   }
   

   return lines;
}