// example:
// declaration of a line class that stores its window

#ifndef LINE_HPP
#define LINE_HPP

#include "window.hpp"
#include "vector.hpp"

class line {
private:
   vector start;
   vector end;
   window & w;
public:
   line( window & w, const vector & start, const vector & end ):
      start( start ),
      end( end ),
      w( w )
   {}
   void draw();
};

#endif // LINE_HPP
