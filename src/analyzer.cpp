#include <cstdio>
#include <cstdlib>
#include <cctype>
#include "../include/analyzer.h"
#include "../include/sort.h"

size_t get_file_size(FILE* const file) {
   size_t currentIndex = ftell(file);
   size_t file_size = 0;
   
   fseek(file, 0, SEEK_END);
   file_size = ftell(file);
   fseek(file, (long)currentIndex, SEEK_SET);
   
   return file_size;
}

const char* get_line_ptr(const char* const startPtr) {
   const char* ptr = startPtr;
   
   while (true) {
      if (*ptr == '\n' && isalpha(ptr[1]))
         return ptr + 1;
      
      if (*ptr == '\0')
         return nullptr;
      
      ++ptr;
   }
}

size_t get_line_size(const char* const startPtr) {
   const char* endPtr = startPtr + 1;
   
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
   
   size_t lines_number = 0,
          ch_index     = 0;
   char ch = text[0];
   
   while (!isalpha(ch)) {
      if (ch == '\0')
         return 0;
      else
         ch = text[++ch_index];
   }
   
   while (true) {
      if (ch == '\n') {
         if (isalpha(text[ch_index + 1]))
            ++lines_number;
      }
      else if (ch == '\0')
         return lines_number + 1;
      
      ch = text[++ch_index];
   }
}

Line* get_lines(const char* const text, const size_t lines_number) {
   if (lines_number) {
      Line* lines = (Line*)calloc(lines_number, sizeof(Line));
      size_t size = 0;
      const char* ptr = text;
      
      while (!isalpha(*ptr))
         ++ptr;
      size = get_line_size(ptr);
      
      lines[0].ptr = ptr;
      lines[0].size = size;
      
      for (size_t line_index = 1; line_index < lines_number; ++line_index) {
         ptr = get_line_ptr(ptr + size);
         size = get_line_size(ptr);
         
         lines[line_index].ptr  = ptr;
         lines[line_index].size = size;
      }
      
      return lines;
   }
   
   return nullptr;
}

int analyze(const char* const file_name) {
   FILE* file = fopen(file_name, "r");
   
   // Error processing
   if (file == nullptr)
      return 0;

   size_t file_size = get_file_size(file);
   char*  text      = (char*)calloc(file_size + 1, sizeof(char)); // prepared text
   size_t text_size = fread(text, sizeof(char), file_size, file);
   
   fclose(file);
   
   text = (char*)realloc(text, text_size + 1);
   text[text_size] = '\0';
   
   size_t lines_number = get_lines_number(text);
   Line* lines = get_lines(text, lines_number);
   
   sort(lines, lines_number);
  
   FILE* file_output = fopen("../output.txt", "w");
   for (size_t line_index = 0; line_index < lines_number; ++line_index) {
      fwrite((void*)lines[line_index].ptr, sizeof(char), lines[line_index].size + 1, file_output);
   }
   
   
   return 1;
}