/* Verify that the expression getchar() != EOF is 0 or 1. */
#include <stdio.h>

main()
{
	int cond; // 0 or 1
	int ch;
	while (cond = ((ch=getchar()) != EOF)) {
		if (ch != 0x0A) // ignore enter/newline
			printf ("Expression : %d\n", cond);
	}
	
	printf ("Expression : %d\n", cond);
}
