#include <bfchan.h>
#include <nanafy.h>
#include "assemble-bfchan-exit.p"

int assemble_bfchan_exit (bfchan *bfchanp, nanafy *nana){
	if (write_nanafy(BFCHAN_EXIT_ASSEMBLY, sizeof(BFCHAN_EXIT_ASSEMBLY), NANAFY_TEXT_SECTION, nana) != 0){
		return 1;
	}
	return 0;
}
