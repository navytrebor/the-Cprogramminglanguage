#include <stdio.h>

/*Write a function rightrot(x,n) that returns the value of the integer x rotated to the right by n positions.*/

unsigned rightrot(unsigned x, int n)
{
    int bits = sizeof(unsigned) * 8;
    n %= bits;
    if (n < 0)
        n += bits;

    return (x >> n) | (x << (bits - n));
}

int main(void)
{
    unsigned x = 0x12345678u;
    int n = 8;

    unsigned r = rightrot(x, n);

    printf("x      = 0x%X\n", x);
    printf("n      = %d\n", n);
    printf("result = 0x%X\n", r);

    return 0;
}
