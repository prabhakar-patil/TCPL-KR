/* Exercise 1-17. Write a program to print all input lines that are longer than 80 characters. */
#include <stdio.h>

#define MAXLINE 1000
#define LINE_CUTOFF 80

int _getline(char line[], int maxline);

main()
{
	int len;
	char line[MAXLINE];

	while ((len = _getline(line, MAXLINE)) > 0) {
		if (len > LINE_CUTOFF)
			printf("%s\n", line);
	}
}

int _getline(char line[], int limit)
{
	int c;
	int i;
	
	for (i = 0; i<limit-1 && (c = getchar())!=EOF && c!='\n'; ++i)
		line[i] = c;
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}
