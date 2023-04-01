/*
 * Write a program that prints the numbers from 1 to 100, each separated by a
newline.

If the number is a multiple of 3, it prints 'fizz' instead.
If the number is a multiple of 5, it prints 'buzz' instead.
If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.
*/

/**
 * A real-life analogy for this problem could 
 * be a teacher who wants to grade his/her students' papers.
 * In this analogy, each student is like a number,
 * and the grade they receive is like the output 
 * that the program produces.
 * When the student's grade is divisible by 3, 
 * the teacher writes "fizz" on the paper, 
 * and when it is divisible by 5, the teacher writes "buzz."
 *  If the grade is divisible by both 3 and 5,
 * the teacher writes "fizzbuzz" on the paper.
*/

#include <unistd.h>

void ft_putnbr(int n)
{
    char str[10]= "0123456789";

    if (n > 9)
        ft_putnbr(n / 10);
    write(1, &str[n % 10], 1);
}

int main(void)
{
    int i;

    i = 1;
    while (i <= 100)
    {
        if (i % 15 == 0)
            write(1, "fizzbuzz", 8);
        else if (i % 3 == 0)
            write(1, "fizz", 4);
        else if (i % 5 == 0)
            write(1, "buzz", 4);
        else
            ft_putnbr(i);
        i++;
        write (1, "\n", 1);
    }
}

