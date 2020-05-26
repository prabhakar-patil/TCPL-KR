/* Exercise 1-23. Write a program to remove all comments from a C program. Don't forget to handle quoted strings and character constants properly. C comments don't nest. */
#include <stdio.h>

#define MAXLINE 1000

#define OUT 0	/* out of quoted string or comment */
#define IN 1	/* in quoted string or comment */

main()
{
	int c, prev_c, pprev_c;
	int quote;	/* hold state "IN/OUT" */
	int comment;	/* hold state "IN/OUT" */
	
	quote = OUT;
	comment = OUT;		
	prev_c = 0;
	pprev_c = 0;

	while ((c = getchar()) != EOF) {
		if (c == '"' && comment == OUT) {
			if (quote == OUT)
				quote = IN;
			else 
				quote = OUT;
		}

		if (c == '*' && prev_c == '/' && quote == OUT)
			comment = IN;
		if (c == '/' && prev_c == '*' && quote == OUT && comment == IN)
			comment = OUT;
		else if (comment == OUT && c!='/') {
			if (c!='*' && prev_c=='/' && pprev_c != '*')
				putchar('/');
			putchar(c);
		}
		
		pprev_c = prev_c;
		prev_c = c;
	}
}
