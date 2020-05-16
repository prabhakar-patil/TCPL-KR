#include <stdio.h>

/* print Celcius-Fahreneit table
 * for celsius = 0, 20, ..., 300; flaoting-point version*/
main()
{
	float celsius, fahr;
	float lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	celsius = lower;
	printf ("Celsius Fahreneit\n");

	while (celsius <= upper) {
		fahr = (celsius * (9.0/5.0)) + 32.0;
		printf("%3.0f\t%6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
