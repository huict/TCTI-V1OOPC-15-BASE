// example:
// use a constructor to create (initialize) 
// a line struct

#include <iostream>

struct line {
   int start_x;
   int start_y; 
   int end_x;
   int end_y;

   line( int p_start_x, int p_start_y, int p_end_x, int p_end_y ){
      start_x = p_start_x;
      start_y = p_start_y;
      end_x   = p_end_x;
      end_y   = p_end_y;
   }

   void print();
};

int main(int argc, char **argv){
   line diagonal_line( 10, 10, 50, 50 );
   diagonal_line.print();
	return 0;
}
