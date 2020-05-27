/* Exercise 2-1. Write a program to determine the ranges of char , short , int , and long variables, both signed and unsigned , by printing appropriate values from standard headers and by direct computation. Harder if you compute them: determine the ranges of the various floating-point types. */
#include <stdio.h>
#include <limits.h>

main()
{
	unsigned long num;
	printf("From Standard Headers\n");
	printf("---------------------\n");
	printf("char [%4d %4d]\n", CHAR_MIN, CHAR_MAX);
	printf("short [%6d %6d]\n", SHRT_MIN, SHRT_MAX);
	printf("int [%11d %11d]\n", INT_MIN, INT_MAX);
	printf("long [%20ld %20ld]\n", LONG_MIN, LONG_MAX);
	printf("----------------------------------------------------\n");

	printf("signed char [%4d %4d]\n", SCHAR_MIN, SCHAR_MAX);
	printf("signed short [%6d %6d]\n", SHRT_MIN, SHRT_MAX);
	printf("signed int [%11d %11d]\n", INT_MIN, INT_MAX);
	printf("signed long [%20ld %20ld]\n", LONG_MIN, LONG_MAX);
	printf("----------------------------------------------------\n");

	printf("unsigned char [%u %4u]\n", 0, UCHAR_MAX);
	printf("unsigned short [%u %6u]\n", 0, USHRT_MAX);
	printf("unsigned int [%u %11u]\n", 0, UINT_MAX); printf("unsigned long [%d %20lu]\n", 0, ULONG_MAX);
	printf("----------------------------------------------------\n\n");

	printf("By Direct Computation\n");
	printf("---------------------\n");

	num = (signed char)((unsigned char)~0 >> 1);/* ~0: convert to all 1's and limit to max unsigned char by typecast, shift right by 1 to divide by 2*/
	printf("signed char [%4d %4d]\n", (int)-num-1, (int)num);
	num = (signed short)((unsigned short)~0 >> 1);
	printf("signed short [%6d %6d]\n", (int)-num-1, (int)num);
	num = (signed int)((unsigned int)~0 >> 1);
	printf("signed int [%11d %11d]\n", (int)-num-1, (int)num);
	num = (signed long)((unsigned long)~0 >> 1);
	printf("signed long [%20ld %20ld]\n", -num-1, num);
	printf("----------------------------------------------------\n");

	num = ((unsigned char)~0);/* ~0: convert to all 1's and limit to max unsigned char by typecast */
	printf("unsigned char [%u %4u]\n", 0, (unsigned int)num);
	num = ((unsigned short)~0);
	printf("unsigned short [%u %6u]\n", 0, (unsigned int)num);
	num = ((unsigned int)~0);
	printf("unsigned int [%u %11u]\n", 0, (unsigned int)num);
	num = ((unsigned long)~0);
	printf("unsigned long [%u %20lu]\n", 0, num);
	printf("----------------------------------------------------\n");

	return 0;
}

