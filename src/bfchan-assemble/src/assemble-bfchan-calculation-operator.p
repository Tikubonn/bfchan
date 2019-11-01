
/*
	movb (%ebx), %al
	addb $1, %al
	movb %al, (%ebx)

	8a 03
	04 ??
	88 03
*/

static char BFCHAN_CALCULATION_OPERATOR_ASSEMBLY1[] = { 0x8a, 0x03, 0x04 };
static char BFCHAN_CALCULATION_OPERATOR_ASSEMBLY2[] = { 0x88, 0x03 };
