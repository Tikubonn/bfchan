
/*
	movb (%ebx), %al
	incb %al
	movb %al, (%ebx)
	
	8a 03
	fe c0
	88 03
*/

static char BFCHAN_INC_OPERATOR_ASSEMBLY[] = { 0x8a, 0x03, 0x0fe, 0xc0, 0x88, 0x03 };
