// example:
// C-style 'clear array'
// what is wrong?

#include <stdio.h>

#define ARRAY_SIZE 100

int main(){
   int array[ ARRAY_SIZE ];
   char message[] = "all is well\n";
   
   for( int i = 1; i <= ARRAY_SIZE; ++i ){
      array[ i ] = 0;
   }
   printf( "I can tell you that \n" );
   printf( message );
   return 0;
}   

