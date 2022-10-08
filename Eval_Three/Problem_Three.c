/*
Ashvin Ganesan
Charlie McGuffey
CSCI 221
Friday October 7th 2022
Evaluation Three
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
//Problem 3
char* findString(char* first, char* second, int firstLen, int secondLen) {
    for(int i = 0; i < firstLen;i++) {
        if(first[i] == second[0]) {
            for(int j = 0; j < secondLen; j++) {
                if(first[i+j] != second[j]) {
                    break;
                } 
                else if(j == secondLen-1) {
                    char* pointer = &first[i];
                    return pointer;
                }
            }
        }
    }
    char* pointer = &first[firstLen];
    return pointer;
}

int main(int argc, char *argv[]) {
    char* first = "first";
    char* second = "irll";
    char* third = "ir";
    char* stringFail = findString(first, second, 5,4);
    char* stringSuccess = findString(first, third, 5,2);
    //should print irst;
    printf("StringFail: %s\n", stringFail);
    printf("StringSuccess: %s\n", stringSuccess);
    
    return 0;
}