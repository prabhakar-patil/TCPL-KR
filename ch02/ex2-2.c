/* Exercise 2-2. Write a loop equivalent to the for loop above without using && or || . */
#include <stdio.h>

main()
{
	int i;
	int lim;
	int c;
	int condition; /* 1 if loop needs to conitnue otherwise 0 */

	i = 0;
	lim = 1000;
	condition = 1;

	while (condition) {
		if (i < lim-1) {
			if ((c = getchar()) != EOF) {
				if (c != '\n') {
					// todo: operation
					++i;
				}
				else {
					printf("c = %d, i: %d\n", c, i);
					condition = 0;
				}
			}
			else {
				printf("c: %d, i: %d\n", c, i);
				condition = 0;
			}
		}
		else {
			printf("i: %d\n", i);
			condition = 0;
		}
	}
}
