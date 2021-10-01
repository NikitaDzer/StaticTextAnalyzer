#ifndef COMPARE_H
#define COMPARE_H

#include "line.h"

/*!
 * @brief Compares lines from their beginning
 * @param line1 Line* First line
 * @param line2 Line* Second line
 * @return 0 if first line is bigger than second and 1 in other cases
 */
int compare_lines(Line* line1, Line* line2);

/*!
 * @brief Compares lines from their ending
 * @param line1 Line* First line
 * @param line2 Line* Second line
 * @return 0 if first line is bigger than second and 1 in other cases
 */
int compareReversibly_lines(Line* line1, Line* line2);

#endif // COMPARE_H
