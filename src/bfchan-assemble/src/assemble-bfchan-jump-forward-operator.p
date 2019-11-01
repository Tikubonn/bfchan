
/*
	movb (%ebx), %al
	testb %al, %al
	jz then
	
	8a 03
	84 c0
	0f 84 ?? ?? ?? ?? 
*/

static char BFCHAN_JUMP_FORWARD_OPERATOR_ASSEMBLY[] = { 0x8a, 0x03, 0x84, 0xc0, 0x0f, 0x84 };
