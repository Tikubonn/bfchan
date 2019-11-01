
/*
	movb (%ebx), %al
	testb %al, %al
	jnz then
	
	8a 03
	84 c0
	0f 85 ?? ?? ?? ?? 
*/

static char BFCHAN_JUMP_BACKWARD_OPERATOR_ASSEMBLY[] = { 0x8a, 0x03, 0x84, 0xc0, 0x0f, 0x85 };
