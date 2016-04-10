// example:
// declaration of a rectangle object that is contains four line objects

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "window.hpp"
#include "line.hpp"

class rectangle {
private:
   vector start;
   vector end;
   window w;
   line left;
   line right;
   line top;
   line bottom;
public:
   rectangle( window & w, const vector & start, const vector & end );   
   void print();
};


#endif // RECTANGLE_HPP
