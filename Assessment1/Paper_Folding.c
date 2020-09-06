#include <stdio.h>
#include <math.h>
// include other appropriate headers here, as per your requirement

int main(void) {
  int n;
  scanf("%d",&n);

  // Write your logic here. You can define helper functions if you want.
  long long size = pow(2,n)-1;
  char a[size];
  //The first element will always be 1
  a[0] = '1';
  //For middleAdd
  long long middleAdd = 1, secondPointer;

  while (n--)
  {
    a[middleAdd] = '1';
    //Ab one ke aage wale element 2*middleAdd-1 (3) tak rukega
    secondPointer = middleAdd+1;
    while ( secondPointer < 2*middleAdd+1)
    {
      if (a[(2*middleAdd)-secondPointer] == '1')
      {
        a[secondPointer] = '0';
      }else
      {
        a[secondPointer] = '1';
      }  
      secondPointer++;
    }
    //First we add at one, then at 3
    middleAdd = (2*middleAdd)+1;
  }
  printf("%s", a);

  return 0;
}