#ifndef LINE_H
#define LINE_H

#include <cstdio>

/*!
 * @brief Struct for representing line information
 */
struct Line {
   const char* ptr;
   size_t size;
};

/*!
 * @brief Counts number of lines in text
 * @param text CHAR* Text to be split into lines
 * @return Number of lines
 */
size_t get_lines_number(const char* const text);

/*!
 * @brief YOU MUST FREE THIS MEMORY! Gets full information of text's lines and returns pointer to them
 * @param text CHAR* Text to be split into lines
 * @param lines_number SIZE_T Number of lines
 * @return Pointer to array of lines
 */
Line* get_lines(const char* const text, const size_t lines_number);


#endif // LINE_H
