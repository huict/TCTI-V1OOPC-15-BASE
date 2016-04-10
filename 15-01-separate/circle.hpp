// example:
// declaration of a circle class that stores its window

#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "window.hpp"
#include "vector.hpp"

class circle {
private:
   vector midpoint;
   int radius;
   window & w;
public:
   circle( window & w, const vector & midpoint, int radius ):
      midpoint( midpoint ),
      radius( radius ),
      w( w )
   {}
   void draw();
};

#endif // CIRCLE_HPP
