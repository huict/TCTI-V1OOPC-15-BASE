class abstract { 
public:
   virtual void draw() = 0;
};

class concrete : public abstract {
public:
   void draw() override {}
};

int main(int argc, char **argv){
   
   //abstract obj;  // ERROR: object is abstract
   //obj.draw();    // and what would this call anyway?   
   
   concrete brick;
   brick.draw();    // call the concrete draw()

   abstract * p = & brick;
   p->draw();       // again, call the concrete draw
   
   return 0;
}
