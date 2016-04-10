#include "window.hpp"
#include "circle.hpp"

class ball {
private:
   window & w;
   vector midpoint;
   int radius;
   vector speed;
public:
   ball( window &w, vector midpoint, int radius, vector speed );
   void draw();
   void update();
};

void ball::update(){
   midpoint += speed;
}

ball::ball( window &w, vector midpoint, int radius, vector speed ):
   w( w ),
   midpoint( midpoint ),
   radius( radius ),
   speed( speed )
{}

void ball::draw(){
   circle c( w, midpoint, radius );
   c.draw();
}


int main(int argc, char **argv){
   window w( 128, 64, 2 );
   
   ball b( w, vector( 30, 30 ), 20, vector( 10, 20 ) );
   b.draw();
   b.update();
   b.draw();
   
   return 0;
}
