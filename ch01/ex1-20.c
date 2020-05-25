/* Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.  Should n be a variable or a symbolic parameter? --> 8 */
/* Improvement:
 * Number of blanks to put is not exactly replacing TAB by TABSTOP times spaces/blanks
 * It depends on where the \t character is positioned withing a given line. If it is positioned at multiples of TABSTOP then
 * it is perfectly okay to replace TABSTOP times spaces. But if it is not positioned at multiples of TABSTOP then you need
 * to calculate number of blanks/spaces to put replacing tabs, which is < TABSTOP spaces.
 * Calculated as below:
 * nr_blanks = TABSTOP - (tab char position in given line MODULUS TABSTOP)
 * nr_blanks = TABSTOP - (pos % TABSTOP)
 * where, pos starting value/index is 0 */
#include <stdio.h>

#ifndef TABSTOP
	#define TABSTOP 8
#endif

main()
{
	int c;
	int i;
	int c_pos;	/* character position in a given line, start index 0. Reset it at end of every line */
	int nr_blanks;	/* number of blanks to write instead of tab at give character postion in a given line */

	c_pos = 0;
	nr_blanks = 0;

	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			nr_blanks = TABSTOP - (c_pos % TABSTOP);	/* see description above */
			for (i = 0; i < nr_blanks; i++) {
				putchar(' ');
				++c_pos;
			}
		}
		else if (c == '\n') {
			c_pos = 0;
			putchar(c);
		}
		else {
			putchar(c);
			++c_pos;
		}
	}
}
