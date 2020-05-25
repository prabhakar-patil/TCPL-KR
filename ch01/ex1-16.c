/* Exercise 1-16. Print longest line input. Revise the main routine of the longest-line program so it will correctly print the length of arbitrary long input lines, and as much as possible of the text. */
/* Improved :
 * Calculate max line length which crossess MAXLINE and print in front of line, but line string should be restricted to MAXLINE */
#include <stdio.h>

#ifndef MAXLINE
	#define MAXLINE  1000
#endif

int _getline(char line[], int maxline);
void copy(char to[], char from[]);

main()
{
	int len;	/* current len of line */
	int max;	/* max len of line in input */
	char line[MAXLINE];
	char longest[MAXLINE];

	len = 0;
	max = 0;

	while ((len = _getline(line, MAXLINE)) > 0) {
		if (max < len) {
			max = len;
			copy (longest, line);
		}
	}

	if (max > 0)
		printf ("[%3d] %s", max, longest);
	return 0;
}

int _getline(char line [], int maxline)
{
	int i, j;
	int c;

	for (i=0, j=0; (c = getchar())!= EOF && c!='\n'; ++i) { /* allow loop to continue till EOF or newline */
		if (j < maxline-2) {	/* -2 since line[] should be long enough to hold \n and \0 characters */
			line[j] = c;
			j++;
		}
	}
	if (c == '\n') {
		line[j] = c;
		++j;
		++i;
	}
	
	line[j] = '\0';
	return i;
}

void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
