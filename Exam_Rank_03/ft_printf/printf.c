/** Reallife Analogy
The ft_printf function can be compared to the task of packing for a trip.
It serves as the main function that takes in various items, such as format strings and arguments,
and organizes them efficiently to avoid losing or leaving anything behind.

The ft_putstr function can be compared to packing clothes. 
It takes in a string or set of strings and ensures they are folded and organized properly
 before placing them into the suitcase.

The ft_putnbr function can be likened to packing toiletries.
It takes in a number and converts it into a string that can be packed away neatly and efficiently.

The ft_puthex function can be compared to packing electronics. 
It takes in a number and converts it into a hexadecimal string 
that can be safely packed away to avoid damage during transportation.

All of these functions work together seamlessly to ensure
everything that needs to be packed is organized efficiently and fits neatly into the suitcase.
 Similar to how travelers can add or remove items from their luggage,
the ft_printf function can handle various types of format strings and arguments as needed.
**/

#include <stdarg.h>
#include <unistd.h>

void ft_putnbr(unsigned n, unsigned len, char *sign, int *size)
{
    if (n >= len)
        ft_putnbr(n / len, len, sign, size);
    *size += (int) write(1, &sign[n % len], 1);
}

void ft_n(long n, int len, char *sign, int *size)
{
    (n < 0) ? (*size += (int)write(1, "-", 1),\
    ft_putnbr(-n, len, sign, size)) : ft_putnbr(n, len, sign, size);
}

ssize_t ft_putstr(char *str, int len)
{
    while (str && str[len] && ++len)
        ;
    return (str ? write(1, str, len) : write(1, "(null)", 6));
}

int ft_printf(const char *fmt, ...)
{
    int size = 0;
    va_list ap;
    va_start(ap, fmt);
    while (*fmt)
    {
        if (*fmt == '%' && *(fmt + 1) == 's' && (fmt += 2))
            size += (int) ft_putstr(va_arg(ap, char *), 0);
        else if (*fmt == '%' && *(fmt + 1) == 'x' && (fmt += 2))
            ft_putnbr(va_arg(ap, int), 16, "0123456789abcdef", &size);
        else if (*fmt == '%' && *(fmt + 1) == 'd' && (fmt += 2))
            ft_n(va_arg(ap, int), 10, "0123456789", &size);
        else
            size += (int) write(1, fmt++, 1);
    }
    return (va_end(ap), size);
}


int main(int ac,char **av)
{
    ft_printf("askdjas1232");
}
