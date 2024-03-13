/*PWM code*/
#include "LPC17xx.h"

#define SBIT_CNTEN 0
#define SBIT_PWMEN 2
#define SBIT_PWMMR0R 1
#define SBIT_LEN0 0
#define SBIT_LEN1 1
#define SBIT_LEN2 2
#define SBIT_LEN3 3
#define SBIT_LEN4 4
#define SBIT_PWMENA1 9
#define SBIT_PWMENA2 10
#define SBIT_PWMENA3 11
#define SBIT_PWMENA4 12

// function to get pwm for dc motor control
void pwm_init(uint32_t duty);
