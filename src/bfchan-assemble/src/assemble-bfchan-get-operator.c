#include <bfchan.h>
#include <nanafy.h>
#include "assemble-bfchan-get-operator.p"

int assemble_bfchan_get_operator (bfchan_operator *operator, bfchan *bfchanp, nanafy *nana){
	if (write_nanafy(BFCHAN_GET_OPERATOR_ASSEMBLY1, sizeof(BFCHAN_GET_OPERATOR_ASSEMBLY1), NANAFY_TEXT_SECTION, nana) != 0){
		return 1;
	}
	if (put_nanafy_external_relative_offset(bfchanp->symgetchar, NANAFY_TEXT_SECTION, 4, nana) != 0){
		return 1;
	}
	if (write_nanafy(BFCHAN_GET_OPERATOR_ASSEMBLY2, sizeof(BFCHAN_GET_OPERATOR_ASSEMBLY2), NANAFY_TEXT_SECTION, nana) != 0){
		return 1;
	}
	return 0;
}
