#include <stddef.h>

static size_t strlength (char *sequence){
	size_t length = 0;
	char *seq = sequence;
	while (*seq != '\0'){
		length++;
		seq++;
	}
	return length;
}

void get_bfchan_path_dir_and_basename (char *path, size_t *beginp, size_t *endp){
	size_t length = strlength(path);
	size_t end = length == 0 ? 0 : length;
	for (size_t index = length; 0 < index--;){
		if (path[index] == '/' || 
			 	path[index] == '\\'){
			break;
		}
		else
		if (path[index] == '.'){
			end = index;
		}
	}
	*beginp = 0;
	*endp = end;
}
