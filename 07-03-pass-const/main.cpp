void f( int & x ){}

int main(){
   const int x = 10;
   
   // f( x ); // compilation error
   // f( 3 + 5 ); // compilation error

   return 0;
}   