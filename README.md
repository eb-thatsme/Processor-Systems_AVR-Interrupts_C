#Processor-Systems_AVR-Interrupts_Assembly

This C project uses timer interrupts to create square waves and send data when uploaded to the ATmega324PB board (AVR Microcontroller). The two main files, along with descriptions, are:

**Activity 1**

Write a program to get data from Port B and send it to Port A continuously while an interrupt will do the following: Timer0 interrupt to create a square wave of 3kHz on PortD while sending data from PORTB to PORTA

**Activity 2**

Connect PB0 to PD2 (INT0) with a male-to-male connector and do the same for PB1 and PD3 (INT1). Whenever PB0 goes LOW (Ground), the contents of PORTA increase by one; and when PB1 goes LOW (Ground) the contents of PORTA decrease by one. When the value of PORTA is bigger than 10, PA7 goes high; otherwise it is low. 
