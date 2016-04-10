#include <iostream>

class vector {
public:
   int x;
   int y; 

   vector( int x = 0, int y = 0 );
};

vector::vector( int x, int y ): 
   x( x ), y( y )
{}

int main(int argc, char **argv){
   
   vector a;
   vector b( 1 );
   vector c( 2, 3 );
   
   return 0;
}
