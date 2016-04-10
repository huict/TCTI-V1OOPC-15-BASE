// example:
// a by-value parameter can be modified, 
// but that doesn't affect the copied variable

#include <stdio.h>

void f( int x ){
   x = x + 5; // did the author realize that he is modifying a copy?
}

int main(){
   int i = 42;
   f( i );
   printf( "i=%d", i );
   return 0;
}   

