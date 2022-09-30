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


//Problem 1
const char* choose_mover(int boxes) {
    int alice = 200 * (boxes / 23);
    int bob = 260 * (boxes/30);
    if((boxes % 23) > 0) {
        alice+= 200;
    }
    if((boxes % 30) > 0) {
        bob+= 260;
    }
    if(alice < bob) {
        return "Alice";
    }
    return "Bob";
}

int main(int argc, char *argv[]) {     
   printf("%s", choose_mover(30));
   return 0;
}
