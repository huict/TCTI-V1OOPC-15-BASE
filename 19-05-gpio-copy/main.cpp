// ==========================================================================
//
// copy switch at C.23 to LED at B.27
//
// This file is in the public domain.
//
// ==========================================================================

#include "hwlib.hpp"

int main( void ){	
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   auto led = hwlib::target::pin_in_out( 1, 27 );
   led.direction_set_output();

   auto sw = hwlib::target::pin_in_out( 2, 23 );
   sw.direction_set_input();

   while(1){
      led.set( ! sw.get() );
   }
}


