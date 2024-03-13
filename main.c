/*main program*/
#include "functions.h"

#include <cr_section_macros.h>
#include <NXP/crp.h>
#include "LPC17xx.h"

// Variable to store CRP value in. Will be placed automatically
// by the linker when "Enable Code Read Protect" selected.
// See crp.h header for more information
__CRP const unsigned int CRP_WORD = CRP_NO_CRP ;

int main(void)
{
SystemInit();
port_init();
UART1_Init(9600);
char ch;
pwm_init(50);

LPC_GPIO2->FIODIR=0XFF; //P2 is output
while(1)
{
UART1_Sendchar('A'); //Transmit "a" char
ch=UART1_Getchar();
LPC_GPIO2->FIOPIN0 = ch;
LPC_PWM1->MR3 = 25;
LPC_PWM1->MR4 = 25;
/* Trigger the latch Enable Bits to load the new Match Values */
LPC_PWM1->LER = (1<<0) | (1<<1) | (1<<2) | (1<<3) | (1<<4);
delay_ms(5);

}

return 0;
}

