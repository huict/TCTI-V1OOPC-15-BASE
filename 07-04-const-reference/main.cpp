void f( const int & x ){}

void g( const int & x ){
   // x = 7; // compilation error
}

int main(){
   const int x = 10;
   
   f( x );     // OK
   f( 3 + 5 ); // OK

   return 0;
}   
 