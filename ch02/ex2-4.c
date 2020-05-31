/* Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes each character in s1 that matches any character in the string s2 */
#include <stdio.h>

void squeeze(char s1[], char s2[]);

main()
{
	int c;
	int i;
	/*char s1[] = "The C++ Programming Language";
	char s2[] = "The C Programming Language";
	*/
	char s1[512];
	char s2[512];

	i = 0;
	printf("Enter s1: ");
	while ((c = getchar()) != EOF && c != '\n') {
		s1[i++] = c;
	}
	s1[i] = '\0';

	i = 0;
	printf("Enter s2: ");
	while ((c = getchar()) != EOF && c != '\n') {
		s2[i++] = c;
	}
	s2[i] = '\0';

	squeeze(s1, s2);
	printf("\nsqueezed s1: %s\n", s1);
}

/* in place modification to s1 */
void squeeze(char s1[], char s2[])
{
	int c;
	int i, j, k;

	for (i = 0; s2[i] != '\0'; i++) {
		k = 0;
		for (j = 0; s1[j]!= '\0'; j++) {
			if (s1[j] != s2[i])
				s1[k++] = s1[j];
		}
		s1[k] = '\0';
	}
}
