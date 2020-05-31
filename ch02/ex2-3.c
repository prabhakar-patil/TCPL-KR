/* Exercise 2-3. Write a function htoi(s) , which converts a string of hexadecimal digits (including an optional 0x or 0X ) into its equivalent integer value. The allowable digits are 0 through 9 , a through f , and A through F. */
#include <stdio.h>

#define MAX_DIGIT_LEN 10 /* 8 nibbles for max 32 bit hex number + 2 chars for 0x or 0X */

unsigned int htoi(char hexnum[]);

main()
{
	int c;
	int i;
	unsigned int num;
	char hexnum[MAX_DIGIT_LEN];

	i = 0;
	printf("Enter Hex Number (Range: 0x0 - 0xFFFFFFFF): ");
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			hexnum[i] = '\0';
			num = htoi(hexnum);
			printf("%u\n", num);
			printf("Enter Hex Number (Range: 0x0 - 0xFFFFFFFF): ");
			i = 0;
		}
		else {
			hexnum[i] = c;
			++i;
		}
	}
	return 0;
}

unsigned int htoi(char hexnum[])
{
	int i;
	unsigned int num;
	int len;

	for (i=0; hexnum[i] != '\0'; ++i); /* get hexnum char length */

	len = i;
	i = 0;
	if (len > 2 && hexnum[i] == '0')
		++i;
		if (hexnum[i] == 'x' || hexnum[i] == 'X')
			++i;

	num = 0;
	for (; hexnum[i] != '\0' && ((hexnum[i] >= '0' && hexnum[i] <= '9') ||
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
