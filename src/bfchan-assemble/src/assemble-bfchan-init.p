
#define BFCHAN_INIT_MAIN "_main"
#define BFCHAN_INIT_PUTCHAR "_putchar"
#define BFCHAN_INIT_GETCHAR "_getchar"
#define BFCHAN_INIT_WORKING_MEMORY "working_memory"

/*
.data
	buffer:
		.space 65536
.text
	_main:
		pushl %ebp
		movl %esp, %ebp
		mov $buffer, %ebx
  
  55
  89 e5
	bb ?? ?? ?? ?? 
*/

static char BFCHAN_INIT_ASSEMBLY[] = { 
  0x55,
  0x89, 0xe5,
	0xbb
};
