#include "window.hpp"
#include "circle.hpp"

class ball : public circle {
private:
   vector speed;
public:
   ball( window & w, const vector & midpoint, int radius, const vector & speed );
   void update() override;
};

ball::ball( window & w, const vector & midpoint, int radius, const vector & speed ):
   circle( w, midpoint, radius ),
   speed( speed )
{}

void ball::update(){
   location += speed;
}

class window_mirror : public window {
private:
   window & w;
public:
   window_mirror( window & w ): 
      window( vector( w.size.x / 2, w.size.y ) ),
      w( w )
   {}
   
   void draw( const vector & pixel, bool v = true ) override {
      if( pixel.x <= ( w.size.x / 2 )){
         w.draw( pixel, v );
         w.draw( vector( ( w.size.x - 1 ) - pixel.x, pixel.y ), v );
      }   
   }
};

int main(){
   window_window w1( vector( 128, 64 ), 2 );
   auto w = window_mirror( w1 );
   ball b( w, vector( 10, 10 ), 8, vector( 2, 2 ));
   for(;;){
      w.clear();
      b.draw();
      wait_ms( 100 );
      b.update();
   }
}

