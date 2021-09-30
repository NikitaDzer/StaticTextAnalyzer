#include <cctype>
#include "../include/compare.h"

static int compare_chars(const char ch1, const char ch2) {
   if (ch2 == '\n')
      return 0;
   if (ch1 == '\n')
      return 1;
   
   if (ch1 == ch2 || (!isalpha(ch1) && !isalpha(ch2)))
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
   
   return 1;
}

int compare_lines(const char* const line1, const char* const line2) {
   size_t i = 0;
   int comparisonResult = 0;
   
   while (true) {
       comparisonResult = compare_chars(line1[i], line2[i]);
      
      if (comparisonResult != -1)
         return comparisonResult;
      
      ++i;
   }
}