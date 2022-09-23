/*
Ashvin Ganesan
Charlie McGuffey
CSCI 221
Friday September 23rd 2022
Evaluation One
*/
#include <stdio.h>
#include <string.h>
#include <math.h>

#define length(x) ((sizeof x) / (sizeof x[0]));

//Problem 3
int powers(int n) {
    int count = 0;
    //This is terribly inefficient implementation :P
    for(int i = 2; i < n; i++) {
        for(int j = 2; j < n; j++) {
            if(pow(i,j) <= n) {
                count++;
            }
        }
    }
    return count;
}

int main(int argc, char *argv[]) {
    int pow = powers(18);
    printf("%d",pow);
    return 0;
}

