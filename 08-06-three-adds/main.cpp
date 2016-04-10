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
   
   vector a( 1, 2 ), b( 3, 4 ), c( 5, 6 );
   int x = 1, y = 2, z;
   
   c = a + b;
   z = x + y;
   // z = x + b;    // compilation error
   
   return 0;
}
