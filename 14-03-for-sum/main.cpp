// example:
// C++ sum the elements of an array

#include <stdio.h>

int main(){
   int array[] = { -1, 40, 3 };
   
   int sum = 0;
   for( int element : array ){
      sum += element;
   }


   printf( "The answer is %d\n", sum );
   return 0;
}   

