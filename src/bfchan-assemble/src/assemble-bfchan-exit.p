
/*
  leave
  movl $0, %eax
  ret
  
  c9
  b8 00 00 00 00
  c3
*/

static char BFCHAN_EXIT_ASSEMBLY[] = {
  0xc9,
  0xb8, 0x00, 0x00, 0x00, 0x00,
  0xc3
};
