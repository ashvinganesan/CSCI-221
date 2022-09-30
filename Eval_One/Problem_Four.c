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
#include <stdlib.h>

#define length(x) ((sizeof x) / (sizeof x[0]));


//Problem 4
void fibonacci(int n) {
    int prev = 1;
    int current = 1;
    for(int i = 2; i < n; i++) {
        int temp = prev + current;
        prev = current;
        current = temp;
    }
    printf("%d\n", current);
}
int main(int argc, char *argv[]) {
    fibonacci(atoi(argv[1]));
}



