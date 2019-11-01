#pragma once
#include <stddef.h>

typedef enum bfchan_operator_type {
	BFCHAN_INC_OPERATOR,
	BFCHAN_DEC_OPERATOR,
	BFCHAN_CALCULATION_OPERATOR, // opt
	BFCHAN_INC_ADDR_OPERATOR,
	BFCHAN_DEC_ADDR_OPERATOR,
	BFCHAN_CALCULATION_ADDR_OPERATOR, // opt
	BFCHAN_PUT_OPERATOR,
	BFCHAN_GET_OPERATOR,
	BFCHAN_JUMP_FORWARD_OPERATOR,
	BFCHAN_JUMP_BACKWARD_OPERATOR,
	BFCHAN_ZERO_CLEAR_OPERATOR, // opt
	BFCHAN_ASSIGN_OPERATOR, // opt
	BFCHAN_GET_PUT_OPERATOR, // opt
	BFCHAN_JUMP_FORWARD_MARKER, // opt (do not jump mark only)
	BFCHAN_JUMP_BACKWARD_MARKER, // opt (do not jump mark only)
} bfchan_operator_type;

typedef struct bfchan_calculation_operator {
	int value;
} bfchan_calculation_operator;

typedef struct bfchan_jump_operator {
	size_t offset;
	size_t offsetbegin;
	size_t offsetend;
	size_t size;
} bfchan_jump_operator;

typedef struct bfchan_operator {
	bfchan_operator_type type;
	union {
		bfchan_calculation_operator calculation;
		bfchan_jump_operator jump;
	} operator;
} bfchan_operator;

typedef struct bfchan_operator_list {
	bfchan_operator *sequence;
	size_t seek;
	size_t size;
} bfchan_operator_list;

#define BFCHAN_SYMNAME_LENGTH 128

typedef struct bfchan_symname {
	char sequence[BFCHAN_SYMNAME_LENGTH];
	size_t size;
} bfchan_symname;

typedef enum bfchan_target {
	BFCHAN_TARGET_APPLICATION,
	BFCHAN_TARGET_CFUNC
} bfchan_target;

typedef struct bfchan {
	bfchan_target target;
	bfchan_symname symname;
	size_t symgetchar;
	size_t symputchar;
	size_t workingmemorysize;
	bfchan_operator_list operator_list;
	bfchan_operator_list opt_operator_list;
} bfchan;
