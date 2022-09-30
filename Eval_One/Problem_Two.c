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

#define length(x) ((sizeof x) / (sizeof x[0]))

//Problem 2
u_int16_t find_divisor(int numbers[], size_t len) {
    for(int i = 0; i < len-1; i++) {
        for(int j = i+1; j < len;j++) {
            if((numbers[i]%numbers[j]) == 0) {
                //int arr[2] = {j, i};
                printf("{%d,%d}\n",numbers[j], numbers[i]);
                return 0;
            }
            if((numbers[j]%numbers[i]) == 0) {
                //int arr[2] = {i, j};
                printf("{%d,%d}\n",numbers[i], numbers[j]);
                return 0;
            }
        }
    }
    printf("{%d,%d}\n",0, 0);
    return 0;
}

int main(int argc, char *argv[]) {
    int arr[4] = {3, 8, 12, 20};
    size_t len = length(arr);
    find_divisor(arr, len);
    return 0;
}