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




//Problem 1
int conditional(int x, int y, int z) {
    int xcomplement = ~x + 1;
    int l = (((xcomplement)>>sizeof(x)) | (x>>sizeof(x))); //if x is 0 then l = 0 otherwise l = OxFFFFFF...
    int k = (l & y); //if l is all ones then k = y. if l is 0 then k = 0
    int ret = (k | (z & ~l)); //if l is 0 then k is 0 and ~l is 1111...1. Therefor ret = z. Otherwise ret = k, which is y.
    return ret;
    //return x ? y : z; // z if x is 0, y if x != 0
    
    //PS I really liked this problem it made me think alot in a diff way :)
}

int main(int argc, char *argv[]) {     
   printf("Expected Answer is 3. Actual Answer is %d\n", conditional(0,2,3));
   printf("Expected Answer is 2. Actual Answer is %d\n", conditional(1,2,3));
   printf("Expected Answer is 2. Actual Answer is %d\n", conditional(-1,2,3));
   return 0;
}
