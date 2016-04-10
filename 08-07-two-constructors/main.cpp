#include <iostream>

class vector {
public:
   int x;
   int y; 
   
   vector( int x, int y ): 
      x( x ), y( y )
   {}
   
   vector(){}

};

int main(int argc, char **argv){
   
   vector a;
   vector b( 1, 2 );

   return 0;
}

