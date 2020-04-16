# Simple_shell

This project was made for Holberton School, it is the last project of the first trimester, and we use all that we have learned at this time.

This Shell was built and tested in Ubuntu 14.04 LTS via Vagrant in VirtualBox and compiled with GCC Compiler version 4.8.4.

It consists of a simple shell designed on C language, to be used with simple mode typing commands on the prompt or using "non-interactive" mode.

## Download

For use and see this simple_shell, just clone from this repository:

`https://github.com/somarae8/simple_shell.git`

## Compilation process

Once you have cloned the repo, just open your terminal on the directory called 'simple shell' and type:

`gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`

## How to use

We have 2 modes of using the program, in interactive mode and non-interactive mode:

#### non-interactive

    In this mode, we pass the command from the standard output but don't print the prompt.

`$ echo "/bin/ls" | ./hsh`


#### interactive

    The prompt is printed and the program waits to user type a command.

`$ ./hsh`
`(#cisfun$ )`

## Description

This shell use the next functions in the next directories:

#### ========== err_func.c ==========

`read_error`        --> If the program fail to read the command lines, print the error.

`print_error`       --> Build the error message if tue user type and wrong command.       


#### ========== executer.c ==========

`ejecutador`        --> Run the command entered by the user.

`search_path`	    --> Function to search path of environment.


#### ========== free_func.c ==========

`free_all`          --> Free all the mallocs from the program.

`send_free`         --> Send to free 2 arguments, `line` and `token` for example.


#### ========== functions.c ==========

`print_sign`        --> Print the prompt if use the interactie mode.

`tokenize`          --> Save on an array each command entered by the user, before run the command.

`command_lot`       --> Count the number of commands entered by the user.

`_realloc`	    --> Reallocate the memory

`_memcopy`	    --> Copy str the number of bytes from src to desk.


#### ========== _printf.c ==========

`get_op_func`       --> Function to look for arguments from the _printf fuction.

`_printf`           --> Print a simple line of text and can receive format and arguments.


#### ========== _printf_c.c ==========

`_printc`           --> Print char on _printf function.

`_prints`           --> Print string on _printf function.


#### ========== _printf_n.c ==========

`_printp`           --> Print the percent on _printf function.

`f_int`             --> Print integers on _printf function.

`f_int_unsigned`    --> Print unsigned integers on _printf function.


#### ========== prompt.c ==========

`c_handler`         --> Handle the CTRL + C signal.

`main`              --> The main function of the program.


#### ========== str_func.c ==========

`_putchar`          --> Print just a char.

`_strcmp`           --> Compare if two strings are the same.

`_strlen`           --> Length of the string.

`_strncpy`          --> Copy a string from a _source_ to a _dest_ a _n_ bytes size.

`_strcat`	    --> Concat two strings

## Authors ✍

* **Luis Angel Vargas Mosquera** - *GitHub user* - [LuAnVaRmO](https://github.com/LuAnVaRmO)
* **Eduardo Ramos Barbosa** - *GitHub user* - [somarae8](https://github.com/somarae8)
