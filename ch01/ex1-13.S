/* Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging */
/* This IA32 code, can be compiled using multilib. If you havent installed gcc multilib, please do so.
 * I have written compile_ex1-13.sh to do the job for you. 
 * Use case:
 * $ cat ex1-13.S | ./a.out
 * */

.include "defines.s"

.equ EOF, -1
.equ MAX_WORD_LEN, 255
.equ BAR_CHAR, '|'
.equ SPACE_CHAR, ' '
.equ TAB_CHAR, '\t'
.equ NEWLINE_CHAR, '\n'

.section .rodata
	newline:
		.string "\n"
	fig1:
		.string "\n                Fig1: Histogram : Horizontal Bars                     \n"
        fig1_underline:
		.string "                ---------------------------------                     \n"
	fmt_y_axix_num:
		.string	"%2d "
	fmt_x_axix_num:
		.string	"%2d "
	fmt_bar_char:
		.string	"%c "
	fmt_hist_value:
		.string	" %d\n"

	fig2:
		.string "\n                Fig2: Histogram : Vertical Bars                     \n"
        fig2_underline:
		.string "                -------------------------------                     \n"
	fmt_bar_char_fig2:
		.string	" %c "
	three_spaces:
		.string	"   "
	
.section .text
	.globl main
	.type main, @function

.equ c, loc1
.equ i, loc2
.equ j, loc3
.equ word_len, loc4
.equ max_word_len, loc5
.equ max_occurrence_value, loc6
.equ current_occurrence, loc7
.equ word_histogram, loc8
.equ tmp, loc9

main:
	# pro-logue
	pushl	%ebp		# push prev ebp value to stack
	movl	%esp, %ebp	# ebp = esp

	# align esp to 16 byte boundary address
	andl	$-16, %esp	# -16d = 0xFFFF FFF0
	# create local storage of 2048 bytes
	subl	$2048, %esp

	# initialize local variables to 0
	movl	$0, c(%ebp)
	movl	$0, i(%ebp)
	movl	$0, j(%ebp)
	movl	$0, word_len(%ebp)
	movl	$0, max_word_len(%ebp)
	movl	$0, max_occurrence_value(%ebp)
	movl	$0, current_occurrence(%ebp)

	# word_histogram = calloc(MAX_WORD_LEN, 4)
	movl	$MAX_WORD_LEN, p1(%esp)
	movl	$4, p2(%esp)
	call	calloc
	cmpl	$0, %eax
	je 	error_out
	movl	%eax, word_histogram(%ebp)	

	# while ((c = getchar()) != EOF)
	jmp	while_cond
while:
	movl	c(%ebp), %eax
	#if(c == ' ' || c == '\t' || c == '\n')
	cmpl	$SPACE_CHAR, %eax
	je	process_whitespace
	cmpl	$TAB_CHAR, %eax
	je	process_whitespace
	cmpl	$NEWLINE_CHAR, %eax
	je	process_whitespace
	# else ++word_len
	addl	$1, word_len(%ebp)
	jmp	while_cond

	process_whitespace:
		movl	word_histogram(%ebp), %ebx
		movl	word_len(%ebp), %ecx		# ecx = word_len
		movl	(%ebx, %ecx, 4), %eax		# eax = word_histogram[word_len]
		addl	$1, %eax			# eax = eax + 1
		movl	%eax, (%ebx, %ecx, 4)		# word_histogram[word_len] = eax

		# if (max_occurrence_value < word_histogram[word_len] && word_len != 0)
		cmpl	$0, %ecx
		je	next1
		cmpl	%eax, max_occurrence_value(%ebp)
		jge	next1
		movl	%eax, max_occurrence_value(%ebp)

	next1:
		# if (max_word_len < word_len)
		cmpl	%ecx, max_word_len(%ebp)
		jge	next2
		movl	%ecx, max_word_len(%ebp)	# max_word_len = word_len

	next2:
		movl	$0, word_len(%ebp)
		
while_cond:
	call	getchar
	movl	%eax, c(%ebp)
	cmpl	$EOF, %eax
	jne	while
	
	# print horizontal bar histogram
	# for (i = 1; i < max_word_len; ++i)
	movl	$1, i(%ebp)
	jmp	for_hor_cond
