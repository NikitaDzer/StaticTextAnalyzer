#ifndef SORT_H
#define SORT_H

#include "line.h"

/*!
 * @brief Sorts lines in ascending order
 * @param lines LINE* Lines to be sort
 * @param lines_number Number of lines
 * @param sort_type Type of sort (1 - comparator starts from begin of line, 2 - comparator starts from end of line)
 * @return 0 if lines were sorted successfully
 */
int sort(Line* const lines, const size_t lines_number, const int sort_type);

#endif // SORT_H
