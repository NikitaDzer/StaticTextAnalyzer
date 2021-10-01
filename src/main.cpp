#include "../include/analyze.h"

int main() {
    char inputFile_path[] = "../input.txt",
         outputFile_path[] = "../output.txt";
    
    int result = analyze(inputFile_path, outputFile_path);
    
    return result;
}