for_hor:
	movl	$fmt_y_axix_num, p1(%esp)	
	movl	i(%ebp), %ecx
	movl	%ecx, p2(%esp)
	call	printf

	# for (j = 0; j < word_histogram[i]; ++j)
	movl	$0, j(%ebp)
	jmp	for_hor_inner_cond

	for_hor_inner:
		# printf("%c ", BAR_CHAR);
		movl	$fmt_bar_char, p1(%esp)
		movl	$BAR_CHAR, p2(%esp)
		call	printf
		addl 	$1, j(%ebp)

	for_hor_inner_cond:
		movl	i(%ebp), %edx			# edx = i
		movl	word_histogram(%ebp), %ebx
		movl	(%ebx, %edx, 4), %edx
		cmpl	%edx, j(%ebp)
		jl	for_hor_inner
	
	# printf(" %d\n", word_histogram[i]);
	movl	$fmt_hist_value, p1(%esp)
	movl	%edx, p2(%esp)
	call	printf

	addl	$1, i(%ebp)	# ++i
for_hor_cond:
	movl	i(%ebp), %ecx			# ecx = i
	cmpl	max_word_len(%ebp), %ecx
	jle	for_hor

	# printf("\n                Fig1: Histogram : Horizontal Bars                     \n");
	movl	$fig1, p1(%esp)
	call	printf
	# printf("                  ---------------------------------                     \n");
	movl	$fig1_underline, p1(%esp)
	call	printf

	movl	$newline, p1(%esp)
	call	printf
	# print vertical vertical bars
	# for (i = 0; i < max_occurrence_value; ++i)	
	movl	max_occurrence_value(%ebp), %eax	# current_occurrence = max_occurrence_value;
	movl	%eax, current_occurrence(%ebp)
	movl	$0, i(%ebp)
	jmp	for_vert_cond
for_vert:
	# printf("%2d ", current_occurrence); 
	movl	$fmt_y_axix_num, p1(%esp)
	movl	current_occurrence(%ebp), %eax
	movl	%eax, p2(%esp)
	call	printf

	# for (j = 1; j < max_word_len; ++j)
	movl	$1, j(%ebp)
	jmp	for_vert_inner_cond
	for_vert_inner:
		# if (word_histogram[j] == current_occurrence)
		movl	j(%ebp), %ecx
		movl	word_histogram(%ebp), %ebx
		movl	(%ebx, %ecx, 4), %eax
		cmpl	current_occurrence(%ebp), %eax
		jl	fvi_next1
		# printf(" %c ", BAR_CHAR);			
		movl	$fmt_bar_char_fig2, p1(%esp)
		movl	$BAR_CHAR, p2(%esp)
		call	printf
		jmp	fvi_next2
	fvi_next1:
		movl	$three_spaces, p1(%esp)
		call 	printf
	fvi_next2:
		addl	$1, j(%ebp)
	for_vert_inner_cond:
		movl	j(%ebp), %ecx
		cmpl	max_word_len(%ebp), %ecx
		jle	for_vert_inner
	
	movl	$newline, p1(%esp)
	call	printf
	subl	$1, current_occurrence(%ebp)	# --current_occurrence
	addl	$1, i(%ebp)			# ++i

for_vert_cond:
	movl	i(%ebp), %ecx
	cmpl	max_occurrence_value(%ebp), %ecx
	jl	for_vert

	# print x axis for fig2
	movl	$three_spaces, p1(%esp)
	call 	printf
	# for (i = 1; i < max_word_len; ++i)
	movl	$1, i(%ebp)
	jmp	for_print_x_axis_fig2_cond
for_print_x_axis_fig2:
	movl	$fmt_x_axix_num, p1(%esp)
	movl	%ecx, p2(%esp)
	call	printf
	addl	$1, i(%ebp)
for_print_x_axis_fig2_cond:
	movl	i(%ebp), %ecx
	cmpl	max_word_len(%ebp), %ecx
	jle	for_print_x_axis_fig2

	movl	$newline, p1(%esp)
	call	printf
	
	# printf("\n                Fig2: Histogram : Vertical Bars                    \n");
	movl	$fig2, p1(%esp)
	call	printf
	# printf("\n                -------------------------------                     \n");
	movl	$fig2_underline, p1(%esp)
	call	printf


	# free(word_histogram)
	movl	word_histogram(%ebp), %ebx
	movl 	%ebx, p1(%esp)
	call	free

	# exit(0)
	movl	$EXIT_SUCCESS, p1(%esp)	# push 0 to stack
	jmp 	out
error_out:
	movl	$EXIT_FAILURE, %eax
out:
	call	exit
