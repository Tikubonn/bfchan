
# BFChan 

![](https://img.shields.io/badge/License-GPLv3-green)
![](https://img.shields.io/badge/OS-Windows-blue)
![](https://img.shields.io/badge/CPU-x86%20and%20x64-blue)
![](https://img.shields.io/badge/Compiler-GCC-blue)

\| [日本語](README.ja.md) \| English \| 

BFChan is a BrainFuck compiler that is written in C language.

this can compile a BrainFuck source code for x86 and x64 Windows. 
and this can optimize assembly easily.

I did named this compiler as BFC when wrote this.
but it has been already used to another compiler, so I changed his name to BBW Chan.
BBW Chan is a abbrev of *BrainFuck Compiler Chan* (Chan is a honorific title for Japanese girl, not chinese name xD).

## Usage

you can compile a BrainFuck source code with bfc command.
bfc command compile and create a object file.
be careful, this cannot make a executable file. 
so you should link a created object file with gcc to create executable file.

for this example, create a program that print a string of "Hello world!" then break line.

```shell
$ bfchan -o hellowold.o <<EOF
++++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++++
++++++++++++
>
++++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++++
+
>
++++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++++
++++++++
>
++++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++++
++++++++
>
++++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++++
+++++++++++
>
++++++++++++++++++++
++++++++++++
>
++++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++++
+++++++++++++++++++
>
++++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++++
+++++++++++
>
++++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++++
++++++++++++++
>
++++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++++
++++++++
>
++++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++++
>
++++++++++++++++++++
+++++++++++++
>
++++++++++
<<<<<<<<<<<<
[.>]
EOF
$ gcc helloworld.o -o helloworld.exe
```

### Compile as C Function

BFChan can compile BrainFuck source code as a function for C language.
if you compiled for C function, you can use compiled function in your C program.
compiled function take a char type array and run on that.

let's try!
this code will print out element in array to until reading 0.
after wrote this, save this code as print.b.

```brainfuck
[.>]
```

if you want to compile source code to C function, you can use -c option.
-c option get a function name from file name of source file.
for this example, this function name is print.
lets compile!

```shell
$ bfchan -c print.b -o print.o
```

when you compile source code with -c option, BFChan generate a C header file on the output directory.
you can use compiled function in C program with including this file.

```c
extern int _cdecl print (char*);
```

first, include created header file. last, call the compiled function with an argument that is a char type array.
for this example, argument of char type array is a ascii string of "Hello world!".
compiled function will return 0 when success, otherwise non-zero integer.

if you finished writing this code, save this as main.c.

```c
#include "print.h"

int main (){
  print("Hello world!\n");
  return 0;
}
```

last, compile and link files with GCC for creating executable file.
congratulations :D

```shell
$ gcc main.c print.o -o helloworld.exe
```

## Requirements 

* [Nanafy](https://github.com/tikubonn/nanafy) 1.0.0

## Installation 

BFChan contain a makefile for build, so you can build this compiler with this code.
when build was success, bfchan.exe and bfchan.dll are created in bin directory, 
and bfchan.h, bfchan.lib and bfchan.dll are created in dist directory.

BFChan has required Nanafy for create object file.
so you should give directories those are contains library and header files to MAKE.
it is not necessary if you already configured the environment variables for Nanafy.

```shell
$ make NANAFY_INCLUDE_DIR="" NANAFY_LIBRARY_DIR=""
```

last, please copy files and configure environment variables yourself.

## License 

* BFChan has required [Nanafy](https://github.com/tikubonn/nanafy). Nanafy has released under the [MIT License](LICENSE).
* BFChan has released under the [GNU General Public License Version3](LICENSE).
