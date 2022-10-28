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


// int main(int argc, char *argv[]) {
//     for(int i = 0; i < 10; i++) {
//         int pow = exponentiate(2,i);
//         printf("%d\n",pow);
//     }
//     return 0;
    
// }





//PART B
struct point2d{
    int x;
    int y;
};


//Note to self bugs z is not used and m is also essentially not used
//z is not initialized properly
//We don't free the stuff
int main(char* argc, char* argv) {
    int m = atoi(argv[1]);
    struct point2d *p = malloc(sizeof(struct point2d));
    p->x = atoi(argv[2]);
    p->y = atoi(argv[3]);
    struct point2d *z = malloc(sizeof(struct point2d));
    z->x = 0;
    z->y = z->y - (m * p->x);
    printf("x coord: %d\n", p->x);
    printf("y coord: %d\n", p->y);
    return 0;
}
