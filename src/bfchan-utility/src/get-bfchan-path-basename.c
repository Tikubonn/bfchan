#include <bfchan.h>
#include <stddef.h>
#include <stdbool.h>

static void position_slash (char *path, size_t *beginp){
  size_t begin = 0;
  size_t index = 0;
  char *seq = path;
  while (*seq != '\0'){
    if (*seq == '\\'){
      begin = index +1;
    }
    else
    if (*seq == '/'){
      begin = index +1;
    }
    index++;
    seq++;
  }
  *beginp = begin;
}

static void position_dot (char *path, size_t *sizep){
  size_t size = 0;
  size_t index = 0;
  char *seq = path;
  while (*seq != '\0'){
    if (*seq == '.'){
      size = index;
    }
    index++;
    seq++;
  }
  *sizep = size;
}

void get_bfchan_path_basename (char *path, size_t *beginp, size_t *endp){
  size_t begin;
  position_slash(path, &begin);
  size_t si;
  position_dot(path + begin, &si);
  *beginp = begin;
  *endp = begin + si;
}
