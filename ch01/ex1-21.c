/* Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab . When either a tab or a single blank would suffice to reach a tab stop, which should be given so preference? --> tab would be given preference since program is for entabbing */
#include <stdio.h>

#define TABSTOP 8

main()
{
	int i,j;
	int c;
	int c_pos;	/* current position of character in a given line, index start at 0 */
	int nr_blanks;	/* number of blanks to put */
	int nr_tabs;	/* number of tabs to put */

	c_pos = 0;
	nr_blanks = 0;
	nr_tabs = 0;
	c_pos = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			if ((c_pos+1) % TABSTOP != 0) { /* space not positioned TABSTOP multiple boundary */
				++nr_blanks;
			}
			else { /* space positioned at TABSTOP boundary, worth put tab rather than space, previous space, if any, also adusted in tab */
				nr_blanks = 0;
				++nr_tabs;
			}
		}
		else { /* non space char */
			/* while we enter this else part, there can be
			 * 1.1 only tabs from previous if
			 * 1.2 only blanks from previous if
			 * 2. both tabs and spaces to put in sequence respectively
			 * 3. Either of above two, plus new \t character
			 * 3.1 Previous tabs + a new tab = No problem
			 * 3.2. Previous blanks + a new tab = previous blanks can be safely ignored and new tab is sufficient
			 * 4. Either of first two, plus non \t character
			 * */
			for (; nr_tabs > 0; --nr_tabs) 	/* case 1.1 and/or 2 */
				putchar('\t');
			if (c != '\t') { 		/* case 1.2 and/or 2 */
				for (; nr_blanks > 0; --nr_blanks)
					putchar(' ');
			}
			else {
				nr_blanks = 0;	/* case 3.2 */
			}

			putchar(c);	/* case 3.1 and/or 3.2 and/or 4 */

			if (c == '\n')
				c_pos = -1; /* reset */

			/* calculate character position after inserting new tab
			 * it should be end of new TABSTOP */
			if (c == '\t') /* case 3 */
				c_pos = c_pos + (TABSTOP - (c_pos % TABSTOP)) - 1;
		}
		++c_pos;
	}
}
