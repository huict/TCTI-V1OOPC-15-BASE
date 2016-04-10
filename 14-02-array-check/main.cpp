// example:
// C-style check array for being sorted
// what is wrong?

#include <stdio.h>

#define ARRAY_SIZE 64

int main(){
   int array[ ARRAY_SIZE ];
   int fouten = 0;
   
   for( int i = 0; i < ARRAY_SIZE; ++i ){
      array[ i ] = 100 + i;
   }
   
   for( int i = 0; i < ARRAY_SIZE; ++i ){       
      if( array[ i ] > array[ i + 1 ] ){
         printf( "not sorted\n" );
         fouten++;
      }
   }

   printf( "Het aantal fouten is %d\n", fouten );
   return 0;
}   

