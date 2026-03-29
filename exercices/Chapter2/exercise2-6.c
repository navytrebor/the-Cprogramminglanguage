#include <stdio.h>
/* Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged*/

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned mask = ((1u << n) - 1u) << (p - n + 1);
    return (x & ~mask) | ((y << (p - n + 1)) & mask);
}

int main(void)
{
    unsigned x = 0b1111000000001111u;
    unsigned y = 0b10101010u;
    int p = 7;
    int n = 4;

    unsigned r = setbits(x, p, n, y);

    printf("x      = 0x%X (%u)\n", x, x);
    printf("y      = 0x%X (%u)\n", y, y);
    printf("p=%d n=%d\n", p, n);
    printf("result = 0x%X (%u)\n", r, r);

    return 0;
}
