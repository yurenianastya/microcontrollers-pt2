/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    uint8 register_value;
    
    for(;;)
    {
        register_value = Input_Buttons_Read();
        if(register_value == 0b00110 || register_value == 0b00011
            || register_value == 0b01001 || register_value == 0b01011 
            || register_value == 0b01010 || register_value == 0b00110 
            || register_value == 0b00101 || register_value == 0b01100) 
        {
            LED_pin_Write(1);
            CyDelay(500);
        } 
        else 
        {
            LED_pin_Write(0);
        }      
    }
}

/* [] END OF FILE */
