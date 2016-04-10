#include <iostream>

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

int main(int argc, char **argv){
   vector a( 1, 2 );
   vector b;
   
   return 0;
}
