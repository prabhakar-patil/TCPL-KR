/* Exercise 1-17. Write a program to print all input lines that are longer than 80 characters. */
#include <stdio.h>

#define MAXLINE 1000

#ifndef LINE_CUTOFF
	#define LINE_CUTOFF 80
#endif

int _getline(char line[], int maxline);

main()
{
	int len;
	char line[MAXLINE];

	while ((len = _getline(line, MAXLINE)) > 0) {
		if (len > LINE_CUTOFF)
			printf("[%3d] %s", len, line);
	}
}

int _getline(char line[], int limit)
{
	int c;
	int i, j;
	
	for (i = 0, j = 0; (c = getchar())!=EOF && c!='\n'; ++i) {
		if (j < limit-2) { /* room for newline and null */
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
	return i;
}
