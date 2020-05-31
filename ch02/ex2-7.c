/* Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged. */

/* Sample output -
 * $ ./a.out
 * Enter x (in hex): 0xaa
 * enter p (in dec): 7
 * enter n (in dec): 8
 * (x=0xaa, p=7, n=8)
 * x after invert: 0x55
 * */
#include <stdio.h>

unsigned int htoi(char s[]);
unsigned int dtoi(char s[]);
unsigned int invert(unsigned int x, int p, int n);

main()
{
	int i, c;
	char s[10];
	unsigned int x;
	int p, n;

	printf("Enter x (in hex): ");
	i = 0;
	while ((c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	s[i] = '\0';
	x = htoi(s);

	printf("enter p (in dec): ");
	i = 0;
	while ((c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	s[i] = '\0';
	p = dtoi(s);

	printf("enter n (in dec): ");
	i = 0;
	while ((c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	s[i] = '\0';
	n = dtoi(s);

	x = invert(x, p, n);
	printf("x after invert: 0x%x\n", x);
	return 0;
}

unsigned int invert(unsigned int x, int p, int n)
{
	int x_not;	/* x's p to p+1-n  bits in inverted form at rightmost bit postion in x_not */
	int mask;	/* holds mask(relevant 1s) for x from p to p+1-n bits */
	printf("(x=0x%x, p=%d, n=%d)\n", x, p, n);

	x_not = 0;
	mask = (~(~0 << n)) << (p+1-n);

	x_not = ~(x & mask) & mask;	/* invert x's p to p+1-n bits */
	x = x_not | (x & ~mask);	/* reset x's p to p+1-n bits to 0, and OR with inverted value */
	return x;
}

/* hex ascii to integer */
unsigned int htoi(char s[])
{
	int i;
	unsigned int num;

	i = 0;
	/* length of s string is assumed to be >=2 */
	if (s[i] == '0' && (s[i+1] == 'x' || s[i+1] == 'X'))
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

/* decimal ascii to integer */
unsigned int dtoi(char s[])
{
	int i;
	unsigned int num;

	num = 0;
	for (i = 0; s[i] != '\0'; i++)
		num = num*10 + s[i] - '0';
	return num;
}
