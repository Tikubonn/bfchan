#include <bfchan.h>
#include <nanafy.h>
#include "assemble-bfchan-exit.p"

nanafy_status assemble_bfchan_exit_manually (bfchan *bfchanp, nanafy *nana){
	nanafy_status status;
	status = write_nanafy_manually(BFCHAN_EXIT_ASSEMBLY, sizeof(BFCHAN_EXIT_ASSEMBLY), NANAFY_TEXT_SECTION, nana);
	if (status != NANAFY_SUCCESS){
		return NANAFY_ERROR;
	}
	return NANAFY_SUCCESS;
}
