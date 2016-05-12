#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include "window.hpp"
#include "vector.hpp"

class drawable {
protected:
   window & w;
   vector location;
public:
   drawable( window & w, const vector & location );   
   virtual void draw() = 0;
   virtual void update(){}
};

#endif // DRAWABLE_HPP
