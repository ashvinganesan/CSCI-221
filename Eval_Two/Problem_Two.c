/*
Ashvin Ganesan
Charlie McGuffey
CSCI 221
Friday September 30th 2022
Evaluation Two
*/
#include <stdio.h>
#include <string.h>
#include <math.h>




//Problem 2
int logic(int numb) {
    //This is just the 1st part of the other problem :/
    int numbcomplement = ~numb + 1;
    int l = (((numbcomplement)>>sizeof(numb)) | (numb>>sizeof(numb))); 
    return (~l) & 1; //I think I have an avoidble double negative, but this is basically the previous problem so I just copy pasted and can't be bothered to change it
}

int main(int argc, char *argv[]) {     
   printf("Expected value is 0. Actual value is %d\n", logic(-100));
   printf("Expected value is 0. Actual value is %d\n", logic(100));
   printf("Expected value is 1. Actual value is %d\n", logic(0));
   return 0;
}
