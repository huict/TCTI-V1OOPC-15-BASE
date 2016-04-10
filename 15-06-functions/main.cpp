#include <iostream>

class animal { 
public:
   void print(){ std::cout << "I am an animal.\n"; }
};

class duck : public animal {
public:   
   void print(){ std::cout << "I am a duck.\n"; }
};

void f( animal & x ){
   x.print();
}

int main(){
   animal    a;
   duck      d;

   a.print();   // I am an animal
   d.print();   // I am a duck

   animal & ar = d;
   ar.print();  // I am an animal  <======== !!

   animal *ap = & d;
   ap->print(); // I am an animal  <======== !!
   
   f( a );      // I am an animal
   f( d );      // I am an animal  <======== !!   
}

