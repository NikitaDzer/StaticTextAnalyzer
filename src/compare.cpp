#include <cctype>
#include "../include/compare.h"

static int compare_chars(const char ch1, const char ch2) {
   if (ch2 == '\n')
      return 0;
   if (ch1 == '\n')
      return 1;
   
   if (ch1 == ch2)
      return -1;
   
   if (isalpha(ch1)) {
      if (isalpha(ch2)) {
         if (toupper(ch1) > toupper(ch2))
            return 0;
         if (toupper(ch1) == toupper(ch2))
            return ch2 > ch1;
         return 1;
      }
      
      return 0;
   }
   else if (isalpha(ch2))
      return 1;
   
   return ch2 > ch1;
}

int compare_lines(Line* line1, Line* line2) {
   const char* const line1_ptr = line1->ptr;
   const char* const line2_ptr = line2->ptr;
   int comparisonResult = 0;
   size_t i = 0;
   
   while (true) {
       comparisonResult = compare_chars(line1_ptr[i], line2_ptr[i]);
      
      if (comparisonResult != -1)
         return comparisonResult;
      
      ++i;
   }
}

int compareReversibly_lines(Line* line1, Line* line2) {
   const char* const line2_endPtr = line2->ptr + line2->size - 1;
   const char* const line1_endPtr = line1->ptr + line1->size - 1;
   int comparisonResult = 0;
   size_t i = 0;
   
   while (true) {
      comparisonResult = compare_chars(line1_endPtr[-i], line2_endPtr[-i]);
   
      if (comparisonResult != -1)
         return comparisonResult;
   
      ++i;
   }
}