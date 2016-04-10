// example:
// declaration of a rectangle object that is contains four line objects

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "line.hpp"

class rectangle {
private:
   line left, right, top, bottom;
public:
   rectangle( int start_x, int start_y, int end_x, int end_y );
   void print();
};


#endif // RECTANGLE_HPP
