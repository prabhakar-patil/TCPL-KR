/* Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.  Should n be a variable or a symbolic parameter? --> 8 */
#include <stdio.h>

#ifndef TABSTOP
	#define TABSTOP 8
#endif

main()
{
	int c;
	int i;

	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			for (i = 0; i < TABSTOP; i++)
				putchar(' ');
		}
		else {
			putchar(c);
		}
	}
}
