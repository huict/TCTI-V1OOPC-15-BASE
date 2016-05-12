// ==========================================================================
//
// repeatedly print hello, prefixed with a sequence number
//
// This file is in the public domain.
//
// ==========================================================================

#include "hwlib.hpp"

int main( void ){	
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;

   for( int i = 1; ; ++i ){
      hwlib::wait_ms( 1000 );
      hwlib::cout 
         << hwlib::left << hwlib::setw( 5 ) << i 
         << " Hello world\n";  
   }   
   
}

