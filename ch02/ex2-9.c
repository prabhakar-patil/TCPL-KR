/* Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x . Explain why. Use this observation to write a faster version of bitcount */

/* Explaination - Any two successive number, when represented in its binary format, their LSB bits are opposite to each other.
 * If former has 1, then follower has 0 and vice-versa. When you do &(Logical AND) operation on two different logic bits, its output is 0,
 * resulting deleting LSB bit(rightmost bit) */

/* Sample output-
 * Enter x(in hex): 5
 * x's bit count: 2
 * */
#include <stdio.h>

unsigned int htoi(char s[]);
int bitcount(unsigned int);

main()
{
	int i, c;
	unsigned int x;
	char s[10];

	printf("Enter x(in hex): ");
	i = 0;
	while ((c = getchar()) != '\n')
		s[i++] = c;
	s[i] = '\0';
	x = htoi(s);

	printf("x's bit count: %d\n", bitcount(x));
	return 0;
}

int bitcount(unsigned int x)
{
	int b;

	for (b=0; x != 0; x &= x-1)
		b++;
	return (b);
}

unsigned int htoi(char s[])
{
	int i;
	unsigned int num;

	i = 0;
	/* s[] length assumed to be >= 2 */
	if (s[i] == '0' && (s[i+1] == 'x' || s[i+1] == 'X'))
		i +=2;

	num = 0;
	for (; s[i] != '\0'; i++) {
		if (s[i] >= '0'  && s[i] <= '9')
			num = num*16 + s[i] - '0';
		else if (s[i] >= 'A'  && s[i] <= 'F')
			num = num*16 + s[i] - 'A' + 10;
		else if (s[i] >= 'a'  && s[i] <= 'f')
			num = num*16 + s[i] - 'a' + 10;
	}
	return num;
}
