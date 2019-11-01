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
