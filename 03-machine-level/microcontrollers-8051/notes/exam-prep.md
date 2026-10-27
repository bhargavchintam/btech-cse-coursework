# 8051 — Exam Preparation

The questions that keep coming back, grouped by unit. Marks in brackets. Programs mean
write the 8051 assembly (or embedded C where stated) with the algorithm and the result.

## Unit 1 — Introduction to Microcontrollers and the 8051

- Compare a microprocessor and a microcontroller with a table. (8 marks) — *asked in IA1*
- Distinguish Harvard and von Neumann architecture; state which the 8051 uses and why. (6 marks)
- List the key features of the 8051. (8 marks) — *repeated, 2017 paper*
- Compare the 8031, 8051 and 8052 (ROM, RAM, timers, interrupts). (6 marks)
- Explain the criteria for choosing a microcontroller for an embedded design. (8 marks)
- Draw and explain the internal block diagram of the 8051. (10 marks)

## Unit 2 — Architecture and Memory Organization

- Draw the 8051 pin diagram and explain EA, PSEN and ALE. (10 marks) — *asked in IA1*
- List the alternate functions of Port 3 pins. (6 marks)
- Explain the internal RAM organization (00H–7FH) with the three regions. (8 marks)
- Describe the four register banks and how RS1:RS0 select one. (6 marks)
- Draw the PSW and explain each flag bit. (8 marks) — *repeated*
- Find the bit address of bit 5 of byte 2AH. (4 marks)
- Explain the stack operation of the 8051; state the reset value of SP and the PUSH/POP order. (6 marks)

## Unit 3 — Addressing Modes

- List and explain the five addressing modes of the 8051 with one example each. (10 marks) — *asked in IA1, 2017 paper*
- Differentiate `MOV A, #40H` and `MOV A, 40H`. (4 marks)
- Explain register-indirect addressing; why only R0, R1 and DPTR can be pointers. (6 marks)
- Explain indexed addressing and `MOVC A, @A+DPTR` with a lookup-table example. (8 marks)
- Given R0 = 45H and RAM[45H] = AAH, give A after `MOV A, R0`, `MOV A, @R0`, `MOV A, 45H`. (6 marks)

## Unit 4 — Instruction Set

- Classify the 8051 instruction set into its groups with examples. (10 marks)
- Explain the data-transfer instructions MOV, MOVC, MOVX and XCH. (8 marks)
- Explain the rotate instructions RL, RLC, RR, RRC and SWAP with the effect on A and CY. (8 marks) — *asked in IA2*
- Explain the bit/Boolean instructions SETB, CLR, CPL, JB, JNB and the carry-logic instructions. (8 marks)
- Explain CJNE and DJNZ and their effect on the carry and the program flow. (6 marks)

## Unit 5 — Assembly Programming

- Explain the use of assembler directives ORG, DB, DW, EQU and END. (6 marks)
- Write a program to copy a block of N bytes from one location to another. (8 marks) — *asked in IA2*
- Write a program to toggle all bits of Port 1 continuously. (6 marks)
- Write a delay subroutine and explain how the delay is calculated. (8 marks)
- Write a program to find the sum of the first N natural numbers. (8 marks)
- Explain how a subroutine is called and how ACALL/LCALL differ from AJMP/LJMP. (6 marks)

## Unit 6 — Arithmetic Programs

- Write a program for 8-bit addition of two numbers with carry. (8 marks) — *repeated*
- Write a program for 16-bit addition of two numbers. (8 marks) — *asked in IA2, 2017 paper*
- Write a program for 8-bit subtraction; explain why CLR C is needed before SUBB. (8 marks)
- Explain MUL AB and DIV AB, stating where the result and remainder go. (6 marks)
- Write a program to multiply two 8-bit numbers and store the 16-bit product. (8 marks)
- Explain DA A and add the packed-BCD numbers 59 and 48. (6 marks)

## Unit 7 — Data Manipulation

- Write a program to arrange N bytes in ascending order (bubble sort). (10 marks) — *asked in IA2*
- Write a program to arrange N bytes in descending order. (8 marks)
- Write a program to find the largest number in an array. (8 marks) — *repeated*
- Write a program to find the smallest number in an array. (8 marks)
- Write a program to count the even and odd numbers in a block. (8 marks)

## Unit 8 — Timers and Counters

- Explain the TMOD register with the meaning of each bit. (8 marks) — *asked in IA2*
- Explain the four timer modes (0–3). (8 marks) — *repeated, 2017 paper*
- Explain the TCON register bits. (6 marks)
- Find the reload value for a 1 ms delay on Timer0 in mode 1 at 12 MHz; give TH0, TL0. (6 marks)
- Write a program to generate a 1 kHz square wave on P1.0 using Timer0. (10 marks)
- Write a program to generate a 1 second delay using Timer0. (8 marks)

## Unit 9 — Serial Communication

- Explain the SCON register and the four serial modes. (8 marks)
- Explain how Timer1 mode 2 generates the baud rate; derive TH1 for 9600 baud at 11.0592 MHz. (8 marks) — *asked in IA2*
- Differentiate synchronous and asynchronous, and serial and parallel communication. (6 marks)
- Explain the framing of a serial byte — start bit, data bits, parity, stop bit. (6 marks)
- Write a program to transmit the character 'A' serially at 9600 baud. (8 marks) — *repeated*
- Write a program to receive a byte serially and send it to Port 1. (8 marks)

## Unit 10 — Interrupts and Interfacing

- Explain the interrupt sources of the 8051 and their vector addresses. (8 marks) — *repeated, 2017 paper*
- Explain the IE and IP registers and how interrupt priority works. (8 marks)
- Write a program using Timer0 interrupt to toggle a pin. (8 marks) — *asked in IA2*
- Interface an LED / seven-segment display to a port and display 0–9. (10 marks)
- Interface a stepper motor to the 8051 and explain the step sequence. (10 marks)
- Explain interfacing an ADC / DAC to the 8051. (8 marks)
