/* Write a program that prints its input one word per line */
#include <stdio.h>

main()
{
	int c;
	int state;
	int is_prev_nl = 0;  /* 1: if previous character is newline otherwise 0*/

	while((c = getchar()) != EOF) {
		if(c == ' ' || c == '\t' || c == '\n') {
			if(is_prev_nl == 0) {
				putchar('\n');
				is_prev_nl = 1;
			}
		}
		else {
			putchar(c);
			is_prev_nl = 0;
		}
	}
}
