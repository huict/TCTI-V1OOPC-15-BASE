// example:
// passing a parameter that is modified by the called funcion
// C: pass a pointer
// C++: pass a reference

#include <iostream>

// C versie 
void c_add( int * p, int n ){
   *p = *p + n;
   // p[ 5 ] = 10; // totale onzin, maar wel legaal C
}

// C++ versie 
void add( int & m, int n ){
   m = m + n;
   // m[ 5 ] = 10; // compilatiefout
}

int main(int argc, char **argv){
   int n = 10;
   
   c_add( &n, 5 );
   std::cout << "n=" << n << "\n";
   
   n = 10;
   add( n, 5 );
   std::cout << "n=" << n << "\n";
   
   return 0;
}
