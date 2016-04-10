// example:
// assigning to a const parameter caues a compiler error

#include <stdio.h>

void f( int x ){
   // the next line causes a compilation error
   x = x + 5; 
}

int main(){
   int i = 42;
   f( i );
   printf( "i=%d", i );
   return 0;
}   