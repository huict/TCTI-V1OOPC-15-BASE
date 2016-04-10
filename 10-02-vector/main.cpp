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

std::ostream & operator<<( std::ostream & lhs, vector pos ){
   lhs << "(" << pos.x << "," << pos.y << ")";
   return lhs;
}

int main(int argc, char **argv){
   vector pos1( 1, 2 ), pos2( 12, 33 );
   std::cout << pos1 << "  " << pos2 << "\n";
}



