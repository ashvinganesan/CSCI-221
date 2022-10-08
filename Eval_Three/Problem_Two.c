/*
Ashvin Ganesan
Charlie McGuffey
CSCI 221
Friday October 7th 2022
Evaluation Three
*/

//Problem 2
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct OutputArrays {
    int* divisors;
    int* divisees;
    int length;
};
typedef struct OutputArrays OutputArrays;

OutputArrays* newOutputArrays(int* divisor, int* divisee, int len) {
    OutputArrays *n = (OutputArrays *)(malloc(sizeof(struct OutputArrays)));
    if(len == 0) {
        n->divisees = NULL;
        n->divisors = NULL;
        n->length = len;
        return n;
    }
    n->divisees = divisee;
    n->divisors = divisor;
    n->length = len;
    return n;
}


OutputArrays* findingDivisors(int* arr, int size) {
    int length = 0;
    for(int i = 0; i < size; i++) {
        for(int j = i+1; j < size; j++) {
            if(arr[i]%arr[j] == 0) {
                // printf("I: %d, J: %d \n", i, j);
                // printf("Divisee:%d, Divisor %d \n",arr[i], arr[j]);
                length++;
            } else if(arr[j]%arr[i] == 0) {
                // printf("I: %d, J: %d \n", i, j);
                // printf("Divisee:%d, Divisor %d \n",arr[j], arr[i]);
                length++;
            }
        }
    }
    // printf("Length is %d\n", length);
    int* divisor = (int*)malloc(sizeof(int) * length);
    int* divisee = (int*)malloc(sizeof(int) * length);
    int count = 0;
    for(int i = 0; i < size; i++) {
        for(int j = i+1; j < size; j++) {
            if(arr[i]%arr[j] == 0) {
                divisor[count] = arr[j];
                divisee[count] = arr[i];
                count++;
            } else if (arr[j]%arr[i] == 0) {
                divisor[count] = arr[i];
                divisee[count] = arr[j];
                count++;
            }
        }
    }
    // for(int i = 0; i < length;i++) {
    //     printf("Divisor: %d\n ",divisor[i]);
    //     printf("Divisee: %d\n",divisee[i]);
    // }
    return(newOutputArrays(divisor, divisee,length));

}

int main(int argc, char *argv[]) {
    int array [8] = {1,2,3,4,5,6,7,8};
    OutputArrays* arr = findingDivisors(array,8);
    for(int i = 0; i < arr->length;i++) {
        printf("Divisor: %d, ",arr->divisors[i]);
        printf("Divisee: %d\n",arr->divisees[i]);
    }
    return 0;
}