/* Write a program to copy its input to its output, replacing each tab by \t , each backspace by \b , and each backslash by \\ . This makes tabs and backspaces visible in an unambiguous way */
#include <stdio.h>

/* improvement: how to capture backspace and backslash on input */
main()
{
	int ch;

	while((ch = getchar()) != EOF) {
		if (ch != '\t' && ch != '\b' && ch != '\\')
			putchar(ch);

		if(ch == '\t') {
			putchar('\\');
			putchar('t');
		}

		if(ch == '\b') { /* entered from keyboard from input as Ctrl-H*/
			putchar('\\');
			putchar('b');
		}
		
		if(ch == '\\') { /* c backslash is represented as \\ and entered as \ from keyboard at input */
			putchar('\\');
			putchar('\\');
		}
	}
}
