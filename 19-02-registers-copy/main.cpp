// ==========================================================================
//
// copy switch at C.23 to LED at B.27
//
// This file is in the public domain.
//
// ==========================================================================

#include "sam.h"

int main( void ){	
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   // enable the clock to all GPIO
   PMC->PMC_PCER0 = ( 0x3F << 11 );   
   
   // make the GPIO pin an output
   PIOB->PIO_OER = 0x01 << 27;
   
   for(;;){
         
      // check whether the switch is pressed      
      if (( PIOC->PIO_PDSR & ( 0x01 << 23 )) == 0 ){
         
         // make the GPIO pin high
         PIOB->PIO_SODR = 0x01 << 27;
         
      } else {
         
         // make the GPIO pin low
         PIOB->PIO_CODR = 0x01 << 27;
         
      }
   } 
}

