#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

#define PIN_LED	(1<<13)

void delay_ms(uint32_t ms);

int main(void)
{
	//rcc_clock_setup_in_hse_8mhz_out_24mhz();
	rcc_periph_clock_enable(RCC_GPIOC);

	gpio_set_mode(GPIOC, 
		GPIO_MODE_OUTPUT_2_MHZ, 
		GPIO_CNF_OUTPUT_PUSHPULL, 
		PIN_LED);
	gpio_clear(GPIOC, PIN_LED);

	for(;;)
	{
		gpio_toggle(GPIOC, PIN_LED);
		delay_ms(1000);
	}

	return 0;
}

void delay_ms(uint32_t ms)
{
	uint32_t count;
	while(ms--)
	{
		for(count=0; count<800;count++);
	}
}