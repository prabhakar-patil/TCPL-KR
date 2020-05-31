/* Exercise 2-5. Write the function any(s1,s2) , which returns the first location in a string s1 where any character from the string s2 occurs, or -1 if s1 contains no characters from s2 .  (The standard library function strpbrk does the same job but returns a pointer to the location.) */
#include <stdio.h>

int any(char s1[], char s2[]);

main()
{
	int i, c;
	int first_location;
	char s1[512];
	char s2[512];

	printf("Enter s1: ");
	i = 0;
	while ((c = getchar()) != EOF && c != '\n')
		s1[i++] = c;
	s1[i] = '\0';
	if (c == EOF)
		putchar('\n');

	printf("Enter s2: ");
	i = 0;
	while ((c = getchar()) != EOF && c != '\n')
		s2[i++] = c;
	s2[i] = '\0';
	if (c == EOF)
		putchar('\n');

	first_location = any(s1, s2);
	printf("Location of first matching char of s2 in s1: %d\n", first_location);
	return 0;
}

int any(char s1[], char s2[])
{
	int i, j, k;
	unsigned int first_location; /* holds first(lower) location of any character from s2 which matches in s1 */

	first_location = -1;	/* max value of unsigned int */

	for (i=0; s2[i] != '\0'; i++) {
		for (j=0; s1[j] != '\0'; j++) {
			if (s1[j] == s2[i]) {
				if (first_location > j)
					first_location = j;
			}
		}
	}
	return first_location;
}
