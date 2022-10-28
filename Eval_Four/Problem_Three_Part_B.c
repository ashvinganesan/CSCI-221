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
#include <stdlib.h>


//PART B
struct point2d{
    int x;
    int y;
};


//Note to self bugs z is not used and m is also essentially not used
//z is not initialized properly
//We don't free the stuff
//the first arg in main must be an int also 2nd arguement must have [] at the end

//I am making the assumption that this code is trying to scale the point by the scaler and rotate the point 90 degrees
// void rotate(int* args) {
//     int scaler = args[0];
//     struct point2d *point = malloc(sizeof(struct point2d));
//     point->x = args[1];
//     point->y = args[2];
//     struct point2d *output = malloc(sizeof(struct point2d));
//     output->x = 0 - (scaler * point->y);
//     output->y = 0 - (scaler * point->x);
//     printf("x coord: %d\n", output->x);
//     printf("y coord: %d\n", output->y);
//     free(point);
//     free(output);
//     return;
// }
int main(int argc, char* argv[]) {
    // int ret[] = {1,1,1};
    // rotate(ret);
    int scaler = atoi(argv[1]);
    struct point2d *point = malloc(sizeof(struct point2d));
    point->x = atoi(argv[2]);
    point->y = atoi(argv[3]);
    struct point2d *output = malloc(sizeof(struct point2d));
    output->x = 0 - (scaler * point->y);
    output->y = 0 - (scaler * point->x);
    printf("x coord: %d\n", output->x);
    printf("y coord: %d\n", output->y);
    free(point);
    free(output);
    return 0;
}
//I used the command line and terminal to test this code. when running it initially it was helpful to point out all the 
// warnings and errors within the code. It gave me some of the below info. Additionally Valgrind was helpful for spotting
// that we malloc the points but we never freed them in the original code. 
/*
Problem_Three_Part_B.c:23:5: error: first parameter of 'main' (argument count)
      must be of type 'int'
int main(char* argc, char* argv) {
    ^
Problem_Three_Part_B.c:23:5: error: second parameter of 'main' (argument array)
      must be of type 'char **'
*/