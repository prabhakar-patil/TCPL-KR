/* Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank */
#include <stdio.h>

main()
{
	int ch=0, prev_ch=-1;

	while((ch=getchar()) != EOF) {
		if(ch != ' ')
			putchar(ch);

		if(ch == ' ') {
			if(prev_ch != ch)
				putchar(ch);
		}
		prev_ch = ch;
	}
}
