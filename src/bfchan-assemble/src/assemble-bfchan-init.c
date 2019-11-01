#include <bfchan.h>
#include <nanafy.h>
#include <stddef.h>
#include "assemble-bfchan-init.p"

int assemble_bfchan_init (bfchan *bfchanp, nanafy *nana){
	// *working-memory
	size_t symworkingmemory;
	{
		if (register_nanafy_private_symbol(BFCHAN_INIT_WORKING_MEMORY, sizeof(BFCHAN_INIT_WORKING_MEMORY) -1, NANAFY_BSS_SECTION, nana, &symworkingmemory) != 0){
			return 1;
		}
	}
	// *putchar
	{
		size_t symid;
		if (register_nanafy_external_symbol(BFCHAN_INIT_PUTCHAR, sizeof(BFCHAN_INIT_PUTCHAR) -1, nana, &symid) != 0){
			return 1;
		}
		bfchanp->symputchar = symid;
	}
	// *getchar
	{
		size_t symid;
		if (register_nanafy_external_symbol(BFCHAN_INIT_GETCHAR, sizeof(BFCHAN_INIT_GETCHAR) -1, nana, &symid) != 0){
			return 1;
		}
		bfchanp->symgetchar = symid;
	}
	// *main
	{
		char *symseq;
		size_t symsize;
		bfchan_symname_name(&(bfchanp->symname), &symseq, &symsize);
		size_t symid;
		if (register_nanafy_symbol(symseq, symsize, NANAFY_TEXT_SECTION, nana, &symid) != 0){
			return 1;
		}
	}
	// *init 
	allocate_nanafy(bfchanp->workingmemorysize, NANAFY_BSS_SECTION, nana);
	if (write_nanafy(BFCHAN_INIT_ASSEMBLY, sizeof(BFCHAN_INIT_ASSEMBLY), NANAFY_TEXT_SECTION, nana) != 0){
		return 1;
	}
	if (put_nanafy_external_offset(symworkingmemory, NANAFY_TEXT_SECTION, 4, nana) != 0){
		return 1;
	}
	return 0;
}
