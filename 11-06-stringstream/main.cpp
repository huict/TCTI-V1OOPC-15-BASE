#include "ostream"
#include "catch_with_main.hpp"
#include "vector.hpp"

std::ostream & operator<<( std::ostream & lhs, vector pos ){
   lhs << "(" << pos.x << "," << pos.y << ")";
   return lhs;
}

TEST_CASE( "operator<<" ){
   std::stringstream s;
   
   vector v( 1, 2 );
   
   s << v;
   
   REQUIRE( s.str() == "(1,2)" );   
}


