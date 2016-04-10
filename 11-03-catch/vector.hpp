#ifndef VECTOR_HPP
#define VECTOR_HPP

class vector {
public:
   int x;
   int y; 
   
   vector( int x, int y ): 
      x( x ), y( y )
   {}
   
   vector():
      x( 0 ), y( 0 )
   {}
   
};

#endif