#include <stdio.h>

#ifndef SNUM
	#define SNUM 5
#endif

#ifndef LEN
	#define LEN 0xFFFF
#endif

int v[LEN];

int binsearch(int x, int v[], int n);

main()
{
	int i, n, x;

	n = LEN;
	/* v[] in increasing order */
	for (i = 0; i < n; i++)
		v[i] = i;

	x = SNUM;
	printf ("%d position in v[] : %d\n", x, binsearch(x, v, n));
	return 0;
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
	int low, mid, high;

	low = 0;
	high = n - 1;

	while (low <= high) {
		mid = (low + high)/2;	/* to get middle index */
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;	/* no match */
}
