#include <bfchan.h>
#include <stddef.h>

static int calculation (bfchan_operator_list *listfrom, bfchan_operator_list *listto){
	clear_bfchan_operator_list(listto);
	size_t length = bfchan_operator_list_length(listfrom);
	for (size_t index = 0; index < length;){
		size_t next;
		if (optimize_bfchan_calculation_operator(index, listfrom, listto, &next) != 0){
			return 1;
		}
		index = next;
	}
	if (copy_bfchan_operator_list(listto, listfrom) != 0){
		return 1;
	}
	return 0;
}

static int calculation_addr (bfchan_operator_list *listfrom, bfchan_operator_list *listto){
	clear_bfchan_operator_list(listto);
	size_t length = bfchan_operator_list_length(listfrom);
	for (size_t index = 0; index < length;){
		size_t next;
		if (optimize_bfchan_calculation_addr_operator(index, listfrom, listto, &next) != 0){
			return 1;
		}
		index = next;
	}
	if (copy_bfchan_operator_list(listto, listfrom) != 0){
		return 1;
	}
	return 0;
}

static int zero_clear (bfchan_operator_list *listfrom, bfchan_operator_list *listto){
	clear_bfchan_operator_list(listto);
	size_t length = bfchan_operator_list_length(listfrom);
	for (size_t index = 0; index < length;){
		size_t next;
		if (optimize_bfchan_zero_clear_operator(index, listfrom, listto, &next) != 0){
			return 1;
		}
		index = next;
	}
	if (copy_bfchan_operator_list(listto, listfrom) != 0){
		return 1;
	}
	return 0;
}

static int assign (bfchan_operator_list *listfrom, bfchan_operator_list *listto){
	clear_bfchan_operator_list(listto);
	size_t length = bfchan_operator_list_length(listfrom);
	for (size_t index = 0; index < length;){
		size_t next;
		if (optimize_bfchan_assign_operator(index, listfrom, listto, &next) != 0){
			return 1;
		}
		index = next;
	}
	if (copy_bfchan_operator_list(listto, listfrom) != 0){
		return 1;
	}
	return 0;
}

static int jump_forward (bfchan_operator_list *listfrom, bfchan_operator_list *listto){
	clear_bfchan_operator_list(listto);
	size_t length = bfchan_operator_list_length(listfrom);
	for (size_t index = 0; index < length;){
		size_t next;
		if (optimize_bfchan_jump_forward_operator(index, listfrom, listto, &next) != 0){
			return 1;
		}
		index = next;
	}
	if (copy_bfchan_operator_list(listto, listfrom) != 0){
		return 1;
	}
	return 0;
}

static int jump_backward (bfchan_operator_list *listfrom, bfchan_operator_list *listto){
	clear_bfchan_operator_list(listto);
	size_t length = bfchan_operator_list_length(listfrom);
	for (size_t index = 0; index < length;){
		size_t next;
		if (optimize_bfchan_jump_backward_operator(index, listfrom, listto, &next) != 0){
			return 1;
		}
		index = next;
	}
	if (copy_bfchan_operator_list(listto, listfrom) != 0){
		return 1;
	}
	return 0;
}

int optimize_bfchan_operator (bfchan_operator_list *listfrom, bfchan_operator_list *listto){
	if (calculation(listfrom, listto) != 0){
		return 1;
	}
	if (calculation_addr(listfrom, listto) != 0){
		return 1;
	}
	if (zero_clear(listfrom, listto) != 0){
		return 1;
	}
	if (assign(listfrom, listto) != 0){
		return 1;
	}
	if (jump_forward(listfrom, listto) != 0){
		return 1;
	}
	if (jump_backward(listfrom, listto) != 0){
		return 1;
	}
	return 0;
}
