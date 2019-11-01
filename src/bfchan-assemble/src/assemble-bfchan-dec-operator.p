
/*
	movb (%ebx), %al
	decb %al
	movb %al, (%ebx)

	8a 03
	fe c8
	88 03
*/

static char BFCHAN_DEC_OPERATOR_ASSEMBLY[] = { 0x8a, 0x03, 0xfe, 0xc8, 0x88, 0x03 };
