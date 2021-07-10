/*
The binary representation of a 30-bit unsigned integer Q is denoted by the sequece [Q[29],Q[28].....Q[0]], where Q[29] 
corresponds to the MSB bit of Q. Leading zeros may apperar.

A 30-bit unsigned integer N is given. The right cyclic shoft of N by one bit is the 30-bit unsigned integer whose binary representation is 
[N[0],N[29]....N[1]]. A right cyclic shift of N by K bits is the result of performing a right cyclic shift of N by one bit K times.

For example:

  . The right cyclic shift of 9736 by one bit is 4868.
  . The right cyclic shift of 9736 by two bit is 2434.
  . The right cyclic shift of 9736 by three bit is 1217
  . The right cyclic shift of 9736 by five bit is 268435760
  . The right cyclic shift of 9736 by eleven bit is 809500676
  
  The number 809500676 is the largest value that can be obtained by performing a right shift of 9736.
 
*/

#include <stdio.h>

int cyclicRotation(int N)
{
  int largest = N;
  int shift = 0;
  int temp = N;
  int count;
  
  for(count = 1; count < 30; ++count)
  {
    int index = (temp & 1);
    temp = ((temp >> 1) | (index << 29));
    
    if(temp > largest)
    {
      largest = temp;
      shift = count;
    }
  }
  return shift;
}

int main()
{
  int a = cyclicRotation(28);
  printf("%d", a);
  return 0;
}
