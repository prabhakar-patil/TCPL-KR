/* Exercise 1-14. Write a program to print a histogram of the frequencies of different characters in its input */
#include <stdio.h>

#define NR_ALPHABETS 26 

main()
{
	int c;
	int i, j;
	int char_histogram[26];

	for (i = 0; i < 26; ++i)
		char_histogram[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c >= 'A' && c <= 'Z') 
			++char_histogram[c - 'A'];

		if (c >= 'a' && c <= 'z')
			++char_histogram[c - 'a'];
	}

	for (i = 0; i < 26; ++i) {
		printf ("%c ", i + 'A');
		for (j = 0; j < char_histogram[i]; ++j)	
			printf("*");
		printf(" %d\n", char_histogram[i]);
	}
}
