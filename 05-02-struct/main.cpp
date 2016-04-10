// example:
// print a line by (explicitly) passing a line struct 
// that contains the four coordinates

#include <iostream>

struct line {
   int start_x;
   int start_y; 
   int end_x;
   int end_y;
};

void print_line( line x );

int main(int argc, char **argv){
   line diagonal_line = { 10, 10, 40, 20 };
   print_line( diagonal_line );
   return 0;
}
