/* Exercise 1-22. Write a program to ``fold'' long input lines into two or more shorter lines after the last non-blank character that occurs before the n-th column of input. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column. */
#include <stdio.h>
#define MAXLINE 1000
#ifndef FOLDAT
	#define FOLDAT 80
#endif
int _getline(char line[], int maxline);
int fold(char line[], int col);
main()
{
	int i;
	int len;
	int nr_folds; 		/* keeps count of folds of a line */
	char line[MAXLINE];
	len = 0;
	nr_folds = 0;
	while ((len = _getline(line, MAXLINE)) > 0) {
		nr_folds = fold(line, FOLDAT);
		printf("%s", line);
		/*while (nr_folds) {
			for (i = 0; line[i] != '\n' && i < MAXLINE; ++i) {
				putchar(line[i]);
			}
			if (i < MAXLINE)
				putchar(line[i]);
			--nr_folds;
		}*/
	}
}
/* folds a line > maxcol into two or more
 * maxcol: max column number beyond which line is to be folded
 * returns fold count: a single line folded in n lines */
int fold(char line[], int maxcol)
{
	int nr_folds;	/* fold count of input line after fold operation done */
	int len; 	/* length of input line */
	int i, j;
	for (i = 0; line[i] != '\n'; ++i);
	len = i;
	/*if (len <= maxcol)
		return 1;
		*/
	nr_folds = (len-1)/maxcol + 1;
	/* look back from end to find blank of tab character to fold line */
	for (i = 0; i < nr_folds-1; i++) {
		//for (j = ((i+1)*maxcol-1); (j >= i*maxcol) && (line[j]!='\t' || line[j]!=' '); --j);
		j = (i+1)*maxcol - 1;
		printf("j:[%2d, %2d]\n", i*maxcol, j);
		while ((j >= i*maxcol) && line[j] != '\t' && line[j] != ' ')
			--j;
		if (j >= (i*maxcol))
			line[j] = '\n';
	}
	return nr_folds;
}
int _getline(char line[], int maxline)
{
	int i, j;
	int c;
	for (i = 0, j = 0; (c = getchar())!=EOF && c!='\n'; ++i) {
		if (j < maxline-2) { /* room for newline and null */
			line[j] = c;
			++j;
		}
	}
	if (c == '\n') {
		line[j] = c;
		++j;
		++i;
	}
	line[j] = '\0';
	return i; /* original line length */
}
