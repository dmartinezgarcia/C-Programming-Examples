/* NOTE: Select an exercise and use CTRL+MAYUS+C to comment it. Select an exercise and use CTRL+MAYUS+X to uncomment it. */

/*********************************************************
    Exercise 1
		Type in and run the four programs presented in this chapter. Compare the output produced by each program with the output presented after each program in the text.
*********************************************************/

// The output is the same.

/*********************************************************
    Exercise 2
		Write a program that determines whether your particular computer performs an arithmetic or a logical right shift.
*********************************************************/

//#include <stdio.h>
//#include <stdbool.h>
//
//char getCharBits (void)
//{
//    unsigned char a = ~0;
//    char i = 0;
//
//    while (a & 0x01)
//    {
//        i++;
//        a >>= 1;
//    }
//
//    return i;
//}
//
//// Function that returns true if the computer performs arithmetic shifts or false if it performs logical shifts.
//
//bool isArithmeticShift (void)
//{
//    // First lets determine the number of bits in char.
//    char bits = getCharBits();
//    signed char a = (~0) >> bits;
//
//    if (a & 0x01)
//        return true;
//    else
//        return false;
//}
//
//int main (void)
//{
//    printf("This computer performs arithmetic shifts? %s.\n", isArithmeticShift() ? "YES" : "NO");
//
//    return 0;
//}

/*********************************************************
    Exercise 3
        Given that the expression ~0 produces an integer that contains all 1s, write a function called int_size() that returns the number of bits contained in an int on your particular machine.
*********************************************************/

//#include <stdio.h>
//
//char getIntSize (void)
//{
//    unsigned int a = ~0;
//    char i = 0;
//
//    while (a & 0x01)
//    {
//        i++;
//        a >>= 1;
//    }
//
//    return i;
//}
//
//int main (void)
//{
//    printf("What is the size of an integer in bits in your particular machine? %i.\n", getIntSize());
//
//    return 0;
//}

/*********************************************************
    Exercise 4
        Using the result obtained in exercise 3, modify the rotate() function from Program 11.4 so that it no longer makes any assumptions about the size of an int.
*********************************************************/

//#include <stdio.h>
//
//char getIntSize (void)
//{
//    unsigned int a = ~0;
//    char i = 0;
//
//    while (a & 0x01)
//    {
//        i++;
//        a >>= 1;
//    }
//
//    return i;
//}
//
//// Function to rotate an unsigned int left or right
//
//unsigned int  rotate (unsigned int  value, int  n)
//{
//    unsigned int  result, bits;
//    char tbits = getIntSize();
//
//    // scale down the shift count to a defined range
//
//    if  ( n > 0 )
//        n = n % tbits;
//    else
//        n = -(-n % tbits);
//
//    if  ( n == 0 )
//        result = value;
//    else if ( n > 0 )      // left rotate
//    {
//        bits = value >> (tbits - n);
//        result = value << n  |  bits;
//    }
//    else  {               // right rotate
//        n = -n;
//        bits = value << (tbits - n);
//        result = value >> n  |  bits;
//    }
//
//    return result;
//}
//
//int main (void)
//{
//    unsigned int  w1 = 0xabcdef00u, w2 = 0xffff1122u;
//    unsigned int  rotate (unsigned int  value, int  n);
//
//    printf ("%x\n", rotate (w1, 8));
//    printf ("%x\n", rotate (w1, -16));
//    printf ("%x\n", rotate (w2, 4));
//    printf ("%x\n", rotate (w2, -2));
//    printf ("%x\n", rotate (w1, 0));
//    printf ("%x\n", rotate (w1, 44));
//
//    return 0;
//}

/*********************************************************
    Exercise 5
        Write a function called bit_test() that takes two arguments: an unsigned int and a bit number n. Have the function return 1 bit number n if it is on inside the word, and 0 if it is off. Assume that bit number 0 references the leftmost bit inside the integer. Also write a corresponding function called bit_set() that takes two arguments: an unsigned int and a bit number n. Have the function return the result of turning bit n on inside the integer.
*********************************************************/

//#include <stdio.h>
//#include <stdbool.h>
//
//char getIntSize (void)
//{
//    unsigned int a = ~0;
//    char i = 0;
//
//    while (a & 0x01)
//    {
//        i++;
//        a >>= 1;
//    }
//
//    return i;
//}
//
//char bit_test (unsigned int a, char n)
//{
//    char nbits = getIntSize();
//    unsigned int mask = 0;
//
//    if (n >= nbits)
//        return 0;
//
//    mask = 0x01 << (nbits - 1 - n);
//
//    if (a & mask)
//        return 1;
//    else
//        return 0;
//}
//
//unsigned int bit_set (unsigned int a, char n)
//{
//    char nbits = getIntSize();
//
//    if (n >= nbits)
//        return 0;
//
//    return (a | (0x01 << (nbits - 1 - n)));
//}
//
//int main (void)
//{
//    unsigned int a = 0;
//
//    printf("Number before the sets: %x.\n", a);
//    a = bit_set(a, 24);
//    a = bit_set(a, 16);
//    a = bit_set(a, 8);
//    a = bit_set(a, 0);
//    printf("Number after the sets: %x.\n", a);
//
//    printf("Bit %i is %s.\n", 24, bit_test(a, 24) ? "ON" : "OFF");
//    printf("Bit %i is %s.\n", 16, bit_test(a, 16) ? "ON" : "OFF");
//    printf("Bit %i is %s.\n", 8, bit_test(a, 8) ? "ON" : "OFF");
//    printf("Bit %i is %s.\n", 0, bit_test(a, 0) ? "ON" : "OFF");
//    printf("Bit %i is %s.\n", 23, bit_test(a, 23) ? "ON" : "OFF");
//    printf("Bit %i is %s.\n", 15, bit_test(a, 15) ? "ON" : "OFF");
//    printf("Bit %i is %s.\n", 7, bit_test(a, 7) ? "ON" : "OFF");
//    printf("Bit %i is %s.\n", 2, bit_test(a, 2) ? "ON" : "OFF");
//
//    return 0;
//}

