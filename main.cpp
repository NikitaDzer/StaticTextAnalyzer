#include <cstdio>
#include "include/analyzer.h"

int main() {
    printf("Static text analyzer.\n");
    
    char path[] = "../text.txt";
    int result = analyze(path);
    
    return result;
}