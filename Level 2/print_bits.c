/**
 * Bit shifting is a way of manipulating bits in a binary number by moving them to the left or right1. Bit shifting can be used for various purposes,
 * such as multiplying or dividing by powers of two, setting or clearing specific bits, encoding or decoding data, etc.234
 Example:
 Using a combination lock. Imagine you have a lock with four wheels,
 each with 10 digits from 0 to 9. To open the lock, you need to align the correct combination on the wheels.
 Each wheel can be seen as a bit that can be shifted left or right by one position.
 For example, if you have 1234 as the current combination and you want to change it to 2345
 , you need to shift each wheel one position to the right. If you want to change it to 0123,
 you need to shift each wheel one position to the left.
 */


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

#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))


#include<unistd.h>
void print_bits(unsigned char c)
{
    int i = 7;
    while(i >= 0)
    {
        if (CHECK_BIT(c,i))
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