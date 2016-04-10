#include <iostream>

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

int main(int argc, char **argv){
   
   vector a( 1, 2 ), b( 3, 4 );
   

   // calculations with vectors
   a = a + b;
   
   return 0;
}
