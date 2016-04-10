#include <iostream>

class vector {
public:
   int x;
   int y; 
   
   vector( int x, int y ): 
      x( x ), y( y )
   {}
};

int main(int argc, char **argv){
   vector a( 1, 2 ), b( 3, 4 );

   // add b to a
   a.x += b.x;
   a.y += b.y;

   return 0;
}
