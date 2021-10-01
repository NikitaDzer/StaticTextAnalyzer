#include <cstdio>
#include <cstdlib>
#include <cctype>
#include "../include/analyze.h"
#include "../include/sort.h"
#include "../include/line.h"

static const char* outputFile_defaultPath = "../output.txt";

static size_t get_file_size(FILE* const file) {
   size_t currentIndex = ftell(file);
   size_t file_size = 0;
   
   fseek(file, 0, SEEK_END);
   file_size = ftell(file);
   fseek(file, (long)currentIndex, SEEK_SET);
   
   return file_size;
}

int analyze(const char* const inputFile_path, const char* const outputFile_path = outputFile_defaultPath) {
   char* text       = nullptr;
   Line* lines      = nullptr;
   FILE* inputFile  = nullptr;
   FILE* outputFile = nullptr;
   size_t inputFile_size = 0,
          text_size      = 0,
          lines_number   = 0;
   
   inputFile = fopen(inputFile_path, "r");
   if (!inputFile) {
      printf("Cannot open input file with path %s.\n", inputFile_path);
      return 1;
   }

   inputFile_size = get_file_size(inputFile);
   text           = (char*)calloc(inputFile_size + 2, sizeof(char));
   if (!text) {
      printf("There is not enough memory for text.\n");
      return 2;
   }
   
   text_size = fread(text, sizeof(char), inputFile_size, inputFile) + 1;
   
   if (fclose(inputFile) == EOF) {
      printf("Cannot close input file with path %s.", inputFile_path);
      return -1;
   }
   
   text = (char*)realloc(text, text_size + 1);
   if (!text) {
      printf("Something wrong went with realloc.\n");
      return 2;
   }
   
   text[text_size - 1] = '\n';
   text[text_size] = '\0';
   
   lines_number = get_lines_number(text);
   lines        = get_lines(text, lines_number);
   if (!lines) {
      printf("There is not enough memory for 'lines'.\n");
      return 2;
   }
   
   sort(lines, lines_number);
   
   outputFile = fopen(outputFile_path, "w");
   if (!outputFile) {
      printf("Cannot open output file with path %s!", outputFile_path);
      return 1;
   }

   for (size_t line_index = 0; line_index < lines_number; ++line_index)
      fwrite(lines[line_index].ptr, sizeof(char),
             lines[line_index].size + 1, outputFile);

   if (fclose(outputFile) == EOF) {
      printf("Cannot close input file with path %s.", outputFile_path);
      return -1;
   }
   
   free(lines);
   free(text);
   
   return 0;
}