// example:
// make the four coordinates private

#include <iostream>

struct line {
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

   void print();

};

void print_line( line x );

int main(int argc, char **argv){
   line diagonal_line = { 10, 10, 100, 30 };
   // diagonal_line.start_x = 7 ; // dit geeft nu een compilatie fout
   print_line( diagonal_line );
   return 0;
}
