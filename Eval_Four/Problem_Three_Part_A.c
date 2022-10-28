/*
Ashvin Ganesan
Charlie McGuffey
CSCI 221
Friday October 28th 2022
Evaluation Four
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
//PART A
//This is trying to do exponentiation fast
//I used the debugger with VS code and used break points(also just running test code was helpful)
//I realized after I was supposed to use GDB. If I was to use GDB I would run the commmand that shows all warnings

int exponentiate(int x, int exponent) {
    int ret = 1;
    // The issue was that when it never entered the while loop it would still return r*x once. 
    //The simplest fix was just catching the corner case with this if statement
    if(exponent == 0) { 
        return 1;
    }
    while (exponent > 1) {
        if (exponent % 2 == 1) {
            ret = x * ret;
        }
        x = x * x;
        exponent = exponent / 2;
    }
    return ret * x;
}


int main(int argc, char *argv[]) {
    for(int i = 0; i < 10; i++) {
        int pow = exponentiate(2,i);
        printf("%d\n",pow);
    }
    return 0;
    
}
