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
#include <stddef.h>

extern int add_bfchan_operator_list_manually (bfchan_operator*, bfchan_operator_list*);
#include <stddef.h>

extern int add_bfchan_operator_list (bfchan_operator*, bfchan_operator_list*);
#include <stddef.h>

extern int copy_bfchan_operator_list (bfchan_operator_list*, bfchan_operator_list*);
#include <stddef.h>

extern int extend_bfchan_operator_list (size_t, bfchan_operator_list*);

extern void free_bfchan_operator_list (bfchan_operator_list*);
#include <stddef.h>

extern int get_bfchan_operator_list (size_t, bfchan_operator_list*, bfchan_operator*);
#include <stddef.h>

void init_bfchan_operator_list (bfchan_operator*, size_t, bfchan_operator_list*);
#include <stddef.h>

extern size_t bfchan_operator_list_length (bfchan_operator_list*);
#include <stddef.h>

extern void clear_bfchan_operator_list (bfchan_operator_list*);
#include <stddef.h>

extern int set_bfchan_operator_list (bfchan_operator*, size_t, bfchan_operator_list*);
#include <stddef.h>

extern int optimize_bfchan_assign_operator (size_t, bfchan_operator_list*, bfchan_operator_list*, size_t*);
#include <stddef.h>

extern int optimize_bfchan_calculation_addr_operator (size_t, bfchan_operator_list*, bfchan_operator_list*, size_t*);
#include <stddef.h>

extern int optimize_bfchan_calculation_operator (size_t, bfchan_operator_list*, bfchan_operator_list*, size_t*);
#include <stddef.h>

extern int optimize_bfchan_zero_clear_operator (size_t, bfchan_operator_list*, bfchan_operator_list*, size_t*);

extern int optimize_bfchan_operator (bfchan_operator_list*, bfchan_operator_list*);
#include <stddef.h>

extern int optimize_bfchan_jump_forward_operator (size_t, bfchan_operator_list*, bfchan_operator_list*, size_t*);
#include <stddef.h>

extern int optimize_bfchan_jump_backward_operator (size_t, bfchan_operator_list*, bfchan_operator_list*, size_t*);
#include <nanafy.h>

extern nanafy_status assemble_bfchan_assign_operator_manually (bfchan_operator*, bfchan*, nanafy*);
#include <nanafy.h>

extern int assemble_bfchan_assign_operator (bfchan_operator*, bfchan*, nanafy*);
#include <nanafy.h>

extern nanafy_status assemble_bfchan_calculation_operator_manually (bfchan_operator*, bfchan*, nanafy *nana);
#include <nanafy.h>

extern int assemble_bfchan_calculation_operator (bfchan_operator*, bfchan*, nanafy*);
#include <nanafy.h>

extern nanafy_status assemble_bfchan_dec_operator_manually (bfchan_operator*, bfchan*, nanafy*);
#include <nanafy.h>

extern int assemble_bfchan_dec_operator (bfchan_operator*, bfchan*, nanafy*);
#include <nanafy.h>

extern nanafy_status assemble_bfchan_get_operator_manually (bfchan_operator*, bfchan*, nanafy*);
#include <nanafy.h>

extern int assemble_bfchan_get_operator (bfchan_operator*, bfchan*, nanafy*);
#include <nanafy.h>

extern nanafy_status assemble_bfchan_inc_operator_manually (bfchan_operator*, bfchan*, nanafy*);
#include <nanafy.h>

extern int assemble_bfchan_inc_operator (bfchan_operator*, bfchan*, nanafy*);
#include <nanafy.h>

extern nanafy_status assemble_bfchan_jump_backward_operator_manually (bfchan_operator*, bfchan*, nanafy*);
#include <nanafy.h>

extern int assemble_bfchan_jump_backward_operator (bfchan_operator*, bfchan*, nanafy*);
#include <nanafy.h>

extern nanafy_status assemble_bfchan_jump_forward_operator_manually (bfchan_operator*, bfchan*, nanafy*);
#include <nanafy.h>

extern int assemble_bfchan_jump_forward_operator (bfchan_operator*, bfchan*, nanafy*);
#include <nanafy.h>

extern nanafy_status assemble_bfchan_operator_manually (bfchan_operator*, bfchan*, nanafy*);
#include <nanafy.h>

extern int assemble_bfchan_operator (bfchan_operator*, bfchan*, nanafy*);
#include <nanafy.h>

