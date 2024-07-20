#include "buffer.h"
#include <stdio.h>

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}