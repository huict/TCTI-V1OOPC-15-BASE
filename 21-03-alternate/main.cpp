#include "hwlib.hpp"

class pin_out_invert : public hwlib::pin_out {
private:
   hwlib::pin_out & slave;
   
public:
   pin_out_invert( hwlib::pin_out & slave ): 
      slave( slave ){}
   
   void set( bool x ) override {
      slave.set( ! x );
   }  
};

class pin_out_all : public hwlib::pin_out {
private:
   hwlib::pin_out * list[ 4 ];     
   
public:

   pin_out_all( 
      hwlib::pin_out & p0, 
      hwlib::pin_out & p1 = hwlib::pin_out_dummy,  
      hwlib::pin_out & p2 = hwlib::pin_out_dummy, 
      hwlib::pin_out & p3 = hwlib::pin_out_dummy 
   ):
      list{ &p0, &p1, &p2, &p3 }
   {}
   
   void set( bool v ){
      for( auto p  : list ){
          p->set( v );
      }
   }
};

int main( void ){	
    
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   namespace target = hwlib::target;
   
   auto led0     = target::pin_out( target::pins::d7 );
   auto led1     = target::pin_out( target::pins::d6 );
   auto led2_pin = target::pin_out( target::pins::d5 );
   auto led3_pin = target::pin_out( target::pins::d4 );
   
   auto led2     = pin_out_invert( led2_pin );
   auto led3     = pin_out_invert( led3_pin );
   
   auto leds = pin_out_all( led0, led1, led2, led3 );
   
   hwlib::blink( leds, 500 );    
}
