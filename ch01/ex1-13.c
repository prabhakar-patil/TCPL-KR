/* Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging */
/* Use case:
 * $ cat ex1-13.c | ./a.out
 * */
#include <stdio.h>

#define MAX_WORD_LEN 255
#define BAR_CHAR '|'

main()
{
	int c; /* intput character */
        int i, j; /* counters */
	int word_len; /* counts length of characters in a word during one while iteration */
	int max_word_len; /* maximum length character from input */
	int max_occurrence_value; /* defines repeatation of any word having maximum length in input */
	int current_occurrence; /* variable used hold current occurence in loop */
	int word_histogram[MAX_WORD_LEN]; /* histogram array: index defines a word length and value defines occurrence of word in input */

	word_len = 0;
	max_word_len = 0;
	max_occurrence_value = 0;

	for (i = 0; i < MAX_WORD_LEN; ++i)
		word_histogram[i] = 0;

	while ((c = getchar()) != EOF) { 
		if(c == ' ' || c == '\t' || c == '\n') {
			++word_histogram[word_len];

			if (max_occurrence_value < word_histogram[word_len] && word_len != 0)
				max_occurrence_value = word_histogram[word_len];
		
			if (max_word_len < word_len)
				max_word_len = word_len;

			word_len = 0;
		}
		else {
			++word_len;
		}
	}

	for (i = 1; i < max_word_len; ++i) { /* started from index 1, since 0 length words doesn't exist*/
		printf("%2d ", i);
		for (j = 0; j < word_histogram[i]; ++j) 
			printf("%c ", BAR_CHAR);
		
		printf(" %d\n", word_histogram[i]);
	}

	printf("\n                Fig1: Histogram : Horizontal Bars                     \n");
	printf("\n                ---------------------------------                     \n");

	printf("\n");
	current_occurrence = max_occurrence_value;
	for (i = 0; i < max_occurrence_value; ++i) {
		printf("%2d ", current_occurrence);
		for (j = 1; j < max_word_len; ++j) {
			if (word_histogram[j] == current_occurrence) {
				printf(" %c ", BAR_CHAR);
			}
			else if (word_histogram[j] > current_occurrence) {
				printf(" %c ", BAR_CHAR);
			}
			else {
				printf ("   ");
			}
		}
		printf("\n");
		--current_occurrence;
	}
	printf("   ");
	for (i = 1; i < max_word_len; ++i)
		printf("%2d ", i);
	printf("\n");

	printf("\n                Fig2: Histogram : Vertical Bars                     \n");
	printf("\n                -------------------------------                     \n");
}
