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

#include <unistd.h>
#include <stdarg.h>

size_t ft_putstr(char *str, int len)
{
    while (str && str[len] && len)
    {
        ;
    }
        return (str ? write(1, str, len): write(1, "(null)", 6));
}

void ft_putnbr(long n, unsigned len,char *sign, int *size)
{
    if (n >= len)
        ft_putnbr(n /len, len, sign, size);
    *size += (int) write(1, &sign[n % len], 1);
}

void ft_puthex(long n, int len, char *sign, int *size)
{
    (n < 0) ? (*size += (int) write(1, "-", 1),
        ft_putnbr(-n,len, sign, size)):(ft_putnbr(n, len, sign,size));
}


int ft_printf(char *format, ...)
{
    int size = 0;
    va_list ap;

    va_start(ap, format);
    while (*format)
    {
        if (*format == '%' && *(format + 1) == 's' && (format += 2))
            size += (int) ft_putstr(va_arg(ap, char *), 0);
        else if (*format == '%' && *(format + 1) == 'x' && (format += 2))
            ft_putnbr(va_arg(ap, int), 16, "0123456789abcdef", &size);
        else if (*format == '%' && *(format + 1) == 'd' && (format += 2))
            ft_puthex(va_arg(ap, int), 10, "0123456789", &size);
        else
            size += (int) write(1, format++, 1);
    }
    return (va_end(ap), size);
}

int main(int ac,char **av)
{
    ft_printf("askdjas1232");
}
