#include <stdio.h>
#include "../include/analyzer.h"
 
 struct AnalyzerLine {
    fpos_t startIndex;
    fpos_t endIndex;
    char* content;
    long long dictPos;
};

int isLetter(char ch) {
    return 'A' <= ch && ch <= 'z';
}

char toLower(char ch) {
    return 'A' <= ch && ch <= 'Z' ? ch + 'a' - 'A' : ch;
}

int isGreater(char ch1, char ch2) {
    return ch1 > ch2;
}

int analyzer(char* fileName) {
    FILE* file = fopen(fileName, "r");
    
    if (file == NULL)
        return 0;
    
    
    
    
    
    
    
    
    long long numberOfLines = 0;
    for (register char currentChar = fgetc(file);; currentChar = fgetc(file)) {
        if (currentChar == '\n')
            ++numberOfLines;
        else if (currentChar == -1) {
            ++numberOfLines;
            break;
        }
    }
    printf("%lld\n", numberOfLines);
    
    
    
    
    
    
    
    
    
    
    
    fseek(file, 0L, SEEK_SET);
    AnalyzerLine lines[numberOfLines];
    for (long long startIndex = 0, lineIndex = 0; lineIndex < numberOfLines; ++startIndex) {
        char ch = fgetc(file);
        printf("Ch: %c(%d)\n", ch, ch);
        
        if (isLetter(ch)) {
            AnalyzerLine* pLine = &lines[lineIndex];
    
            (*pLine).startIndex = startIndex;
            for (long long endIndex = startIndex + 1;; ++endIndex) {
                char ch = fgetc(file);
                
                if (ch == '\n' || ch == -1) {
                    (*pLine).endIndex = endIndex;
                    startIndex = endIndex;
                    lineIndex++;
                    break;
                }
            }
        }
        else if (ch == '\n') {
            lines[lineIndex].endIndex = lines[lineIndex].startIndex = startIndex;
            lineIndex++;
        }
    }
    for (long long i = 0; i < numberOfLines; ++i) {
        printf("Line: %lld; start: %lld; end: %lld\n", i, lines[i].startIndex, lines[i].endIndex);
    }
    
    
    
    
    
    char sortedLines[numberOfLines];
    
    
    
    
    fclose(file);
    
    return 1;
}