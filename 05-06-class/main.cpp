// example:
// use a line class 
// that is cleared and defined in separate files

#include <iostream>
#include "line.hpp"

int main(int argc, char **argv){
   line diagonal_line( 20, 20, 40, 40 );
   diagonal_line.print();
   return 0;
}
