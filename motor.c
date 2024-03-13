/*PWM code*/
#include "motor.h"

// function to get pwm for dc motor control
void pwm_init(uint32_t duty)
{
//int dutyCycle;
SystemInit();

LPC_SC->PCONP |= (1<<6);
LPC_SC->PCLKSEL0 |=(1<<13); //PWM clk=uc clk
/* configure for PWM1.4(3A) and PWM1.3(4A) */

LPC_PINCON->PINSEL3 |=(1<<11)|(1<<15); //3rd alternate fn for 3A

and 4A

/* Enable Counters,PWM module */
LPC_PWM1->TCR = (1<<SBIT_CNTEN) | (1<<SBIT_PWMEN);
LPC_PWM1->PR = 0x0; /* No Prescalar */
LPC_PWM1->MCR = (1<<SBIT_PWMMR0R); /*Reset on PWMMR0, reset TC if

it matches MR0 */

LPC_PWM1->MR0 = 100; /* set PWM cycle(Ton+Toff)=100) */
LPC_PWM1->MR1 = 50; /* Set 50% Duty Cycle for all four channels */
LPC_PWM1->MR2 = 50;
LPC_PWM1->MR3 = duty;
LPC_PWM1->MR4 = duty;
/* Trigger the latch Enable Bits to load the new Match Values */
LPC_PWM1->LER = (1<<SBIT_LEN0) | (1<<SBIT_LEN1) | (1<<SBIT_LEN2) |

(1<<SBIT_LEN3) | (1<<SBIT_LEN4);

/* Enable the PWM output pins for PWM_1-PWM_4(P2_0 - P2_3) */
LPC_PWM1->PCR = (1<<SBIT_PWMENA1) | (1<<SBIT_PWMENA2) |

(1<<SBIT_PWMENA3) | (1<<SBIT_PWMENA4);

}
