#include "vector.hpp"

bool operator==( const vector & lhs, const vector & rhs ){
   return ( lhs.x == rhs.x ) && ( lhs.y == rhs.y );
}

int main(int argc, char **argv){

   vector a( 1, 2 );
   vector b( 4, 3 );

   vector c = a + b;

   assert( a == vector( 1, 2 ) );
   assert( b == vector( 4, 3 ) );
   assert( c == vector( 5, 5 ) );

   return 0;
}
