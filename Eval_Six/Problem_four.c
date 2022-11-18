#include <math.h>

int accumulatorExponent(double number, double* list, int length) {
    for(int i = 0; i< length; i++) {
        number+= list[i];
    }
    int exp = frexp(number, &exp);
    return exp;
}