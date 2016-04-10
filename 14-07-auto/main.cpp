// example:
// always use & with the for loop variable

#include <stdio.h>


int main(){
   const int array_size = 100;
   int a[ array_size ];

   for( auto & x : a ){
      x = 5;  // a is changed
   }

   for( const auto & x : a ){
      // x = 5;  // compilation error
   }

   return 0;
}   

