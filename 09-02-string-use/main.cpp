#include <iostream>
#include <string>

int main(int argc, char **argv){
   std::string s = "hallo";
   if(( s == "hallo" ) && ( "hallo" == s )){
      std::cout << "yes\n";
   }
   s[ 1 ] = 'e';
   std::string w = s + " world";
   std::cout << w + '\n';

   s[ 11 ] = 'x';
   s.at( 11 ) = 'x';
   
  std::cout << s << '\n';
   
}



