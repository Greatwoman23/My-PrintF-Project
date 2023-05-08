# Welcome to My Printf
***

## Task
The task is to create a Program called my_Printf.c function. It requires disassembling it into smaller parts and creating a framework that makes it possible to add new capabilities to current code.


## Description
This code contains a lot of procedures for structuring and producing data to what is known as standard output.
This printf program consists of functions and a main function, they are both included in this C program.  Functions with sample inputs are called by the main function
The code designates the C function my_printf, which offers a customized implementation of the printf function.

The functions are: 
Fix_StriNg(char *s)
This method accepts as input a character array or string and outputs it to the screen. It returns the total amount of characters typed.


Fix_CHaRaCTer(char c)
This function accepts a single character as input and displays it on the screen. It yields an integer.

 NuMeRAl_reF(void *HeXaPvaLue)
This method transforms a pointer value to hexadecimal and returns it as a string. It returns the number of characters in the generated string.

UnuSed_digit_valuE(unsigned int nbr, char *base, int base_size)
This function transforms an unsigned integer to a string using the number system base supplied. 
The function recursively divides the input integer by the base until the number is less than the base. 
Each division operation's residual is utilized as an index into the base string.

My_cAsE_D (int nbr)
This method transforms an integer into a string and displays it on the screen.
 The total amount of characters written is returned.


char *restrict format, my_printf(...)
This function accepts a format string and a configurable number of parameters, similar to the normal printf() method. The function searches the format string character by character for format specifiers. Some of the format identifiers that are supported include %d,%o,%u,%x,%c,%s, and%p. 
The function returns the total amount of characters displayed on the screen.


## Installation
I did not need to install anything for this project.

## Usage
To use the printf code include the header file and call the corresponding function(s) in your application to utilise these functions.


```
./my_project argument1 argument2
```

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px'></span>
