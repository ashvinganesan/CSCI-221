#include <stdint.h>
#include <inttypes.h>


uint64_t product(uint32_t a, uint32_t b) {
    uint64_t ret = a*b;
    return ret;
}

uint64_t* retList(uint32_t* array1, uint32_t* array2, int length) {
    uint64_t* array3 = malloc(sizeof(array1)*length);
    for (int i=0; i<length; i++){
        array3[i] = product(array1[i], array2[i]);
    }
    return array3;
}
