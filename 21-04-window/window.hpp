// example:
// declaration of a window class

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "windows.h"
#include "vector.hpp"

class window {   
public:
   const vector size;
   
   window( const vector & size ): size( size ){}
   
   virtual void draw( const vector & pixel, bool v = true ) = 0;
   
   virtual void clear(){
      for( int x = 0; x < size.x; ++x ){
         for( int y = 0; y < size.y; ++y ){
            draw( vector( x, y ), false );
         }
      }       
   }
};

class window_window : public window {
   int scale;
   
   // needed to use the OS window
   HDC hdc;
   
public:
   window_window( const vector & size, int scale );
   void draw( const vector & pixel, bool v = true ) override;
};

void wait_ms( int n );

#endif // WINDOW_HPP
