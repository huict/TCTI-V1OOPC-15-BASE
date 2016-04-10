#include <iostream>

class vector {
public:
   int x;
   int y; 
   vector operator+( const vector & rhs ) const;
   vector & operator+=( const vector & rhs );
};

vector & vector::operator+=( const vector & rhs ){
   x += rhs.x;
   y += rhs.y;
   return *this;
}

vector vector::operator+( const vector & rhs ) const {
   vector temp = *this;
   temp += rhs;
   return temp;
}

int main(int argc, char **argv){  
   return 0;
}
