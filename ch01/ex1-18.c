/* Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines. */
#include <stdio.h>

#define MAXLINE 1000
#define	BLANK ' '
#define TAB '\t'

int _getline(char line[], int maxline);
int remove_blank_tabs(char line[]);

main()
{
	int len;
	char line[MAXLINE];

	while ((len = _getline(line, MAXLINE)) > 0) {
		if (remove_blank_tabs(line) > 0)
			printf("%s", line);
	}

}

int remove_blank_tabs(char line[])
{
	int i;

	for (i=0; line[i] != '\n'; ++i);	/* go to end of line */

	for (i = i-1; i>-1 && (line[i] == BLANK || line[i] == TAB); --i); /* backtrace till there is no blank and tab char */
	
	if (i >= 0) {
		++i;
		line[i] = '\n';
		++i;
		line[i] = '\0';
	}
	return i;
}

int _getline(char line[], int maxline)
{
	int i, j, k;
	int c;
	int is_valid_eol = 0;  /* holds valid end of line state where trailing blanks and/or tabs are not included */

	for (i = 0, j = 0; (c = getchar())!=EOF && c!='\n'; ++i) {
		if (j < maxline-2) { /* room for newline and/or null */
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
