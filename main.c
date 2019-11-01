#include <bfchan.h>
#include <nanafy.h>
#include <windows.h>
#include <stddef.h>
#include <stdbool.h>

static bool streq (char *sequence1, char *sequence2){
	char *seq1 = sequence1;
	char *seq2 = sequence2;
	while (1){
		if (*seq1 == '\0' && 
				*seq2 == '\0'){
			return true;
		}
		else 
		if (*seq1 != *seq2){
			return false;
		}
		seq1++;
		seq2++;
	}
	return false;
}

static size_t strlength (char *sequence){
	size_t length = 0;
	char *seq = sequence;
	while (*seq != '\0'){
		length++;
		seq++;
	}
	return length;
}

static int strtosize (char *sequence, size_t *sizep){
	size_t size = 0;
	char *seq = sequence;
	while (*seq != '\0'){
		if ('0' <= *seq && *seq <= '9'){
			size *= 10;
			size += *seq - '0';
		}
		else 
		if (*seq == 'G'){
			size *= 1073741824;
			break;
		}
		else
		if (*seq == 'M'){
			size *= 1048576;
			break;
		}
		else
		if (*seq == 'K'){
			size *= 1024;
			break;
		}
		else {
			return 1;
		}
		seq++;
	}
	*sizep = size;
	return 0;
}

static int make_cheader_path (char *path, char *sequence, size_t size){
	size_t begin;
	size_t end;
	get_bfchan_path_dir_and_basename(path, &begin, &end);
	if (end - begin +3 < size){
		for (size_t index = 0; index < end - begin; index++){
			sequence[index] = path[index + begin];
		}
		sequence[end - begin +0] = '.';
		sequence[end - begin +1] = 'h';
		sequence[end - begin +2] = '\0';
		return 0;
	}
	return 1;
}

static int make_cheader (char *path, bfchan_symname *symname){
	FILE *file = fopen(path, "wb");
	char *symseq;
	size_t symsize;
	bfchan_symname_basename(symname, &symseq, &symsize);
	size_t offset = 0;
	while (1){
		char buffer[1024];
		size_t readsize;
		read_bfchan_cheader(buffer, sizeof(buffer), offset, symseq, symsize, &readsize);
		if (readsize == 0){
			break;
		}
		else {
			if (fwrite(buffer, sizeof(char), readsize, file) != readsize){
				return 1;
			}
			offset += readsize;
		}
	}
	if (fclose(file) != 0){
		return 1;
	}
	return 0;
}

#define MAIN "main"

static int parse_args (
	int argcount, char **args,
	bfchan_symname *symname,
	bfchan_target *targetp,
	FILE **inputp,
	FILE **outputp,
	bool *optimizep,
	size_t *workingmemorysizep,
  nanafy_endian *endianp,
	bool *helpp,
	bool *versionp){
	if (init_bfchan_symname(MAIN, sizeof(MAIN) -1, symname) != 0){
		fprintf(stderr, "internal error, '%s' is too much long for symbol.\n", MAIN);
		return 1;
	}
	bfchan_target target = BFCHAN_TARGET_APPLICATION;
	FILE *input = stdin;
	FILE *output = stdout;
	char *inputfilename = NULL;
	char *outputfilename = NULL;
	bool optimize = true;
	bool compileascfuncp = false;
	size_t workingmemorysize = 65536;
  nanafy_endian endian = NANAFY_BIG_ENDIAN;
	bool help = false;
	bool version = false;
	size_t index = 1;
	while (index < argcount){
		if (streq(args[index], "-h") || 
			 	streq(args[index], "--help")){
			help = true;
			break;
		}
		else
		if (streq(args[index], "-v") || 
			 	streq(args[index], "--version")){
			version = true;
			break;
		}
    else 
    if (streq(args[index], "--endianness")){
      if (index +1 < argcount){
        if (streq(args[index +1], "little")){
          endian = NANAFY_LITTLE_ENDIAN;
          index += 2;
        }
        else 
        if (streq(args[index +1], "big")){
          endian = NANAFY_BIG_ENDIAN;
          index += 2;
        }
        else {
          fprintf(stderr, "error, unsupported endian type of '%s'.\n", args[index +1]);
          return 1;
        }
      }
      else {
        fprintf(stderr, "error, --endian option need a endian type.\n");
        return 1;
      }
    }
		else
		if (streq(args[index], "-O")){
			optimize = true;
			index += 1;
		}
		else
		if (streq(args[index], "-O0")){
			optimize = false;
			index += 1;
		}
		if (streq(args[index], "-m")){
			if (index +1 < argcount){
				size_t size;
				if (strtosize(args[index +1], &size) != 0){
					fprintf(stderr, "error, invaild size format of '%s'.\n", args[index]);
					return 1;
				}
				workingmemorysize = size;
				index += 1;
			}
			else {
				fprintf(stderr, "error, -m option need a size for working memory size.\n");
				return 1;
			}
		}
		else
		if (streq(args[index], "-c")){
			compileascfuncp = true;
			index += 1;
		}
		else
		if (streq(args[index], "-o")){
			if (index +1 < argcount){
				if (output == stdout){
					outputfilename = args[index +1];
					output = fopen(args[index +1], "wb");
					if (output == NULL){
						fprintf(stderr, "error, could not open file of '%s'.\n", args[index +1]);
						return 1;
					}
					index += 2;
				}
				else {
					fprintf(stderr, "error, another file was already opened for output.\n");
					return 1;
				}
			}
			else {
				fprintf(stderr, "error, -o option need a path for output.\n");
				return 1;
			}
		}
		else {
			if (input == stdin){
				inputfilename = args[index];
				input = fopen(args[index], "rb");
				if (input == NULL){
						fprintf(stderr, "error, could not open file of '%s'.\n", args[index +1]);
					return 1;
				}
				index += 1;
			}
			else {
				fprintf(stderr, "error, another file was already opened for input.\n");
				return 1;
			}
		}
	}
	if (compileascfuncp == true){
		if (inputfilename == NULL){
			fprintf(stderr, "-c option need a input file.\n");
			return 1; 
		}
		if (outputfilename == NULL){
			fprintf(stderr, "-c option need a output file.\n");
			return 1;
		}
		// *change the target
		target = BFCHAN_TARGET_CFUNC;
		// *setup symname
		size_t symbegin;
		size_t symend;
		get_bfchan_path_basename(inputfilename, &symbegin, &symend);
		if (init_bfchan_symname(inputfilename + symbegin, symend - symbegin, symname) != 0){
			fprintf(stderr, "error, file name of '%s' is too much long for symbol name.\n", inputfilename);
			return 1;
		}
		// *setup header path
		char headerpath[MAX_PATH];
		if (make_cheader_path(inputfilename, headerpath, sizeof(headerpath)) != 0){
			fprintf(stderr, "error, could not make a path of header file for C language.\n");
			return 1;
		}
		// *make header
		if (make_cheader(headerpath, symname) != 0){
			fprintf(stderr, "error, could not create header file for C language.\n");
			return 1;
		}
	}
	*targetp = target;
	*inputp = input;
	*outputp = output;
	*optimizep = optimize;
	*workingmemorysizep = workingmemorysize;
  *endianp = endian;
	*helpp = help;
	*versionp = version;
	return 0;
}

