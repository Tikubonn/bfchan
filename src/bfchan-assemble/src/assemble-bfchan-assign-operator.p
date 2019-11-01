
/*
	ASSIGN 命令は即値を現在位置に書き込む命令です。

	movb $0xff, %al
	movb %al, (%ebx)

	b0 ??
	88 03
*/

static char BFCHAN_ASSIGN_OPERATOR_ASSEMBLY1[] = { 0xb0 };
static char BFCHAN_ASSIGN_OPERATOR_ASSEMBLY2[] = { 0x88, 0x03 };
