
/*
	この処理系では EOF を読み込んだ場合に 0 を現在位置に書き出します。

	call _getchar
	cmpl $-1, %eax
	jne nonzero
zero:
	xor %eax, %eax
nonzero:
	movb %al, (%ebx)
	
	e8 ?? ?? ?? ?? ;; call _getchar
	83 f8 ff
	75 02
	31 c0 
	88 03
*/

static char BFCHAN_GET_OPERATOR_ASSEMBLY1[] = { 0xe8 };
static char BFCHAN_GET_OPERATOR_ASSEMBLY2[] = { 0x83, 0xf8, 0xff, 0x75, 0x02, 0x31, 0xc0, 0x88, 0x03 };
