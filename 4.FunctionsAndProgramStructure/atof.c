#include <stdio.h>
#include <ctype.h>

/* atof: convert string to double */

double atof (char s[])
{
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') 
        i++;
    for (val = 0.0; isdigit(s[i]); i++) 
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    return sign * val / power;
}

int main(void)
{
    printf("atof(\"123.45\")  = %f\n", atof("123.45"));
    printf("atof(\"   -7.5\") = %f\n", atof("   -7.5"));
    printf("atof(\"+42\")     = %f\n", atof("+42"));
    printf("atof(\"19abc\")   = %f\n", atof("19abc"));

    return 0;
}
