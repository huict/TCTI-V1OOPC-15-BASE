#include "vector.hpp"
#include <assert.h>  

int main(int argc, char **argv){
   vector a( 1, 2 );
   vector b( 4, 3 );

   vector c = a + b;

   assert( a.x == 1 ); assert( a.y == 2 );
   assert( b.x == 4 ); assert( b.y == 3 );
   assert( c.x == 5 ); assert( c.y == 6 );

   assert( c.x == 5 ); assert( c.y == 99 ); // assertion failure

   return 0;
}
