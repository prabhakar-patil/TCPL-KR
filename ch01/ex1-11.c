/* How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any?*/
/* Answer to qeustion 1: 
 * $ cat ex1-11.c | ./a.out 
 * Compare with following and both shall provide same result
 * $ cat ex1-11.c | wc
 * */

#include <stdio.h>

#define IN 1   /*Inside a word*/ 
#define OUT 0  /*Outside a word*/

main()
{
	int c;
	int nc, nl, nw;
	int state;

	state = OUT;
	nc = nl = nw = 0;

	while ((c = getchar()) != EOF) {
		++nc; // there is new character
		if(c == '\n')
			++nl;
		if(c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT) {
			++nw;
			state = IN;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);
}