/*********************************************************
    Exercise 6
        Write a function called bitpat_search() that looks for the occurrence of a specified pattern of bits inside an unsigned int. The function should take three arguments and should be called as shown:

            bitpat_search (source, pattern, n)

        The function searches the integer source, starting at the leftmost bit, to see if the rightmost n bits of pattern occur in source. If the pattern is found, have the function return the number of the bit at which the pattern begins, where the leftmost bit is bit number 0. If the pattern is not found, then have the function return −1. So, for example, the call

            index = bitpat_search (0xe1f4, 0x5, 3);

        causes the bitpat_search() function to search the number 0xe1f4 ( = 1110 0001 1111 0100 binary ) for the occurrence of the three-bit pattern 0x5 (= 101 binary). The function returns 11 to indicate that the pattern was found in the source beginning with bit number 11.

        Make certain that the function makes no assumptions about the size of an int (see exercise 3 in this chapter).
*********************************************************/

//#include <stdio.h>
//
//char getIntSize (void)
//{
//    unsigned int a = ~0;
//    char i = 0;
//
//    while (a & 0x01)
//    {
//        i++;
//        a >>= 1;
//    }
//
//    return i;
//}
//
//// This function returns the index related to the size of the integer rather than to the size of the number within the integer, which is more useful and more portable.
//
//unsigned int bitpat_search (unsigned int source, unsigned int pattern, char n)
//{
//    // There are faster ways to implement this.
//    char nbits = getIntSize();
//    char sbit = 0, pbit = 0, i = 0, a = 0;
//
//    for (i = 0, a = 0; i < nbits; i++)
//    {
//        sbit = ( (source & (0x01 << (nbits - 1 - i))) >> (nbits - 1 - i) );
//        pbit = ( (pattern & (0x01 << (n - 1 - a))) >> (n - 1 - a));
//
//        if (sbit == pbit)
//            a++;
//        else
//            a = 0;
//
//        if (a == n)
//            return (i - a);
//    }
//
//    return -1;
//}
//
//int main (void)
//{
//    int index = bitpat_search (0xe1f4, 0x5, 3);
//
//    printf("The value of index is %i.\n", index);
//
//    return 0;
//}

/*********************************************************
    Exercise 7
        Write a function called bitpat_get() to extract a specified set of bits. Have it take three arguments: the first an unsigned int, the second an integer starting bit number, and the third a bit count. Using the convention that bit numbering starts at 0 with the leftmost bit, extract the specified number of bits from the first argument and return the result. So the call

            bitpat_get (x, 0, 3)

        extracts the three leftmost bits from x. The call

            bitpat_get (x, 3, 5)

        extracts five bits starting with the fourth bit in from the left.
*********************************************************/

//#include <stdio.h>
//
//char getIntSize (void)
//{
//    unsigned int a = ~0;
//    char i = 0;
//
//    while (a & 0x01)
//    {
//        i++;
//        a >>= 1;
//    }
//
//    return i;
//}
//
//unsigned int bitpat_get (unsigned int source, char index, char count)
//{
//    char nbits = getIntSize();
//    unsigned int mask = 0;
//    char i = 0;
//
//    for (i = 0; i < count; i++)
//        mask |= 0x01 << (nbits - 1 - i - index);
//
//
//    return (source & mask) >> (nbits - index - i);
//}
//
//int main (void)
//{
//    int val = bitpat_get (0x5FF0F0F0, 8, 8);
//
//    printf("The value of extracted value is %X.\n", val);
//
//    return 0;
//}

/*********************************************************
    Exercise 8
        Write a function called bitpat_set() to set a specified set of bits to a particular value. The function should take four arguments: a pointer to an unsigned int in which the specified bits are to be set; another unsigned int containing the value to which the specified bits are to be set, right adjusted in the unsigned int; a third int that specifies the starting bit number (with the leftmost bit numbered 0); and a fourth int specifying the size of the field. So the call

            bitpat_set (&x, 0, 2, 5);

        has the effect of setting the five bits contained in x, beginning with the third bit from the left (bit number 2), to 0. Similarly, the call

            bitpat_set (&x, 0x55u, 0, 8);

        sets the eight leftmost bits of x to hexadecimal 55.

        Make no assumptions about the particular size of an int (refer to exercise 3 in this chapter).
*********************************************************/

//#include <stdio.h>
//
//char getIntSize (void)
//{
//    unsigned int a = ~0;
//    char i = 0;
//
//    while (a & 0x01)
//    {
//        i++;
//        a >>= 1;
//    }
//
//    return i;
//}
//
//void bitpat_set (unsigned int* source, unsigned int val, char index, char count)
//{
//    char nbits = getIntSize();
//    unsigned int mask = 0;
//    char i = 0;
//
//    // First put all the bits to zero.
//    for (i = 0; i < count; i++)
//        mask |= 0x01 << (nbits - 1 - i - index);
//
//    *source &= ~(mask);
//
//    // Then OR the bits.
//    *source |= (val << (index - count));
//}
//
//int main (void)
//{
//    unsigned int val = 0x1234FF00U;
//    bitpat_set(&val, 0x5551U, 0, 16);
//
//    printf("The value of extracted value is %X.\n", val);
//
//    return 0;
//}