static void show_help (){
	printf(
		"Usage: bfchan [options] file\n"
		"Parameters:\n"
		"  file                       file path for input (default is standard input).\n"
		"Options:\n"
		"  -c                         compile as a function for C language.\n"
		"  -o file                    file path for output (default is standard output).\n"
		"  -O                         optimize assembly when compiling (default is enabled).\n"
		"  -O0                        not optimize assembly when compiling.\n"
		"  -m size                    change the working memory size (default is 65536). if -c option is enabled, this option will be ignored.\n"
    "  --endianness {little|big}  change the endian (default is big).\n"
		"  -h --help                  show the help then exit application.\n"
		"  -v --version               show the version then exit application.\n"
	);
}

static void show_version (){
	printf(
		"bfchan version 1.0.0\n"
	);
}

static int read_source (FILE *file, bfchan *bfchanp){
	while (1){
		int character = getc(file);
		if (character == EOF){
			break;
		}
		else {
			if (put_bfchan(character, bfchanp) != 0){
				fprintf(stderr, "error, error caused at parsing.\n");
				return 1;
			}
		}
	}
	return 0;
}

static int write_object_file (nanafy *nana, FILE *file){
	size_t offset = 0;
	while (1){
		char buffer[1024];
		size_t readsize;
		if (read_nanafy_product(buffer, sizeof(buffer), offset, nana, &readsize) != 0){
			return 1;
		}
		if (readsize == 0){
			break;
		}
		else {
			if (fwrite(buffer, sizeof(char), readsize, file) != readsize){
				fprintf(stderr, "error, error caused at writing.\n");
				return 1;
			}
			offset += readsize;
		}
	}
	return 0;
}

int main (int argcount, char **args){
	bfchan_symname symname;
	bfchan_target target;
	FILE *input;
	FILE *output;
	bool optimize;
	size_t workingmemorysize;
  nanafy_endian endian;
	bool help;
	bool version;
	if (parse_args(
		argcount, args,
		&symname,
		&target,
		&input, 
		&output,
		&optimize,
		&workingmemorysize,
    &endian,
		&help,
		&version) != 0){
		return 1;
	}
	if (help == true){
		show_help();
		return 0;
	}
	else
	if (version == true){
		show_version();
		return 0;
	}
	bfchan *bfchanp = make_bfchan(target, &symname, 0, workingmemorysize);
	if (bfchanp == NULL){
		fprintf(stderr, "internal error, could not make a bfchan instance.\n");
		return 1;
	}
	if (read_source(input, bfchanp) != 0){
		return 1;
	}
	nanafy_info nanainfo;
	setup_nanafy_info_for_x86(endian, &nanainfo);
	nanafy *nana = make_empty_nanafy(NANAFY_SYMNAME_TABLE_DEFAULT_HASH_FUNC, &nanainfo);
	if (nana == NULL){
		fprintf(stderr, "internal error, could not make a nanafy instance.\n");
		return 1;
	}
	if (optimize == true){
		if (optimize_bfchan(bfchanp) != 0){
			fprintf(stderr, "error, error caused at optimizing.\n");
			return 1;
		}
	}
	if (assemble_bfchan(bfchanp, nana) != 0){
		fprintf(stderr, "error, error caused at assembling.\n");
		return 1;
	}
	if (write_object_file(nana, output) != 0){
		return 1;
	}
	free_nanafy(nana);
	free_bfchan(bfchanp);
	if (fclose(input) != 0){
		return 1;
	}
	if (fclose(output) != 0){
		return 1;
	}
	return 0;
}
