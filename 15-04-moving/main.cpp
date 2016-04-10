#include "window.hpp"
#include "circle.hpp"

class ball : public circle {
private:
   vector speed;
public:
   ball( window & w, const vector & midpoint, int radius, const vector & speed );
   void update();
};

void ball::update(){
   midpoint += speed;
}

ball::ball( window & w, const vector & midpoint, int radius, const vector & speed ):
   circle( w, midpoint, radius ),
   speed( speed )
{}

int main(){
   window w( vector( 128, 64 ), 2 );
   ball b( w, vector( 10, 10 ), 8, vector( 2, 2 ));
   for(;;){
      w.clear();
      b.draw();
      wait_ms( 100 );
      b.update();
   }
}

