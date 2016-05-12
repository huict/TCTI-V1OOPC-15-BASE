// ==========================================================================
//
// toggle a led on B.27
// by a switch on C.23
//
// This file is in the public domain.
//
// ==========================================================================

#include "hwlib.hpp"

int main( void ){	
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   auto led0 = hwlib::target::pin_out( hwlib::target::pins::d7 );
   auto led1 = hwlib::target::pin_out( hwlib::target::pins::d6 );
   auto led2 = hwlib::target::pin_out( hwlib::target::pins::d5 );
   auto led3 = hwlib::target::pin_out( hwlib::target::pins::d4 );
   
   for(;;){
      led0.set( 1 ); hwlib::wait_ms( 80 ); led0.set( 0 ); 
      led1.set( 1 ); hwlib::wait_ms( 80 ); led1.set( 0 ); 
      led2.set( 1 ); hwlib::wait_ms( 80 ); led2.set( 0 ); 
      led3.set( 1 ); hwlib::wait_ms( 80 ); led3.set( 0 ); 
      led2.set( 1 ); hwlib::wait_ms( 80 ); led2.set( 0 ); 
      led1.set( 1 ); hwlib::wait_ms( 80 ); led1.set( 0 ); 
   }
}

         

