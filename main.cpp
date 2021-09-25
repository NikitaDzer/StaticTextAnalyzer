#include <stdio.h>
#include "include/analyzer.h"

int main(void) {
    printf("Static text analyzer.\n");
    
    int result = analyzer("../text.txt");
    printf("%d", result);
    
    return 0;
}