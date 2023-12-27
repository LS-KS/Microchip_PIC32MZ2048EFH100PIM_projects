/*******************************************************************************
* Main Source File
*
* Company:
*  Drukon Druck-Kontrolltechnik GmbH
*
* File Name:
*  main.c
*
* Summary:
*  This file contains the "main" function for a project.
*
* Description:
*  This is the main file of the test project.
*
*  Used Hardware:
*  PIC32MZ2048EFH100 on PIM together with
*  EXPLORER 16/32 devboard.
*  This Project uses switches S4 to S6 on the explorer board and toggles LEDs
*  D3 to D10 depending on the pushed buttons.
*  Uses Core timer functions for delay.
*  work.
*
*  Tried to use RNG module to toggle LEDs randomly but couldn't bring that to
*
*  This Project is created by Harmony v3.
*******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes


// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

/**
 * @brief Selects an LED number based on the given number and increment.
 *
 * This function takes a number representing the current LED Pin and an increment.
 * It adds the increment to the current number and performs a cyclic wrap-around
 * within the range [0, 6] to select the next LED.
 *
 * @param rng The current LED number.
 * @param incr The increment to be added to the current LED number.
 *
 * @return The selected LED number after applying the increment and ensuring it
 *         stays within the range [0, 6].
 */
int selectLED(int rng, int incr){
    rng += incr;
    if (rng > 6){
        rng = 0;
    }else if(rng < 0){
        rng = 6;
    }
    return rng;
}

int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    
    /* Initialize custom variables*/
    int rng = 0; // index for LED toggling
    uint32_t delay = 50; // delay after LED toggling using core timer. 
    
    /* Main Loop*/
    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
        
        /* Checks if Button S4 or S5 is pressed
         * Increases LED index if S4 is pressed
         */
        if ( BUTTON_SWITCH_S4_Get() == 0){
           rng = selectLED(rng, -1);
        } else if(BUTTON_SWITCH_S6_Get() == 0){
            rng = selectLED(rng, 1);
        }
        switch(rng){
            case 0:
                LED_D3_Set();
                LED_D4_Clear();
                LED_D5_Clear();
                LED_D6_Clear();
                LED_D7_Clear();
                LED_D8_Clear();
                LED_D9_Clear();
                break;
            case 1:
                LED_D3_Clear();
                LED_D4_Set();
                   LED_D5_Clear();
                   LED_D6_Clear();
                   LED_D7_Clear();
                   LED_D8_Clear();
                   LED_D9_Clear();
                   break;
               case 2:
                   LED_D3_Clear();
                   LED_D4_Clear();
                   LED_D5_Set();
                   LED_D6_Clear();
                   LED_D7_Clear();
                   LED_D8_Clear();
                   LED_D9_Clear();
                   break;
               case 3:
                   LED_D3_Clear();
                   LED_D4_Clear();
                   LED_D5_Clear();
                   LED_D6_Set();
                   LED_D7_Clear();
                   LED_D8_Clear();
                   LED_D9_Clear();
                   break;
               case 4:
                   LED_D3_Clear();
                   LED_D4_Clear();
                   LED_D5_Clear();
                   LED_D6_Clear();
                   LED_D7_Set();
                   LED_D8_Clear();
                   LED_D9_Clear();
                   break;
               case 5:
                   LED_D3_Clear();
                   LED_D4_Clear();
                   LED_D5_Clear();
                   LED_D6_Clear();
                   LED_D7_Clear();
                   LED_D8_Set();
                   LED_D9_Clear();
                   break;
               case 6:
                   LED_D3_Clear();
                   LED_D4_Clear();
                   LED_D5_Clear();
                   LED_D6_Clear();
                   LED_D7_Clear();
                   LED_D8_Clear();
                   LED_D9_Set();
                   break;
               default:
                   LED_D3_Clear();
                   LED_D4_Clear();
                   LED_D5_Clear();
                   LED_D6_Clear();
                   LED_D7_Clear();
                   LED_D8_Clear();
                   LED_D9_Clear();
                   break;
           }
           CORETIMER_DelayMs(delay);
        
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

