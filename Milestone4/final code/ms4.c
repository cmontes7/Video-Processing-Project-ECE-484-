void put_jtag(volatile int *, char ); // function prototype

/********************************************************************************
* This program demonstrates use of the JTAG UART port in the DE2 Basic Computer
*
* It performs the following:
* 1. sends a text string to the JTAG UART
* 2. reads character data from the JTAG UART
* 3. echos the character data back to the JTAG UART
********************************************************************************/
int main(void)
{
	/* Declare volatile pointers to I/O registers (volatile means that IO load and store
	instructions (e.g., ldwio, stwio) will be used to access these pointer locations) */
	volatile int * RS232_ptr = (int *) 0x10001010; // RS232 address
	volatile int * JTAG_UART_ptr = (int *) 0x10001000; // JTAG UART address
	
	volatile int * HEX0_ptr = (int *) 0x10000020; // HEX0 address
	volatile int * HEX1_ptr = (int *) 0x10000021; // HEX1 address
	
	int data;
	
	int count = 1;
	int dig1 = 0;
	/*
	int i;
	char text_string[ ] = "\nJTAG UART example code\n> \0";
	
	for (i = 0; text_string[i] != 0; ++i) // print a text string
		put_jtag (JTAG_UART_ptr, text_string[i] );
	*/
	
	/* read and echo characters */
	while(1)
	{
		data = *(RS232_ptr); // read the JTAG_UART Data register
		if (data & 0x00008000) // check RVALID to see if there is new data
		{	
			
			
			if(count == 1)
			{
				/*
				int i;
				char text_string[ ] = "\nfirst digit\n> \0";
					
				for (i = 0; text_string[i] != 0; ++i) // print a text string
					put_jtag (JTAG_UART_ptr, text_string[i] );			
				*/
				/* Display on the 7-segment display Most Significant Digit */
				if ((char) data == '0')
					*(HEX1_ptr) = 0b0111111; // 0 = 0b0111111
				else if ((char) data == '1')
					*(HEX1_ptr) = 0b0000110; // 1 = 0b0000110
				else if ((char) data == '2')
					*(HEX1_ptr) = 0b1011011; // 2 = 0b1011011
				else if ((char) data == '3')
					*(HEX1_ptr) = 0b1001111; // 3 = 0b1001111
				else if ((char) data == '4')
					*(HEX1_ptr) = 0b1100110; // 4 = 0b1100110
				else if ((char) data == '5')
					*(HEX1_ptr) = 0b1101101; // 5 = 0b1101101
				else if ((char) data == '6')
					*(HEX1_ptr) = 0b1111101; // 6 = 0b1111101
				else if ((char) data == '7')
					*(HEX1_ptr) = 0b0000111; // 7 = 0b0000111
				else if ((char) data == '8')
					*(HEX1_ptr) = 0b1111111; // 8 = 0b1111111
				else if ((char) data == '9')
					*(HEX1_ptr) = 0b1100111; // 9 = 0b1100111
				
				dig1 = *(HEX1_ptr);
				/* echo the character */
				put_jtag (JTAG_UART_ptr, (char) data & 0xFF );
				
				count = 0;
			}
			else
			{
				
				/* Display on the 7-segment display Least Significant Digit */
				if ((char) data == '0')
					*(HEX0_ptr) = 0b111111110111111; // 0 = 0b0111111
				else if ((char) data == '1')
					*(HEX0_ptr) = 0b111111110000110; // 1 = 0b0000110
				else if ((char) data == '2')
					*(HEX0_ptr) = 0b111111111011011; // 2 = 0b1011011
				else if ((char) data == '3')
					*(HEX0_ptr) = 0b111111111001111; // 3 = 0b1001111
				else if ((char) data == '4')
					*(HEX0_ptr) = 0b111111111100110; // 4 = 0b1100110
				else if ((char) data == '5')
					*(HEX0_ptr) = 0b111111111101101; // 5 = 0b1101101
				else if ((char) data == '6')
					*(HEX0_ptr) = 0b111111111111101; // 6 = 0b1111101
				else if ((char) data == '7')
					*(HEX0_ptr) = 0b111111110000111; // 7 = 0b0000111
				else if ((char) data == '8')
					*(HEX0_ptr) = 0b111111111111111; // 8 = 0b1111111
				else if ((char) data == '9')
					*(HEX0_ptr) = 0b111111111100111; // 9 = 0b1100111
				
				*(HEX1_ptr) = dig1; 
				
				/* echo the character */
				put_jtag (JTAG_UART_ptr, (char) data & 0xFF );
				*(JTAG_UART_ptr) = '\n';
				count = 1;
			}
		}
	}
}
/********************************************************************************
* Subroutine to send a character to the JTAG UART
********************************************************************************/
void put_jtag( volatile int * JTAG_UART_ptr, char c )
{
	int control;
	control = *(JTAG_UART_ptr + 1); // read the JTAG_UART Control register
	if (control & 0xFFFF0000) // if space, then echo character, else ignore
	{		
		*(JTAG_UART_ptr) = c;
	}
		
	//*(JTAG_UART_ptr) = '\n';
}
