#include <iostream>

void f( char *s ){
   char copy[ 100 ];
   for( int i = 0; s[ i ] != '\0'; ++i ){
      copy[ i ] = s[ i ];
   }
   std::cout << "[" << copy << "]\n";
}

int main(int argc, char **argv){
   f( "hello" );

   return 0;
}

