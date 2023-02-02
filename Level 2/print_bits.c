/** 
 * -- Define a loop for 8 bytes(which is octet)
 * -- LSB= 0 and MSB = 7
 * -- Current bit set by "&" and the "1" shifted to
 *    left by 'i' bits.
 * -- If non-zero -> bit is set -> prints "1"
 * -- If zero-> bit set -> print 0 
 * --> Bit shifting left(<<) is a way of multiplying a binary number by 2, and 
 *     bit shifting right(>>) is a way of dividing it by 2.
 * Usage: Manipulate binary numbers -> compact and efficient
**/

#include<unistd.h>
void print_bits(unsigned char c)
{
    int i = 7;
    while(i >= 0)
    {
        if (c & (1 << i))
            write(1, "1",1);
        else
            write(1, "0", 1);
        i--;
    }
}

int main(void)
{
    print_bits(2);
}

/** Alternative soln:
 * check the value of the ith bit in the c byte,
 * and print either '0' or '1' based on its value **/

unsigned char bit = (c & (1 << i)) ? '1': '0';
write(1, &bit, sizeof(bit));