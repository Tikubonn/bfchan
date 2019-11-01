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
