// ==========================================================================
//
// toggle a led on B.27
// by a switch on C.23
//
// This file is in the public domain.
//
// ==========================================================================

#include "hwlib.hpp"

void blink( hwlib::pin_in_out & led ){
   led.direction_set_output();
   while(1){
      led.set( 1 );
      hwlib::wait_ms( 200 );
      led.set( 0 );
      hwlib::wait_ms( 200 );      
   }
}

int main( void ){	
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   auto led = hwlib::target::pin_in_out( 1, 27 );
   blink( led );
}

         

