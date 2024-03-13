#include "uart_init.h"
// Function to send character over UART
void UART1_Sendchar(char c)
{
while( (LPC_UART1->LSR & LSR_THRE) == 0 ); // Block until tx empty

LPC_UART1->THR = c;

}

// ***********************
// Function to get character from UART
char UART1_Getchar()
{
char c;
while( (LPC_UART1->LSR & LSR_RDR) == 0 ); // Nothing received so just block
c = LPC_UART1->RBR; // Read Receiver buffer register
return c;
}
