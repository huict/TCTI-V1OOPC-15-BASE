#include "ostream"
#include "catch_with_main.hpp"
#include "vector.hpp"

bool operator==( vector lhs, vector rhs ){
   return ( lhs.x == rhs.x ) && ( lhs.y == rhs.y );
}

std::ostream & operator<<( std::ostream & lhs, vector rhs ){
   return lhs << "(" << rhs.x << "," << rhs.y << ")";
}

TEST_CASE( "constructors, two_parameters" ){
   vector v( 3, 4 );
   REQUIRE( v.x == 3 );   
   REQUIRE( v.y == 4 );   
}

TEST_CASE( "constructors, default" ){
   vector v;
   REQUIRE( v == vector( 0, 0 ) );   
}


