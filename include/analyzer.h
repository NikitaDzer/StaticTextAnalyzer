#ifndef STATICTEXTANALYZER_ANALYZER_H
#define STATICTEXTANALYZER_ANALYZER_H

struct Line {
   const char* ptr;
   size_t size;
};

int analyze(const char* const file_name);

#endif // STATICTEXTANALYZER_ANALYZER_H
