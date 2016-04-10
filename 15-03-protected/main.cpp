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

int main(int argc, char **argv){
   window w( 128, 64, 2 );
   
   ball b( w, vector( 30, 30 ), 20, vector( 10, 20 ) );
   b.draw();
   b.update();
   b.draw();
   
   return 0;
}
