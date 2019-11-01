#include <bfchan.h>
#include <stddef.h>
#define LENGTHOF(source) (sizeof(source) -1)

static char HEADER_SOURCE1[] = "extern int __cdecl ";
static char HEADER_SOURCE2[] = " (char*);";

void read_bfchan_cheader (
  void *sequence, size_t size, 
	size_t offset, 
  char *symname, size_t symnamesize, 
  size_t *readsizep){
  size_t off = offset;
  // *header source1
  if (off < LENGTHOF(HEADER_SOURCE1)){
    size_t index;
    for (index = 0; off + index < LENGTHOF(HEADER_SOURCE1); index++){
      ((char*)sequence)[index] = HEADER_SOURCE1[off + index];
    }
    *readsizep = index;
    return;
  }
	off -= LENGTHOF(HEADER_SOURCE1);
  // *symname
  if (off < symnamesize){
    size_t index;
    for (index = 0; off + index < symnamesize; index++){
      ((char*)sequence)[index] = symname[off + index];
    }
    *readsizep = index;
    return;
  }
	off -= symnamesize;
  // *header source2
  if (off < LENGTHOF(HEADER_SOURCE2)){
    size_t index;
    for (index = 0; off + index < LENGTHOF(HEADER_SOURCE2); index++){
      ((char*)sequence)[index] = HEADER_SOURCE2[off + index];
    }
    *readsizep = index;
    return;
  }
	off -= LENGTHOF(HEADER_SOURCE2);
  // *eof
  *readsizep = 0;
  return;
}
