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




//Problem 3
unsigned char addTinyFloatingPoint(unsigned char a, unsigned char b) {
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

    int retExp;
    if(aExp > bExp) {
        aSig = aSig << (aExp-bExp);
        retExp = bExp;
    } else {
        retExp = aExp;
        bSig = bSig << (bExp-aExp);
    }
    int val = (aSig*aSign)+(bSig*bSign);
    int retSign = 0;
    if(val < 0) {
        retSign = 1;
        val = -1*val;
    }
    // printf("aexp is %x\n", aExp);
    // printf("bexp is %x\n", bExp);
    // printf("retexp is %x\n", retExp);
    if(val >= 224) {
        return 0xFF;
    }
    while(val < 8) { //will only enter this if it is in the values [0,8]
        retExp--;
        val = val << 1;
    }
    while(val > 8) { 
        // printf("Value is %x\n", val);
        // printf("altered val %x\n", (val & 0xFFFFFFFA));
        retExp++;
        if(retExp > 8) {

            if(retSign == 0) {
                return 0x7A;
            }
            return 0xFA;
        }

        val = val >> 1;
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
    printf("%x\n",addTinyFloatingPoint(0b01011010,0b01011001));
    char temp = 0b01011011;
    printf("%x\n",temp);

    printf("%x\n",addTinyFloatingPoint(0b01011010,0b01011111));
    char temp2 = 0b01100100;
    printf("%x\n",temp2);

    printf("%x\n",addTinyFloatingPoint(0b01011010,0b11011001));
    char temp3 = 0b01011001;
    printf("%x\n",temp3);


    return 0;


}
