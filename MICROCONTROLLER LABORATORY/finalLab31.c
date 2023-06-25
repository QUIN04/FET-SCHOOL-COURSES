//sbit Switch at RA0_bit;           // Switch input pin
sbit LCD_RS at RB2_bit;           // LCD commands and data signals
sbit LCD_EN at RB3_bit;
sbit LCD_D4 at RB4_bit;
sbit LCD_D5 at RB5_bit;
sbit LCD_D6 at RB6_bit;
sbit LCD_D7 at RB7_bit;

sbit LCD_RS_Direction at RB2_bit;
sbit LCD_EN_Direction at RB3_bit;
sbit LCD_D4_Direction at RB4_bit;
sbit LCD_D5_Direction at RB5_bit;
sbit LCD_D6_Direction at RB6_bit;
sbit LCD_D7_Direction at RB7_bit;

void main() {
    char text1[] = "QUINUEL NDIP-AGBOR";  // Text to be displayed on line 1
    char text2[] = "FE21A300";            // Text to be displayed on line 2

    Lcd_Init();                         // Initialize the LCD module
    Lcd_Cmd(_LCD_CLEAR);                // Clear the display
    Lcd_Cmd(_LCD_CURSOR_OFF);           // Turn off the cursor

    while (1) {
                     // If the switch is pressed
           Lcd_Out(1, 1, text1);               // Display text1 on line 1
            Lcd_Out(2, 1, text2);               // Display text2 on line 2

        Delay_ms(1000);                 // Wait for 1 second
        Lcd_Cmd(_LCD_CLEAR);        // Clear the display
    }
}