/* Write a program to count blanks, tabs, and newlines */
#include <stdio.h>

main()
{
	int blanks, tabs, newlines;
	int c;

	blanks = 0;
	tabs = 0;
	newlines = 0;

	while((c=getchar()) != EOF) {
		if(c == '\n')
			++newlines;
		if(c == '\t')
			++tabs;
		if(c == ' ')
			++blanks;
	}

	printf("blanks: %d, tabs: %d, newlines: %d\n", blanks, tabs, newlines);
}
