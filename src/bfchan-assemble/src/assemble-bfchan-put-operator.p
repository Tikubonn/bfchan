
/*
	movb (%ebx), %al
	pushl %eax
	call _putchar
	addl $4, %esp
	cmpl $-1, %eax
	jne else 
error:
	movl $1, %eax
	leave
	ret
else:
	
	8a 03
	50
	e8 ?? ?? ?? ?? ;; call _putchar
	83 c4 04
	83 f8 ff
	75 07
	b8 01 00 00 00 
	c9 
	c3
*/

static char BFCHAN_PUT_OPERATOR_ASSEMBLY1[] = {
	0x8a, 0x03,
	0x50,
	0xe8
};

static char BFCHAN_PUT_OPERATOR_ASSEMBLY2[] = {
	0x83, 0xc4, 0x04,
	0x83, 0xf8, 0xff,
	0x75, 0x07,
	0xb8, 0x01, 0x00, 0x00, 0x00,
	0xc9,
	0xc3
};
