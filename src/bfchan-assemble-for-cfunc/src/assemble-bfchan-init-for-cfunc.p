
#define BFCHAN_INIT_PUTCHAR "_putchar"
#define BFCHAN_INIT_GETCHAR "_getchar"

/*
	このアセンブリは BFCHAN_INIT_ASSEMBLY とは異なり
	渡された第一引数を計算用のバッファとして利用します。
	
  pushl %ebp
  movl %esp, %ebp
  movl 8(%esp), %ebx
  
  55
  89 e5
  8b 5c 24 08
*/

static char BFCHAN_INIT_ASSEMBLY_FOR_CFUNC[] = {
  0x55,
  0x89, 0xe5,
  0x8b, 0x5c, 0x24, 0x08
};
