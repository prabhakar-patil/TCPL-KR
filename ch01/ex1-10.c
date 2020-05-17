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

		if(ch == '\b') {
			putchar('\\');
			putchar('b');
		}
		
		if(ch == '\\')
			putchar('\\');
	}
}
