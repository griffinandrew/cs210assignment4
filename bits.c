/* 
 * CS:APP Data Lab 
 * 
 * <Griffin Heyrich U42992446>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
include <stdio.h>

/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* We do support the IEC 559 math functionality, real and complex.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
// Rating: 1
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  //not each of them then or them together, take the not of this to get answer
  int k = ~x | ~y;
  return ~k;
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
//this returns the integer with the largest 2's complement
  return ~(1 << 31);
  //return 2;

}
// Rating: 2
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
 // x = 0xAABBCCDD;
//  n = 3;
 // m = 0;
  printf("0x%02X x\n", x);
  printf("%x n\n", n);
  printf("%x m\n", m);
  int t = n<<3; //shifting by bytes
  int j = m<<3;
  printf("0x%02X og shift of n\n", t);
  printf("0x%02X og shift of m \n", j);

  int first =  x & (0xFF<<t); //these should be just the corect values to swap 
  int second = x & (0xFF<<j); //all zeros but postion to swap
  printf("0x%02X shifing to pos n\n", first);
  printf("0x%02X shift to pos m\n", second);

  //do i need to adjust for byte too?
  int n_iso = 0xFF & (first>>t); //getting the specific bit 
  int m_iso = 0xFF & (second>>j);
  printf("0x%02X n iso\n", n_iso);
  printf("0x%02X m iso\n", m_iso);

  //change m to n postion using shift (this is just shifting bits tho not bytes)
  //int k = n_iso>>j; 
  //int y = m_iso<<t;
  int k = n_iso<<t; 
  int y = m_iso<<j;
  int one_to_clean = k | y; //combines the 2 swapped one to insert onto old byte
  int others = x & ~one_to_clean; //leftovers
  int newpos_1 = n_iso<<j; 
  int newpos_2 = m_iso<<t;
  int one_to_insert = newpos_1 | newpos_2;


  printf("0x%02X others\n", others);
  printf("0x%02X x \n", x);
  printf("0x%02X onetoinsert\n", one_to_insert);
  printf("0x%02X ~onetoinsert\n", ~one_to_insert);

 // x &= ~(x<<t | x<<j);  //clear bits
  //clear bytes

  //insert bytes
 // x |= one_to_insert; // or can I add them in?
 //x |= x + one_to_insert;

  return (others | one_to_insert);

    //return 2;
}
// Rating: 3
/* 
 * bitMask - Generate a mask consisting of all 1's 
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit) {
 // highbit = 1;
  //lowbit = 3; 
  int ones = ~0x0;
 // printf("%d high \n",highbit);
 // printf("%d low \n",lowbit);

  int one_to_highbit = (2 << highbit) +ones;
  int one_tolowbit = (1<<lowbit)+ones;

    //printf("0x%02X ones to high\n", one_to_highbit);
    //printf("0x%02X ones to low\n", one_tolowbit);
  int y = one_to_highbit & ~one_tolowbit;
 // printf("0x%02X y\n", y);
  return y;

  //return 2;
}
/* 
 * isLess - if x < y  then return 1, else return 0 
 *   Example: isLess(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLess(int x, int y) {
  //first check signs
  int y_sign, x_sign;
  y_sign = y>>31; 
  y_sign = y_sign & 0x1;
  x_sign = x>>31;
  x_sign = x_sign & 0x1;
  //compare signs
//  printf("0x%02X x sign\n", x_sign);
 // printf("0x%02X y sign\n", y_sign);
 
  int same_or_not = (y_sign ^ x_sign); //1 when signs same, 0 when different

  //1 if same 0 if different
//  printf("0x%02X sign same or not \n", same_or_not);

  int smaller_when_signs_same = ((x+(~(y)+1))>>31) &0x1; // first digit will be 1 if y smaller, 0 if x smaller, might need to reverse this later on
//gives 1 if x<y, else 0 

//problem is if they are eaual also get a one 

 // printf("0x%02X smaller or not\n", smaller_when_signs_same);
  int equal = ((!(same_or_not)) & smaller_when_signs_same); //
//  printf("0x%02X equal\n", equal);

  int not_equal = (x_sign & !(y_sign));  // 1 if x < y
//  printf("0x%02X not equal \n", not_equal);
  int checking_return = (not_equal | equal);
  //return (not_equal | equal);
 // printf("0x%02X return \n", checking_return);
  return checking_return;
}
/* 
 * isNonNegative - return 1 if x >= 0, return 0 otherwise 
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x) {
  //get value of sign using first bit, if is neg return 0 if non neg 1
  return!(x>>31);
  //return 2;
}
/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0, //can't be 
 *            addOK(0x80000000,0x70000000) = 1, //can be
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
  int y_sign, x_sign;
  y_sign = y>>31; 
  y_sign = y_sign & 0x1;

  x_sign = x>>31;
  x_sign = x_sign & 0x1;
  
  //printf("0x%02X y sign\n", y_sign);
  //printf("0x%02X x sign\n", x_sign);
  //get sign to check b/c we know if pos + pos = pos no overlfow and neg + neg = neg no overflow 
  int check = y+x; //see if overflow results 
//does the total match the number 

  //(y_sign & x_sign) ^ check; //if not over flow if it is they are 
 // printf("0x%02X check\n", check);
  int check_sign = check >>31; //get sign of the overflow to see if it matches
  check_sign = check_sign & 0x1; //msb of total
  //printf("0x%02X check sign\n", check_sign);

  int same_or_not = (y_sign ^ x_sign); //1 if diff 0 if same checking if same or not was xor changd to reg or
 // printf("0x%02X same or not\n", same_or_not);
  int testing_return = (!((y_sign & x_sign) ^ check_sign) | same_or_not); //using ! vs ~ greatly affects input
 // printf("0x%02X what is being returned\n", testing_return);
  
  
  return testing_return;
 
}
// Rating: 4
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  //counter = x&mask1; //gives all 0's except last one 
  printf("0x%02X x\n", x);
  int mask5 = 0x11; // this is 00010001, need 1 in end for 32 bits
  printf("0x%02X mask\n", mask5); //things to do 
  int mask6 = (mask5 | (0x11<<8)); //shifting by 8 gives 0000 1000 1 0000 0000 oring gives 1000100010001
  printf("0x%02X mask6\n", mask6);
  int mask7 = (mask6|(mask6<<16)); // this gives 1 =  000 1000 1000 1000 1000 1000 10001

  printf("0x%02X mask 7\n", mask7);
  int count = x&mask7; //0 positon
  printf("0x%02X count\n", count);
  count = count+((x>>1)&mask7); //copies from first postiton
  printf("0x%02X count shift 1\n", count);
  count = count+((x>>2)&mask7); //copies from second postiton
  printf("0x%02X count shift 2\n", count);
  count = count+((x>>3)&mask7); //copies from third postiton
  printf("0x%02X count shift 3\n", count);
  count = (count>>8) + (count>>16) + count;
  printf("0x%02X total\n", count);

  





  return 2;
}
