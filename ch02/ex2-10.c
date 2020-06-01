/* Exercise 2-10. Rewrite the function lower , which converts upper case letters to lower case, with a conditional expression instead of if-else */

/* Sample Output -
 * ABCDEFGHIJKlmnopqrstuvWXYZ
 * abcdefghijklmnopqrstuvwxyz
 * */
#include <stdio.h>

int lower(int c);

main()
{
	int c;

	while ((c = getchar()) != EOF)
		putchar(lower(c));
	return 0;
}

/* lower: convert c to lower case using ternary operators(?:); ASCII only */
int lower(int c)
{
	return (c >= 'A' && c <= 'Z') ? c - 'A' + 'a': c;
}
