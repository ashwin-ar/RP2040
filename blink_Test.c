//To understand and test cmake, testing with LED Blink 
#include <stdio.h>
#include "pico/stdlib.h" //this is to configure clock and all initial things,
#include "hardware/gpio.h" //this is to include gpio i.e sio & iobank reg
#include "hardware/timer.h"

#define pin_number 25

void delay_ms_ip (uint64_t ms){
        uint64_t start = timer_hw->timerawl;
        while (timer_hw->timerawl - start < ms) {
            tight_loop_contents();}
	return;
}

void main(){
	stdio_init_all();
		//SIO:GPIO_OE Register
		sio_hw -> gpio_oe &= ~(0xffff);
		sio_hw -> gpio_oe |= 1u << pin_number;
		//IO_BANK0:GPIO25_STATUS
		iobank0_hw -> io[pin_number].ctrl = 5 << IO_BANK0_GPIO0_CTRL_FUNCSEL_LSB ; //5<<0
		//SIO:GPIO_OUT Register
		sio_hw -> gpio_clr = 0xffff;
	while(1){
		sio_hw -> gpio_clr |= 1<<pin_number; //also can be written as sio -> gpio_set = 1<<pin_number;	
		delay_ms_ip(1000); 
		sio_hw -> gpio_set |= 1<< pin_number; //also can be written as sio -> gpio_set = 1<<pin_number;
		delay_ms_ip(1000);
		}
	return ;
}