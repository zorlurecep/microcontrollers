/*********************************************************************************************************************
 *
 * FileName:        main.c
 * Processor:       PIC18F25K50
 * Compiler:        MPLAB� XC8
 * Comment:         Main code
 * Dependencies:    Header (.h) files if applicable, see below
 *
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Author                       Date                Version             Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Recep Omer Zorlu
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * TODO                         Date                Finished
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *********************************************************************************************************************/

/*
 * Includes
 */
#include <xc.h>

/*
 * Prototypes
 */
void initChip(void);

/*
 * Global Variables
 */
const unsigned char data[] = {8, 0, 21, 36, 0, 6, 56, 0, 0, 73, 48, 0, 23, 21, 53, 13, 8, 0, 36, 64, 43, 77, 78, 16, 83, 0, 0, 36, 25, 0, 77, 63, 0, 29, 0, 75, 0, 36, 0, 19, 10, 101, 0, 0, 102, 62, 16, 96, 104, 94, 48, 25, 71, 105, 22, 86, 1, 28, 0, 28, 6, 7, 45, 41, 36, 4, 42, 14, 5, 108, 38, 114, 50, 93, 119, 79, 81, 140, 56, 41, 27, 41, 53, 122, 103, 54, 65, 81, 103, 97, 80, 121, 31, 102, 116, 132, 81, 158, 64, 60, 129, 145, 65, 150, 44, 144, 109, 82, 166, 102, 173, 103, 131, 116, 150, 153, 175, 172, 91, 99, 157, 74, 180, 139, 150, 87, 143, 175, 84, 185, 123, 122, 165, 115, 180, 154, 147, 198, 191, 136, 134, 158, 118, 99, 109, 164, 203, 165, 177, 138, 133, 97, 110, 133, 217, 194, 194, 122, 147, 202, 207, 161, 136, 198, 168, 113, 160, 107, 119, 217, 158, 182, 133, 182, 115, 235, 215, 239, 151, 199, 240, 237, 226, 197, 224, 185, 222, 135, 204, 159, 190, 133, 202, 255, 157, 182, 145, 245, 236, 177, 157, 251, 214, 255, 173, 145, 175, 195, 147, 154, 209, 255, 193, 179, 243, 174, 178, 240, 175, 183, 255, 181, 186, 169, 177, 167, 252, 255, 247, 220, 188, 241, 255, 233, 255, 220, 255, 255, 229, 222, 255, 255, 251, 199, 255, 255, 255, 255, 255, 213, 216, 236, 241, 189, 255, 255, 215, 215, 239, 255, 194, 189, 206, 255, 251, 214, 255, 255, 255, 209, 192, 210, 255, 255, 255, 182, 232, 253, 205, 190, 255, 200, 237, 184, 255, 255, 230, 255, 224, 196, 209, 215, 242, 231, 182, 237, 158, 230, 241, 222, 182, 243, 162, 196, 225, 165, 225, 161, 230, 185, 186, 255, 200, 207, 243, 211, 203, 236, 204, 201, 211, 175, 145, 137, 248, 133, 142, 189, 208, 226, 148, 210, 162, 188, 175, 176, 125, 195, 185, 153, 190, 134, 141, 145, 174, 137, 213, 108, 223, 211, 223, 182, 209, 155, 104, 103, 211, 133, 160, 147, 136, 152, 145, 197, 152, 121, 84, 165, 100, 133, 84, 160, 183, 166, 96, 105, 156, 184, 191, 137, 79, 76, 149, 109, 105, 83, 164, 106, 160, 61, 147, 164, 70, 126, 71, 137, 65, 139, 99, 108, 126, 151, 53, 137, 171, 62, 47, 116, 118, 165, 85, 90, 114, 142, 105, 123, 154, 59, 118, 74, 148, 55, 133, 146, 145, 78, 144, 125, 100, 105, 56, 52, 42, 126, 129, 134, 132, 13, 112, 19, 18, 32, 44, 107, 8, 64, 24, 4, 39, 0, 52, 106, 40, 32, 105, 15, 86, 3, 117, 51, 0, 73, 25, 81, 74, 99, 0, 109, 62, 84, 19, 89, 52, 94, 90, 91, 45, 55, 69, 79, 78, 79, 0, 3, 0, 0, 57, 0, 59, 36, 32, 0, 5, 0, 0, 58, 0, 26, 67, 0, 0, 36, 0, 61, 0, 51, 0, 5, 0, 0, 3, 26};

/*
 * Functions
 */
void initChip(void) {
    //CLK settings
    OSCTUNE = 0x80; //3X PLL ratio mode selected
    OSCCON = 0x70; //Switch to 16MHz HFINTOSC
    OSCCON2 = 0x10; //Enable PLL, SOSC, PRI OSC drivers turned off
    //Comment following line of code out when simulating
    //while(OSCCON2bits.PLLRDY != 1); //Wait for PLL lock
    ACTCON = 0x90; //Enable active clock tuning for USB operation

    TRISA = 0b00000001; //Define PORTA as input  
    LATA = 0x00; //All output pins low
    ANSELA = 0b00000000; // define digital or analog
    ADCON1 = 0x00; //AD voltage reference           
    CM1CON0 = 0x00; //Turn off Comparator        

    TRISB = 0x00; //Define PORTB as output
    LATB = 0x00; //All output pins low

    TRISC = 0x00; //Define PORTC as output
    LATC = 0x00; //All output pins low

    // Defining these two pins to read from them. These are the button pins
    TRISCbits.RC0 = 1;
    TRISAbits.RA4 = 1;
}

void main() {
    unsigned char dataQueu[] = {0, 0, 0, 0, 0, 0, 0, 0};
    int counter = 0;
    char lastIndex = 0;
    unsigned char average = 0;

    initChip(); // Initialize all the PORTs and do some configurations

    while (1) // Endless loop : to make sure the program runs continuously
    {
        if (PORTCbits.RC0 == 0) {
            for (char i = 0; i < 8; i++) {
                dataQueu[i] = 0;
            }
            counter = 0;
            lastIndex = 0;
        }


        if (PORTAbits.RA4 == 1) {
            dataQueu[lastIndex] = data[counter];
            for (char i = 0; i < 8; i++) {
                // because 8 is a power of 2 we can simply shift every bit by 3 to divide it to 8
                average += dataQueu[i] >> 3;
            }
        } else {
            average = data[counter];
        }

        // First three bits are basically the led numbers we require. Only tricky part is that values that are power of 2 is a problem
        // they mess up the led count to fix that below if statement used. To indicate we are in between power of 2 and our range I use the below logic.
        if (((average & 16) >> 4) == 1) {
            LATB = (average >> 5) + 1;
        } else {
            LATB = average >> 5;
        }

        // This is a self implemented delay instead of __delay_ms()
        for (unsigned long i = 0; i < 100000; i++) {
        }

        // This logic is required for continues data supply
        counter++;
        if (counter >= 512) {
            counter = 0;
        }

        // This logic is used for handling dataQueue array index
        lastIndex++;
        if (lastIndex >= 8) {
            lastIndex = 0;
        }

        // average should be reset every time 
        average = 0;

    } // End of While loop
} // End of Main function