extern nanafy_status assemble_bfchan_put_operator_manually (bfchan_operator*, bfchan*, nanafy*);
#include <nanafy.h>

extern int assemble_bfchan_put_operator (bfchan_operator*, bfchan*, nanafy*);
#include <nanafy.h>

extern nanafy_status assemble_bfchan_zero_clear_operator_manually (bfchan_operator*, bfchan*, nanafy*);
#include <nanafy.h>

extern int assemble_bfchan_zero_clear_operator (bfchan_operator*, bfchan*, nanafy*);
#include <nanafy.h>

extern nanafy_status assemble_bfchan_dec_addr_operator_manually (bfchan_operator*, bfchan*, nanafy*);
#include <nanafy.h>

extern int assemble_bfchan_dec_addr_operator (bfchan_operator*, bfchan*, nanafy*);
#include <nanafy.h>

extern nanafy_status assemble_bfchan_inc_addr_operator_manually (bfchan_operator*, bfchan*, nanafy*);
#include <nanafy.h>

extern int assemble_bfchan_inc_addr_operator (bfchan_operator*, bfchan*, nanafy*);
#include <nanafy.h>

extern int assemble_bfchan_init (bfchan*, nanafy*);
#include <nanafy.h>

extern int assemble_bfchan_init_manually (bfchan*, nanafy*);
#include <nanafy.h>

extern int assemble_bfchan_exit (bfchan *bfchanp, nanafy *nana);
#include <nanafy.h>

extern nanafy_status assemble_bfchan_exit_manually (bfchan*, nanafy*);
#include <nanafy.h>

extern int fix_bfchan_jump_operator (bfchan*, nanafy*);
#include <nanafy.h>

extern nanafy_status assemble_bfchan_calculation_addr_operator_manually (bfchan_operator*, bfchan*, nanafy *nana);
#include <nanafy.h>

extern int assemble_bfchan_calculation_addr_operator (bfchan_operator*, bfchan*, nanafy*);
#include <nanafy.h>

extern int assemble_bfchan_jump_backward_marker (bfchan_operator*, bfchan*, nanafy*);
#include <nanafy.h>

extern nanafy_status assemble_bfchan_jump_backward_marker_manually (bfchan_operator*, bfchan*, nanafy*);
#include <nanafy.h>

extern int assemble_bfchan_jump_forward_marker (bfchan_operator*, bfchan*, nanafy*);
#include <nanafy.h>

extern nanafy_status assemble_bfchan_jump_forward_marker_manually (bfchan_operator*, bfchan*, nanafy*);
#include <nanafy.h>

extern nanafy_status assemble_bfchan_manually (bfchan*, nanafy*);
#include <nanafy.h>

extern int assemble_bfchan (bfchan*, nanafy*);

extern void free_bfchan (bfchan*);
#include <stddef.h>

extern void init_bfchan (bfchan_target, bfchan_symname*, bfchan_operator*, size_t, bfchan_operator*, size_t, size_t, bfchan*);
#include <stddef.h>

extern bfchan *make_bfchan (bfchan_target, bfchan_symname*, size_t, size_t);

extern int optimize_bfchan (bfchan*);

extern int put_bfchan_manually (char, bfchan*);

extern int put_bfchan (char, bfchan*);
#include <stddef.h>

extern int remap_bfchan_operator_list (bfchan_operator*, size_t, bfchan*);
#include <stddef.h>

extern int remap_bfchan_opt_operator_list (bfchan_operator*, size_t, bfchan*);
#include <stddef.h>

void get_bfchan_path_basename (char *path, size_t *beginp, size_t *endp);
#include <stddef.h>

extern void get_bfchan_path_dir_and_basename (char*, size_t*, size_t*);
#include <stddef.h>

extern void bfchan_symname_basename (bfchan_symname*, char**, size_t*);
#include <stddef.h>

extern void bfchan_symname_name (bfchan_symname*, char**, size_t*);
#include <stddef.h>

extern int init_bfchan_symname (char*, size_t, bfchan_symname*);

extern void copy_bfchan_symname (bfchan_symname*, bfchan_symname*);

extern int assemble_bfchan_init_for_cfunc (bfchan*, nanafy*);

extern nanafy_status assemble_bfchan_init_for_cfunc_manually (bfchan*, nanafy*);
#include <stddef.h>

extern void read_bfchan_cheader (void*, size_t, size_t, char*, size_t, size_t*);
