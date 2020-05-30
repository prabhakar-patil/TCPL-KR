/* Exercise 2-3. Write a function htoi(s) , which converts a string of hexadecimal digits (including an optional 0x or 0X ) into its equivalent integer value. The allowable digits are 0 through 9 , a through f , and A through F. */
#include <stdio.h>

#define NUM "FFFF" /* 755D */

int htoi(char hexnum[]);

main()
{
	int num;

	num = htoi(NUM);
	printf("%d\n", num);
	return 0;
}

int htoi(char hexnum[])
{
	int i;
	int num;

	for (i=0; hexnum[i] != '\0'; ++i); /* get hexnum char length */

	i = 0;
	if (i > 2 && hexnum[i] == '0')
		++i;
		if (hexnum[i] == 'x' || hexnum[i] == 'X')
			++i;

	num = 0;
	for (i=0; hexnum[i] != '\0' && ((hexnum[i] >= '0' && hexnum[i] <= '9') ||
					(hexnum[i] >= 'A' && hexnum[i] <= 'F') ||
				    	(hexnum[i] >= 'a' && hexnum[i] <= 'f')); ++i) {
		if (hexnum[i] >= '0' && hexnum[i] <= '9')
			num = num * 16 + hexnum[i] - '0';
		else if (hexnum[i] >= 'A' && hexnum[i] <= 'F')
			num = num * 16 + (hexnum[i] - 'A' + 10);
		else if (hexnum[i] >= 'a' && hexnum[i] <= 'f')
			num = num * 16 + (hexnum[i] - 'a' + 10);
	}
	return num;
}
