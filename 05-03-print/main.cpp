// example:
// print a line by passing a line struct 
// that contains the four coordinates
// as in implicit parameter to its member function print()

#include <iostream>

struct line {
   int start_x;
   int start_y; 
   int end_x;
   int end_y;
   
   void print();
};

int main(int argc, char **argv){
   line diagonal_line = { 10, 10, 40, 40 };
   diagonal_line.print();
   return 0;
}
