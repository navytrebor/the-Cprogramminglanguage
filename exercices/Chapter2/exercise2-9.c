#include <stdio.h>

/*
 * x &= (x - 1) clears the rightmost 1-bit in x.
 * Reason (two's complement):
 *   - subtracting 1 flips all trailing 0 bits after the rightmost 1, and
 *     turns the rightmost 1 to 0.
 *   - x has that rightmost 1 as 1 and trailing bits as 0.
 *   - x-1 has that bit as 0, trailing bits as 1, and higher bits unchanged.
 *   - ANDing x with x-1 keeps high bits unchanged (same in both), clears the
 *     rightmost 1 (1 & 0 -> 0), and clears trailing bits (0 & 1 -> 0).
 */
int bitcount(unsigned x)
{
    int b;
    for (b = 0; x != 0; x &= (x - 1))
        b++;
    return b;
}

int main(void)
{
    unsigned values[] = {0u, 1u, 0xF0F0u, 0xFFFFFFFFu, 0x12345678u};
    int i;

    for (i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
        unsigned x = values[i];
        printf("x = 0x%X, bitcount = %d\n", x, bitcount(x));
    }
    return 0;
}
