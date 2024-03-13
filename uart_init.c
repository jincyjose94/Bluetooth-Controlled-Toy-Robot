#include "uart_init.h"
// Function to set up UART
void UART1_Init(int baudrate)
{
int pclk;
unsigned long int Fdiv;

// PCLK_UART1 is being set to 1/4 of SystemCoreClock
pclk = SystemCoreClock / 4;

// Turn on power to UART1
LPC_SC->PCONP |= PCUART1_POWERON;

// Turn on UART1 peripheral clock
LPC_SC->PCLKSEL0 &= ~(PCLK_UART1_MASK);
LPC_SC->PCLKSEL0 |= (0 << PCLK_UART1); // PCLK_periph = CCLK/4
// Set PINSEL0 and PINSEL1 so that P0.15 = TXD1, P0.16 = RXD1
LPC_PINCON->PINSEL0 &= ~0xC0000000;
LPC_PINCON->PINSEL0 |= 0x40000000; // Enable TxD1 P0.15
LPC_PINCON->PINSEL1 &= ~0x00000003;
LPC_PINCON->PINSEL1 |= 0x00000001; // Enable RxD1 P0.16

LPC_UART1->LCR = 0x83; // 8 bits, no Parity, 1 Stop bit, DLAB=1
LPC_UART1->FDR = 0x20;
Fdiv = ( pclk / 16 ) / baudrate ; // Set baud rate
LPC_UART1->DLM = Fdiv / 256;
LPC_UART1->DLL = Fdiv % 256;
LPC_UART1->LCR = 0x03; // 8 bits, no Parity, 1 Stop bit DLAB= 0
LPC_UART1->FCR = 0x07; // Enable and reset TX and RX FIFO

}
