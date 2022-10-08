/*
Ashvin Ganesan
Charlie McGuffey
CSCI 221
Friday October 7th 2022
Evaluation Three
*/


//Problem 4
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


char* CopySubString(char* input, int start, int end) {
    char* substring = (char *)malloc(sizeof(char) * (end-start + 1));
    for(int i = start; i < end; i++) {
        *(substring + (i-start) * sizeof(char)) = *(input + (i) * sizeof(char));
    }
    *(substring + (end-start +1) * sizeof(char)) = '\0';
    return substring;
}

int main(int argc, char *argv[]) {
    char* string = "HELLO WORLD";
    char* substring = CopySubString(string, 1,3);
    printf("Substring: %s\n",substring);
    free(substring);
    return 0;
}