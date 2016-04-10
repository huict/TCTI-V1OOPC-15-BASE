// example:
// clearing an array in C++ style
// waht is wrong?

#include <stdio.h>

#define ARRAY_SIZE 1000

int main(){

   int array[ ARRAY_SIZE ] = { 42, 43, 44 };
   
   for( int x : array ){
      x = 0;
   }

   printf( "array[ 0 ] = %d", array[ 0 ] );
   return 0;
}   

