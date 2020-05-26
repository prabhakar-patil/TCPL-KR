/* Exercise 1-24. Write a program to check a C program for rudimentary syntax errors like unmatched parentheses, brackets and braces. Don't forget about quotes, both single and double, escape sequences, and comments. (This program is hard if you do it in full generality.) */
#include <stdio.h>

int braces;		/* {} */
int brackets;		/* [] */
int parenthesis;	/* () */

void skip_comment(int c);
void skip_quote(int c);
void match_other(int c);

main()
{
	int c, d;
	extern int braces, brackets, parenthesis;
	braces = brackets = parenthesis = 0;

	while ((c = getchar()) != EOF) {
		if (c == '/') {
			if ((d = getchar()) == '*') {
				skip_comment(c);
			}
		}
		else if (c == '"' || c == '\'') {
			skip_quote(c);
		}
		else {
			match_other(c);
		}
	}

	if (braces != 0)
		printf("Unmatched braces: %d\n", braces);
	if (brackets != 0)
		printf("Unmatched brackets: %d\n", brackets);
	if (parenthesis != 0)
		printf("Unmatched parenthesis: %d\n", parenthesis);

	return 0;
}

/* function mataches other end of braces/bracket/parenthesis pair */
void match_other(int c)
{
	extern int braces, brackets, parenthesis;
	static int cnt= 0;

	if (c == '{')
		++braces;
	else if (c == '}')
		--braces;
	else if (c == '[')
		++brackets;
	else if (c == ']')
		--brackets;
	else if (c == '(')
		++parenthesis;
	else if (c == ')')
		--parenthesis;
}

/* function stays here and gives control back to callee after end of comment */
void skip_comment(int c)
{
	int d;

	d = 0;
	while (c != '*' || d != '/') {
		c = d;
		d = getchar();
	}
}

/* function stays here and gives control back to callee after end of quote (' or ") */
void skip_quote(int c)
{
	int d;
	while ((d = getchar()) != c) { 	/* loop until it get matching quoute */
		if (d == '\\')		/* ignore characters after escape sequece. Escape sequence is used inside quotes so need to take space care */
			getchar();

	}
}

