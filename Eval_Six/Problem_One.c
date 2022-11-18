/*
Ashvin Ganesan
Charlie McGuffey
CSCI 221
Friday November 18th 2022
Evaluation Six
*/

#include <stdint.h>
#include <inttypes.h>

uint32_t decaying_sum(uint16_t* values, uint16_t length, uint16_t decay){
    return decaying_sum_priv(values, length, length-1, decay, 0);
}

uint32_t decaying_sum_priv(uint16_t* values, uint16_t length, uint16_t counter, uint16_t decay, int val) {
    if(counter == length) {
        return 0;
    }
    return decaying_sum_priv2(values, length, counter-1, decay, (values[counter] +(int)(val/decay)));
}


uint32_t decaying_sum_priv_while(uint16_t* values, uint16_t length, uint16_t decay) {
    uint32_t val = 0;
    while(length >= 0) {
        val = val/decay;
        val += values[length];
        length--;

    }
    return val;

}