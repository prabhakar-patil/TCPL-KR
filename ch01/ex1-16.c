/* Exercise 1-16. Print longest line input. Revise the main routine of the longest-line program so it will correctly print the length of arbitrary long input lines, and as much as possible of the text. */
#include <stdio.h>

#define MAXLINE  1000

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
		printf ("%s\n", longest);
	return 0;
}

int _getline(char line [], int maxline)
{
	int i;
	int c;

	for (i=0; i < maxline-1 && (c = getchar())!= EOF && c!='\n'; ++i)
		line[i] = c;

	if (c == '\n') {
		line[i] = c;
		++i;
	}
	
	line[i] = '\0';
	return i;
}

void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
