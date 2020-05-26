/* Exercise 1-22. Write a program to ``fold'' long input lines into two or more shorter lines after the last non-blank character that occurs before the n-th column of input. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column. */
#include <stdio.h>
#define TABSTOP 8
#ifndef MAXCOL
	#define MAXCOL 80
#endif
int expandtab(char line[], int pos);
int findblank(char line[], int pos);
void printline(char line[], int pos);
int newcurpos(char line[], int pos);
main()
{
	int i;
	int c;
	int pos;		/* holds current position of incoming character in line */
	char line[MAXCOL];
	pos = 0;
	while ((c = getchar()) != EOF) {
		line[pos] = c;
		if (c == '\t') {
			pos = expandtab(line, pos);
		}
		else if (c == '\n') {
			printline(line, pos);
			pos = 0;
		}
		else if (++pos >= MAXCOL) {
			pos = findblank(line, pos);
			printline(line, pos);
			pos = newcurpos(line, pos);
		}
	}
}
int newcurpos(char line[], int pos)
{
	int i, j;
	if (pos >= MAXCOL)
		return 0;
	j = 0;
	for (i = pos; i < MAXCOL; ++i) {
		line[j] = line[i];
		++j;
	}
	return j;
}
/* finds blank character left from current position pointed by pos
 * if blank char does not find, returns pos as it is back to callee
 * indicating not blank found */
int findblank(char line[], int pos)
{
	int i;
	for (i = pos; i > -1; --i) {
		if (line[i] == ' ')
			return i;
	}
	if (i == 0)
		return pos;	/* no blank found */
}
/* prints a line buffer till current position pointed by pos
 * additionally inserts newline to output */
void printline(char line[], int pos)
{
	int i;
	for (i = 0; i < pos; ++i)
		putchar(line[i]);
	putchar('\n');
}
/* expands a tab to blanks at position in line buffer pointed by pos
 * tab to blank calculation is based on current pos w.r.t. TABSTOP */
int expandtab(char line[], int pos)
{
	line[pos] = ' '; /* one tab can take at least one space */
	for (pos = pos+1; pos < MAXCOL && (pos % TABSTOP)!= 0; ++pos)
		line[pos] = ' ';
	if (pos < MAXCOL) {
		return pos;
	}
	else {
		printline(line, pos);
		return 0; /* since line is printed out, reset pos */
	}
}
