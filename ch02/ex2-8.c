/* Exercise 2-8. Write a function rightrot(x,n) that returns the value of the integer x rotated to the right by n positions */

/* Sample output -
 * Enter x (in hex): 0xAAAAAAAA
 * Enter n (in dec): 1
 * x right-rotate by n: 0x55555555
 * */
#include <stdio.h>

unsigned int htoi(char s[]);
unsigned int dtoi(char s[]);
unsigned int rightrot(unsigned int x, int n);

main()
{
	int i, c;
	unsigned int x;
	int n;
	char s[10];

	printf("Enter x (in hex): ");
	i = 0;
	while ((c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	s[i] = '\0';
	x = htoi(s);

	printf("Enter n (in dec): ");
	i = 0;
	while ((c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	s[i] = '\0';
	n = dtoi(s);

	x = rightrot(x, n);
	printf("x right-rotate by n: 0x%x\n", x);
	return 0;
}

unsigned int rightrot(unsigned int x, int n)
{
	unsigned int mask, tmp;
	int i, x_width;

	/* calculate bit size of x variable, which is unsigned int */
	for (tmp = ~0U, i = 0; tmp != 0; i++)
		tmp = tmp >> 1;
	x_width = i;

	mask = ~(~0 << n);
	x = (x >> n) | ((x & mask) << (x_width-n));
	return x;
}

unsigned int htoi(char s[])
{
	int i;
	unsigned int num;

	i = 0;
	/* lenght of s[] assumbed to be >= 2 */
	if (s[i] == '0' && (s[i] == 'x' || s[i] == 'X'))
		i = i+2;

	num = 0;
	for (; s[i] != '\0'; i++) {
		if (s[i] >= '0' && s[i] <= '9')
			num = num*16 + s[i] - '0';
		else if (s[i] >= 'A' && s[i] <= 'F')
			num = num*16 + s[i] - 'A' + 10;
		else if (s[i] >= 'a' && s[i] <= 'f')
			num = num*16 + s[i] - 'a' + 10;
	}
	return num;
}

unsigned int dtoi(char s[])
{
	int i;
	unsigned int num;

	num = 0;
	for (i=0; s[i] != '\0'; i++)
		num = num*10 + s[i] - '0';
	return num;
}
