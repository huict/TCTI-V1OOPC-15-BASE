#ifndef VECTOR_HPP
#define VECTOR_HPP

class vector {
public:
   int x;
   int y; 
   
   vector( int x, int y ): 
      x( x ), y( y )
   {}
   
   vector operator+( const vector & rhs ) const {
      return vector( x + rhs.x, y + rhs.y );
   }   
};

#endif