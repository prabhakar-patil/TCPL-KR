/* Exercise 1-19. Write a function reverse(s) that reverses the character string s . Use it to write a program that reverses its input a line at a time. */
#include <stdio.h>

#define MAXLINE 1000

int _getline(char line[], int maxline);
void reverse(char s[]);

main()
{
	int len;
	char line[MAXLINE];

	while ((len = _getline(line, MAXLINE)) > 0) {
		reverse(line);
		printf("%s", line);
	}
	return 0;
}

void reverse(char s[])
{
	int i;	/* index from left to right */
	int j;	/* index from right to left */	
	int tmp;

	i = 0;
	for (j = 0; s[j] != '\n'; ++j);

	--j;
	while (i < j) {
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp; 
		++i;
		--j;
	}
}

/* return original length of line (Not MAXLINE)*/
int _getline(char line[], int maxline)
{
	int i, j;
	int c;

	for (i=0, j=0; (c = getchar())!=EOF && c!='\n'; ++i) {
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
	return i;
}
