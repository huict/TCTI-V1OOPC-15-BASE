#include <iostream>

void print_line( int start_x, int start_y, int end_x, int end_y );

class line {
private:
   int start_x;
   int start_y; 
   int end_x;
   int end_y;
public:

   line( int p_start_x, int p_start_y, int p_end_x, int p_end_y ){
      start_x = p_start_x;
      start_y = p_start_y;
      end_x   = p_end_x;
      end_y   = p_end_y;
   }
   
   void print(){
      print_line( start_x, start_y, end_x, end_y );
   }

   // move the line
   void shift( int x, int y ){
      start_x += x;
      start_y += y;
      end_x += x;
      end_y += y;
   }
};

int main(int argc, char **argv){
   line diagonal_line( 10, 10, 40, 20 );
   diagonal_line.print();
   
   diagonal_line.shift( 50, 5 );
   diagonal_line.print();
   
   return 0;
}
