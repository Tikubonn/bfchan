#include <bfchan.h>
#include <nanafy.h>
#include <stddef.h>
#include "assemble-bfchan-init-for-cfunc.p"

nanafy_status assemble_bfchan_init_for_cfunc_manually (bfchan *bfchanp, nanafy *nana){
	// *putchar
	{
		size_t symid;
		nanafy_status status = register_nanafy_external_symbol_manually(BFCHAN_INIT_PUTCHAR, sizeof(BFCHAN_INIT_PUTCHAR) -1, nana, &symid);
		if (status != NANAFY_SUCCESS){
			return status;
		}
		bfchanp->symputchar = symid;
	}
	// *getchar
	{
		size_t symid;
		nanafy_status status = register_nanafy_external_symbol_manually(BFCHAN_INIT_GETCHAR, sizeof(BFCHAN_INIT_GETCHAR) -1, nana, &symid);
		if (status != NANAFY_SUCCESS){
			return status;
		}
		bfchanp->symgetchar = symid;
	}
	// *main
	{
		char *sequence;
		size_t size;
		bfchan_symname_name(&(bfchanp->symname), &sequence, &size);
		size_t symid;
		nanafy_status status = register_nanafy_symbol_manually(sequence, size, NANAFY_TEXT_SECTION, nana, &symid);
		if (status != NANAFY_SUCCESS){
			return status;
		}
	}
	// *init 
	nanafy_status status = write_nanafy_manually(BFCHAN_INIT_ASSEMBLY_FOR_CFUNC, sizeof(BFCHAN_INIT_ASSEMBLY_FOR_CFUNC), NANAFY_TEXT_SECTION, nana);
	if (status != NANAFY_SUCCESS){
		return status;
	}
	return NANAFY_SUCCESS;
}
