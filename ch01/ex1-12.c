/* Write a program that prints its input one word per line */
#include <stdio.h>

#define IN 1 /*Inside a word*/
#define OUT 0 /*Outside a word*/

main()
{
	int c;
	int state;
	int is_prev_nl = 0;  /* 1: if previous character is newline otherwise 0*/
	state = OUT;

	while((c = getchar()) != EOF) {
		if(c == ' ' || c == '\t' || c == '\n')
			state = OUT;
		else {
			putchar(c);
			is_prev_nl = 0;
		}

		if(state == OUT) {
			state = IN;
			if(is_prev_nl == 0) {
				putchar('\n');
				is_prev_nl = 1;
			}
		}
	}
}
