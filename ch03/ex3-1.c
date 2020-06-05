/* Exercise 3-1. Our binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside.) Write a version with only one test inside the loop and measure the difference in run-time. */
#include <stdio.h>

#ifndef SNUM
#define SNUM 2047
#endif

#ifndef LEN
#define LEN 0xFFFF
#endif

int v[LEN];

int binsearch(int x, int v[], int n);

main()
{
	int i, x, n;

	n = LEN;
	for (i = 0; i < n; i++)
		v[i] = i;

	x = SNUM;
	printf("%d is at index [%d]\n", x, binsearch(x, v, n));
	return 0;
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
	int low, mid, high;

	low = 0;
	high = n - 1;

	mid = (low+high)/2;
	while (low <= high && x != v[mid]) {
		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
		mid = (low+high)/2;
	}

	if (x == v[mid])
		return mid;
	else
		return -1;
}
