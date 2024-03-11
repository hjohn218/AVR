/*
 * Final Project Three Player Buzzer.cpp
 *
 * Created: 2/9/2022 12:13:45 PM
 * Author : Heidi Johnson
 */ 

//defines the CPU frequency to 16MHz which is the clock speed.
#defines F_CPU	16000000L

//Libraries that are need to run the program
//Lets you program the pins, ports, etc.
#include <avr/io.h>
//Lets you delay the program or make it wait.
#include <util/delay.h>
//Lets you to write interrupts into the code
#include <avr/interrupt.h>




int main(void)
{
	while(1)
	{
		
	}
}	

/* make an array to save Sev Seg pin configuration of numbers
int num_array[10][7] = {  { 1,1,1,1,1,1,0 },    // 0
{ 0,1,1,0,0,0,0 },    // 1
{ 1,1,0,1,1,0,1 },    // 2
{ 1,1,1,1,0,0,1 },    // 3
{ 0,1,1,0,0,1,1 },    // 4
{ 1,0,1,1,0,1,1 },    // 5
{ 1,0,1,1,1,1,1 },    // 6
{ 1,1,1,0,0,0,0 },    // 7
{ 1,1,1,1,1,1,1 },    // 8
{ 1,1,1,0,0,1,1 }};   // 9
	



int main(void)
{
	// for input port-LED
	//Sets pins A0, A2, A4 as input pins
    DDRA=0b00010101;
	// for output port-Switch
	//Sets players buttons to output
    DDRA=0b00101010;
	//Sets reset button as output
	DDRD = 1<< 12;
	
	
    while (1) 
    {
		// checking the status of PIN, if it is '1', turns on the LED
		if(PINA==0x01)
		{
			// for debouncing of switch
			_delay_ms(1000); 
			 // Turning on the LED
			PORTD=0x01;  
		}//End of if(PINA ==0x01)
		// checking the status of PIN, if it is '0', turns off the LED
		else if(PINA==0x00)
		{
			// For debouncing of switch
			_delay_ms(1000  ); 
			// Turning off the LED
			PORTD=0x00;
		}//End of else if(PINA == 0x00)
    }//End of main event while loop
	
}//End of main function




//function header
void Num_Write(int);

void setup()
{
	// set pin modes
	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);
	pinMode(8, OUTPUT);
	
	
}//End of void setup() function for the pins

void loop()
{
	
	//counter loop
	
	for (int counter = 10; counter > 0; --counter)
	{
		delay(1000);
		Num_Write(counter-1);
	}
	delay(3000);
}//End of void loop() function

// this functions writes values to the sev seg pins
void Num_Write(int number)
{
	int pin= 2;
	for (int j=0; j < 7; j++) {
		digitalWrite(pin, num_array[number][j]);
		pin++;
	}
}
/*