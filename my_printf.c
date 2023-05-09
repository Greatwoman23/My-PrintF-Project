#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int Fix_StriNg(char *s);  //The single argument for the "Fix_StriNg" function is a pointer to a character array, or a string.

int Fix_CHaRaCTer(char c)  //The function "Fix_CHaRaCTer" takes a single character c, which is an argument and returns an integer
{
    return write(1, &c, 1);
}

int NuMeRAl_reF(void *HeXaPvaLue)  //This function prints a pointer value as a string after converting it to its hexadecimal representation. The length of the resulting string is indicated by the returned integer.
{
    void *CAseP = HeXaPvaLue;
    int i = 0, ALtituDE = 0;
    unsigned long min, HoRZ_Pu[64],MarK_to_HexP;

    if (CAseP == NULL) Fix_StriNg("(null)");
   MarK_to_HexP = (unsigned long)CAseP;
    while ( MarK_to_HexP != 0)
    {
        int sixteen = 16;
        min =MarK_to_HexP % sixteen;
        if (min < 10)
            HoRZ_Pu[i] = min + 48;
        else
        {
            HoRZ_Pu[i] = min;
            HoRZ_Pu[i] = min + 87;
        }
        
       MarK_to_HexP /= 16, i++;
    }
    ALtituDE += Fix_StriNg("0x");
    while (i - 1 >= 0)
    {
        Fix_CHaRaCTer(HoRZ_Pu[i - 1]), i--, ALtituDE++;
    }
    return (ALtituDE);
}

/*
The "UnuSed_digit_valuE" function accepts three arguments: an unsigned integer nbr, a string base denoting the number system's base to be used, and an integer base_size denoting the length of the base string. 
The input nbr is then divided by base_size recursively until nbr equals base_size. 
Each time a recursion occurs, the remaining division operation is used as an index into the base string, and the Fix_CHaRaCTer function is used to output the corresponding c
*/

int UnuSed_digit_valuE(unsigned int nbr, char *base, int base_size)                                                                      
{
    int CnT = 0;
    if (nbr >= (unsigned int)base_size)
    {
        CnT += UnuSed_digit_valuE(nbr / base_size, base, base_size);
    }
    CnT += Fix_CHaRaCTer(base[nbr % base_size]);
    return CnT;
}

int My_cAsE_D(int nbr)
{
    int CnT = 0;
    if (nbr < 0)
    {
        CnT += Fix_CHaRaCTer('-');
        nbr *= -1;
    }
    if (nbr >= 10)
    {
        CnT += My_cAsE_D(nbr / 10);
    }
    CnT += Fix_CHaRaCTer(nbr % 10 + '0');
    return CnT;
}


int Fix_StriNg(char *s)
{
    int len = strlen(s);
    write(1, s, len);
    return len;
}

/*
The printf() function is simplified in this code. Similar to printf(), it accepts a format string and a variable number of arguments before writing the formatted output to the standard output.
begins by setting up a va_list object args with the variable arguments by calling the va_start() macro.

The format string is then iterated over character by character in search of the% character, which denotes a format specifier. %d, %o, %u, %x, %c, %s, and %p are some of the formated identifiers. 
The function returns the overall character count that was sent to standard output.
*/

int my_printf(char *restrict format, ...)
{
    va_list args;
    va_start(args, format);
    int written = 0;
    for (int i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            i++;
            switch (format[i])
            {
               
                case 'd':
                {
                    written += My_cAsE_D(va_arg(args, int));

                    break;
                }
                
                case 'o':
                {
                    unsigned int i = va_arg(args, unsigned int);
                    written += UnuSed_digit_valuE(i, "01234567", 8);
                    break;
                }
               
                case 'u':
                {
                    unsigned int i = va_arg(args, unsigned int);
                    written += UnuSed_digit_valuE(i, "0123456789", 10);
                    break;
                }
        
                case 'x':
                {
                    unsigned int i = va_arg(args, unsigned int);
                    written += UnuSed_digit_valuE(i, "0123456789ABCDEF", 16);
                    break;
                }
            
                case 'c':
                {
                    char c = (char)va_arg(args, int);
                    write(1, &c, 1);
                    written++;
                    break;
                }
           
                case 's':
                {
                    char *s = va_arg(args, char *);
                    int cwritten = 0;
                    if (s == NULL)
                    {
                        cwritten = Fix_StriNg("(null)");
                    }
                    else
                    {
                        cwritten = Fix_StriNg(s);
                    }
                    written += cwritten;
                    break;
                }

                case 'p':
                {
                    void *p = va_arg(args, void *);
                    written += NuMeRAl_reF(p);

                    break;
                }
               
                default:
                {
                    char c = *format;
                    write(1, &c, 1);
                    written++;
                    break;
                }
            }
        }

        else
        {
            written += Fix_CHaRaCTer(format[i]);
        }
    }

    return written;
}