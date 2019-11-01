#include <bfchan.h>
#include <nanafy.h>
#include <stddef.h>
#include "assemble-bfchan-init-for-cfunc.p"

int assemble_bfchan_init_for_cfunc (bfchan *bfchanp, nanafy *nana){
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
		char *sequence;
		size_t size;
		bfchan_symname_name(&(bfchanp->symname), &sequence, &size);
		size_t symid;
		if (register_nanafy_symbol(sequence, size, NANAFY_TEXT_SECTION, nana, &symid) != 0){
			return 1;
		}
	}
	// *init 
	if (write_nanafy(BFCHAN_INIT_ASSEMBLY_FOR_CFUNC, sizeof(BFCHAN_INIT_ASSEMBLY_FOR_CFUNC), NANAFY_TEXT_SECTION, nana) != 0){
		return 1;
	}
	return 0;
}
