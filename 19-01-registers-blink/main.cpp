// ==========================================================================
//
// blink a led on PIOB pin 27 == arduino-due on-board LED
//
// This file is in the public domain.
//
// ==========================================================================

#include "sam.h"

int main( void ){	
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   // make the GPIO pin an output
   PIOB->PIO_OER = 0x01 << 27;
   
   for(;;){
      
      // make the GPIO pin high
      PIOB->PIO_SODR = 0x01 << 27;
         
      // wait some time
      for( volatile int i = 0; i < 100'000; i++ ){}
      
      // make the GPIO pin low
      PIOB->PIO_CODR = 0x01 << 27;
         
      // again, wait some time
      for( volatile int i = 0; i < 100'000; i++ ){}
      
   } 
}

