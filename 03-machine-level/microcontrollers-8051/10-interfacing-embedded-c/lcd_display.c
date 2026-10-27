// initialise a 16x2 HD44780 LCD and write a short string
// data bus on port 2, control lines RS/RW/EN on port 3
#include <8051.h>

#define RS P3_0
#define RW P3_1
#define EN P3_2

void delay(unsigned int n)
{
    unsigned int i;
    while (n--)
        for (i = 0; i < 120; i++);
}

void enable(void)
{
    EN = 1;
    delay(1);
    EN = 0;      // LCD latches the bus on the high->low edge
    delay(1);
}

void lcd_cmd(unsigned char c)
{
    P2 = c;
    RS = 0;      // command register
    RW = 0;      // write
    enable();
}

void lcd_data(unsigned char d)
{
    P2 = d;
    RS = 1;      // data register
    RW = 0;
    enable();
}

void lcd_init(void)
{
    lcd_cmd(0x38);   // 8-bit, 2 lines, 5x7 font
    lcd_cmd(0x0E);   // display on, cursor on
    lcd_cmd(0x01);   // clear display
    lcd_cmd(0x06);   // auto-increment cursor
    lcd_cmd(0x80);   // line 1, column 0
}

void lcd_puts(__code const char *s)
{
    while (*s)
        lcd_data(*s++);
}

void main(void)
{
    lcd_init();
    lcd_puts("HELLO 8051");
    while (1)
        ;            // hold the message
}
