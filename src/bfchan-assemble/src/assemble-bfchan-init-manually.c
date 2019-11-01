#include <bfchan.h>
#include <nanafy.h>
#include <stddef.h>
#include "assemble-bfchan-init.p"

int assemble_bfchan_init_manually (bfchan *bfchanp, nanafy *nana){
	// *working-memory
	size_t symworkingmemory;
	{
		nanafy_status status = register_nanafy_private_symbol_manually(BFCHAN_INIT_WORKING_MEMORY, sizeof(BFCHAN_INIT_WORKING_MEMORY) -1, NANAFY_BSS_SECTION, nana, &symworkingmemory);
		if (status != NANAFY_SUCCESS){
			return NANAFY_ERROR;
		}
	}
	// *putchar
	{
		size_t symid;
		nanafy_status status = register_nanafy_external_symbol_manually(BFCHAN_INIT_PUTCHAR, sizeof(BFCHAN_INIT_PUTCHAR) -1, nana, &symid);
		if (status != NANAFY_SUCCESS){
			return NANAFY_ERROR;
		}
		bfchanp->symputchar = symid;
	}
	// *getchar
	{
		size_t symid;
		nanafy_status status = register_nanafy_external_symbol_manually(BFCHAN_INIT_GETCHAR, sizeof(BFCHAN_INIT_GETCHAR) -1, nana, &symid);
		if (status != NANAFY_SUCCESS){
			return NANAFY_ERROR;
		}
		bfchanp->symgetchar = symid;
	}
	// *main
	{
		char *symseq;
		size_t symsize;
		bfchan_symname_name(&(bfchanp->symname), &symseq, &symsize);
		size_t symid;
		nanafy_status status = register_nanafy_symbol_manually(symseq, symsize, NANAFY_TEXT_SECTION, nana, &symid);
		if (status != NANAFY_SUCCESS){
			return NANAFY_ERROR;
		}
	}
	// *init
	allocate_nanafy(bfchanp->workingmemorysize, NANAFY_BSS_SECTION, nana);
	nanafy_status status;
	status = write_nanafy_manually(BFCHAN_INIT_ASSEMBLY, sizeof(BFCHAN_INIT_ASSEMBLY), NANAFY_TEXT_SECTION, nana);
	if (status != NANAFY_SUCCESS){
		return NANAFY_ERROR;
	}
	status = put_nanafy_external_offset_manually(symworkingmemory, NANAFY_TEXT_SECTION, 4, nana);
	if (status != NANAFY_SUCCESS){
		return NANAFY_ERROR;
	}
	return NANAFY_SUCCESS;
}
