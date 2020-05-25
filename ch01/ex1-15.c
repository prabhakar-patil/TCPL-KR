/* Exercise 1.15. Rewrite the temperature conversion program of Section 1.2 to use a function for conversion */
#include <stdio.h> 

float ftoc(float fahr);

main()
{
	float fahr, celsius;
	float lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;

	printf("Fahreneit Celsius\n");

	while (fahr <= upper) {
		celsius = ftoc(fahr);
		printf("%3.0f\t%6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}

float ftoc(float fahr)
{
	return ((5.0/9.0) * (fahr - 32.0));
}
