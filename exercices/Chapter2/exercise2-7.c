#include <stdio.h>

/*Write a function invert(x,p,n) that returns x with the n bits that begin at position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.*/

unsigned invert(unsigned x, int p, int n)
{
    unsigned mask = ((1u << n) - 1u) << (p - n + 1);
    return x ^ mask;
}

int main(void)
{
    unsigned x = 0b1111000011110000u;
    int p = 7;
    int n = 4;

    unsigned r = invert(x, p, n);

    printf("x      = 0x%X (%u)\n", x, x);
    printf("p=%d n=%d\n", p, n);
    printf("result = 0x%X (%u)\n", r, r);

    return 0;
}
