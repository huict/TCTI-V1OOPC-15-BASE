#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <ostream>

class vector {
public:
   int x;
   int y; 
   
   vector( int x, int y ): 
      x( x ), y( y )
   {}
   
   vector( const vector & rhs ):
      x( rhs.x ),
      y( rhs.y )
   {}
   
   vector & operator+=( const vector & rhs ){
      x += rhs.x;
      y += rhs.y;
      return *this;
   }
};

std::ostream & operator<<( std::ostream & lhs, const vector & pos );

#endif // VECTOR_HPP
