// example:
// declaration of a line class 

#ifndef LINE_HPP
#define LINE_HPP

class line {
private:
   int start_x;
   int start_y; 
   int end_x;
   int end_y;
public:
   line( int p_start_x, int p_start_y, int p_end_x, int p_end_y );
   void print();
};

#endif // LINE_HPP
