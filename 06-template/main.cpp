// template

#include <iostream>

#include "window.hpp"
#include "line.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

int main(int argc, char **argv){
   window w( 128, 64, 2 );
   
   line diagonal_line( w, 5, 5, 30, 40 );
   diagonal_line.print();
   
   rectangle box( w, 20, 10, 30, 20 );
   box.print();
   
   circle ball( w, 70, 30, 20 );
   ball.print();
   
   return 0;
}
