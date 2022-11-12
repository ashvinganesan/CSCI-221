#include<stdio.h>
int fibonacci(int n) {
    int f1 = 0;
    int f2 = 1; 
    int f3 = 2;
    int counter = 1;
    while(counter < n) {
        f3 = f2+f1;
        f1 = f2;
        f2 = f3;
        counter++;
    }
    return f1;

}
int main()
{
    printf("%d\n", fibonacci(1));
    printf("%d\n", fibonacci(2));
    printf("%d\n", fibonacci(3));
    printf("%d\n", fibonacci(4));
    printf("%d\n", fibonacci(5));
    printf("%d\n", fibonacci(6));
    printf("%d\n", fibonacci(7));

    return 0;
}
