/* Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position p set to the rightmost n bits of y , leaving the other bits unchanged. */
#include <stdio.h>

unsigned int htoi(char s[]);
unsigned int dtoi(char s[]);
unsigned int setbits(unsigned int x, int p, int n, unsigned y);

main()
{
	int c;
	unsigned int x, y, p, n;
	int i;
	char h[10];

	printf("Enter x (in hex): ");
	i = 0;
	while ((c = getchar()) != EOF && c != '\n') {
		h[i++] = c;
	}
	h[i] = '\0';
	x = htoi(h);

	printf("Enter y (in hex): ");
	i = 0;
	while ((c = getchar()) != EOF && c != '\n') {
		h[i++] = c;
	}
	h[i] = '\0';
	y = htoi(h);

	printf("Enter p (in dec): ");
	i = 0;
	while ((c = getchar()) != EOF && c != '\n') {
		h[i++] = c;
	}
	h[i] = '\0';
	p = dtoi(h);

	printf("Enter n (in dec): ");
	i = 0;
	while ((c = getchar()) != EOF && c != '\n') {
		h[i++] = c;
	}
	h[i] = '\0';
	n = dtoi(h);

	x = setbits (x, p, n, y);
	printf("x after: 0x%x\n", x);
}

unsigned int setbits(unsigned int x, int p, int n, unsigned int y)
{
	printf("(x=0x%x, p=%d, n=%d, y=0x%x)\n", x, p, n, y);

	x = x & (~(~(~0 << n) << (p+1-n)));	/* reset x's p to p+1-n bits */
	x = x | ((~(~0 << n) & y) << (p+1-n));	/* OR y's rightmost n bits to x's position p to p+1-n */
	return x;
}

/* decimal ascii to integer */
unsigned int dtoi(char s[])
{
	int i;
	unsigned int num;

	num = 0;
	for (i=0; '\0' != s[i]; i++)
		num = num*10 + s[i] - '0';
	return num;
}

/* hex ascii to integer */
unsigned int htoi(char s[])
{
	int i;
	unsigned int num;

	i = 0;
	/* s length greater than 2 assumed */
	if (s[0] == 0 && (s[1] == 'x' || s[1] == 'X'))
		i = 2;

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
