#include <stdio.h>
#include <ctype.h>

/* atof: convert string s to double, including scientific notation */
double atof(char s[])
{
	double val, power, result;
	int i, sign;
	int exp, expSign;

	for (i = 0; isspace((unsigned char)s[i]); i++)
		;

	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;

	for (val = 0.0; isdigit((unsigned char)s[i]); i++)
		val = 10.0 * val + (s[i] - '0');

	if (s[i] == '.')
		i++;

	for (power = 1.0; isdigit((unsigned char)s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}

	result = sign * val / power;

	if (s[i] == 'e' || s[i] == 'E') {
		i++;
		expSign = (s[i] == '-') ? -1 : 1;
		if (s[i] == '+' || s[i] == '-')
			i++;

		for (exp = 0; isdigit((unsigned char)s[i]); i++)
			exp = 10 * exp + (s[i] - '0');

		while (exp > 0) {
			result = (expSign == 1) ? result * 10.0 : result / 10.0;
			exp--;
		}
	}

	return result;
}

int main(void)
{
	printf("atof(\"123.45\")      = %f\n", atof("123.45"));
	printf("atof(\"123.45e2\")    = %f\n", atof("123.45e2"));
	printf("atof(\"123.45e-2\")   = %f\n", atof("123.45e-2"));
	printf("atof(\"123.46E-6\")   = %.12f\n", atof("123.46E-6"));
	printf("atof(\"   -7.5E+3\")  = %f\n", atof("   -7.5E+3"));

	return 0;
}
