
/*
	現在位置の値を 0 に初期化するアセンブリです。

	movb (%ebx), %al
	xor %al, %al
	movb %al, (%ebx)

	8a 03
	30 c0
	88 03
*/

static char BFCHAN_ZERO_CLEAR_OPERATOR_ASSEMBLY[] = {	0x8a, 0x03, 0x30, 0xc0, 0x88, 0x03 };
