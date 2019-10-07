#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

#define PIN_LED	(1<<13)

int main(void) {
	//rcc_clock_setup_in_hse_8mhz_out_72mhz();
	rcc_periph_clock_enable(RCC_GPIOC);

	gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, PIN_LED);
	gpio_set(GPIOC, PIN_LED);

	while(1) {
		/* wait a little bit */
		for (int i = 0; i < 800000; i++) {
			__asm__("nop");
		}
		
		gpio_toggle(GPIOC, PIN_LED);
	}
}
