/* Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string t to s . Use a switch . Write a function for the other direction as well, converting escape sequences into the real characters. */
#include <stdio.h>

#define BUFSIZE 255
#define OUT 0
#define IN 1

void escape(char s[], char t[]);
void unescape(char t[], char s[]);

main()
{
	int c, i;
	char s[BUFSIZE];
	char d[BUFSIZE*2]; /* if all are escape sequences, array should hold sufficient space for visible whitespace */

	i = 0;

	while ((c = getchar()) != EOF && i < BUFSIZE-1)
		s[i++] = c;
	s[i] = '\0';

	escape(d, s);
	printf("\nescaped s[]: %s\n", d);

	unescape(s, d);
	printf("\nunescaped s[]: \n%s\n", s);
	return 0;
}

/* escape: converts newline and tags into visible \n and \t sequence */
void escape(char d[], char s[])
{
	int i, j, c;

	i = 0;
	j = 0;
	while ((c = s[i]) != '\0') {
		switch (c) {
			case '\n':
				d[j] = '\\';
				j++;
				d[j] = 'n';
				break;
			case '\t':
				d[j] = '\\';
				j++;
				d[j] = 't';
				break;
			default:
				d[j] = c;
				break;
		}
		i++;
		j++;
	}
	d[j] = '\0';
}

/* unescape: converts visible \n and \t sequences in s[] into non-visible whitespaces in d[] */
void unescape(char d[], char s[])
{
	int i, j, c;
	int state = OUT;

	i = 0;
	j = 0;

	while ((c = s[i]) != '\0') {
		switch (c) {
			case '\\':
				state = IN;
				break;
			default:
				if (state == IN) {
					state = OUT;
					if (c == 't')
						d[j++] = '\t';
					else if (c == 'n')
						d[j++] = '\n';
				}
				else {
					d[j++] = c;
				}
				break;
		}
		i++;
	}
	d[j] = '\0';
}
