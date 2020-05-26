/* Exercise 1-23. Write a program to remove all comments from a C program. Don't forget to handle quoted strings and character constants properly. C comments don't nest. */
#include <stdio.h>

void skip_comment(int c);
void print_quote(int c);

main()
{
	int c, d;

	while ((c = getchar()) != EOF) {
		if (c == '/') {
			if ((d = getchar()) == '*')
				skip_comment(c);
			else {
				putchar(c);
				putchar(d);
			}
		}
		else if (c == '"' || c == '\'') {
			print_quote(c);
		}
		else {
			putchar(c);
		}
	}
}

/* removes comment from output prints */
void skip_comment(int c)
{
	int d;
	c = getchar();
	d = getchar();

	while (c != '*' || d != '/') {
		c = d;
		d = getchar();
	}
}

/* print quotes separately, since this is specail case */
void print_quote(int c)
{
	int d;

	d = 0;
	putchar(c); /* print starting quoute */

	while ((d = getchar()) != c) {
		putchar(d);
		if (d == '\\') {/* escape sequence inside quote */
			d = getchar();
			putchar(d);	/* print escaped character */
		}
	}
	putchar(d); /* print ending quote */
}
