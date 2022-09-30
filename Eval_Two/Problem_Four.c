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




//Problem 4
unsigned char multTinyFloatingPoint(unsigned char a, unsigned char b) {
    int bias = 7; //bias = 2^3-1
    int aSig = a & 0x07;
    int bSig = b & 0x07;
    a = a >> 3;
    b = b >> 3;
    int aExp = (a & 0x0F) -bias;
    //For whoever is reading this if you don't have the () then it - takes precedence over & :( This bug made me sad!
    int bExp = (b & 0x0F) - bias;
    a = a >> 4;
    b = b >> 4;
    int aSign = a & 0x01;
    int bSign = b & 0x01;
    if(aSign == 1) {
        aSign = -1;
    } else {
        aSign = 1;
    }
    if(bSign == 1) {
        bSign = -1;
    } else {
        bSign = 1;
    }
    int retSign = aSign*bSign;

    int retExp = aExp + bExp-2;

    if(retSign == -1) {
        retSign = 1;
    } else {
        retSign = 0;
    }
    // printf("retsign is %x\n", retSign);
    if(retExp > 8) {
        if(retSign == 0) {
            return 0x7A;
        }
        return 0xFA;
    }
    int val = aSig * bSig;

    printf("aexp is %x\n", aExp);
    printf("bexp is %x\n", bExp);
    printf("retexp is %x\n", retExp);
    printf("asig is %x\n", aSig);
    printf("bsig is %x\n", bSig);
    printf("val is %x\n", val);

    while(val > 8) { 
        printf("Value is %x\n", val);
        // printf("altered val %x\n", (val & 0xFFFFFFFA));
        retExp++;
        if(retExp > 8) {

            if(retSign == 0) {
                return 0x7A;
            }
            return 0xFA;
        }

        val = val/4;
        printf("Altered Value is %x\n", val);
    }
    // printf("After While\n Value is %x\n", val);
    // printf("altered val %x\n", (val & 0xFFFFFFFA));
    // printf("val is %d\n", val);
    // printf("retExp is %d\n", (retExp));
    // printf("Sign is %d\n", (retSign));

    retExp = retExp + bias;
    int ret = (retSign << 7) | (retExp << 3) | val;




    return ret;
}

int main(int argc, char *argv[]) {     

    printf("ANSWER IS %x\n",multTinyFloatingPoint(0b01001010,0b01000101));    
    return 0;


}
