#ifndef ANALYZE_H
#define ANALYZE_H

/*!
 * @brief Analyzes text in input file, sort it and put sorted text to output file
 * @param inputFile_path CHAR* Input file path
 * @param outputFile_path CHAR* Output file path
 * @return 0 if function put sorted text in output file successfully
 */
int analyze(const char* const inputFile_path, const char* const outputFile_path);

#endif // ANALYZE_H
