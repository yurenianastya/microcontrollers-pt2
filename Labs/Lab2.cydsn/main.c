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

uint8 counter;
CYBIT mode;

CY_ISR(timer_isr_interrupt) 
{
    
    if(counter++ >= 20) 
    {
        counter = 0;
    }
    Timer_Counter_ClearInterrupt(Timer_Counter_INTR_MASK_TC);
}

CY_ISR(button_isr_interrupt)
{
    mode = (mode == 0) ? 1 : 0;
    counter = 0;
    Button_1_ClearInterrupt();
}

int main(void)
{
    CyGlobalIntEnable; 
    
    timer_isr_StartEx(timer_isr_interrupt);
    button_isr_StartEx(button_isr_interrupt);
    Timer_Counter_Start();

    
    for(;;)
    {
        if (mode) 
        {
            switch(counter) 
            {
                case 0:
                Control_Reg_Write(0b100);
                break;
                case 6:
                Control_Reg_Write(0b110);
                break;
                case 8:
                Control_Reg_Write(0b001);
                break;
                case 13:
                Control_Reg_Write(0b000);
                break;
                case 14:
                Control_Reg_Write(0b001);
                break;
                case 15:
                Control_Reg_Write(0b000);
                break;
                case 16:
                Control_Reg_Write(0b001);
                break;
                case 17:
                Control_Reg_Write(0b010);
                break;
                default:
                break;
            }
        } 
        else 
        { 
            switch(counter) 
            {
                case 0:
                Control_Reg_Write(0b001);
                break;
                case 2:
                Control_Reg_Write(0b000);
                break;
                case 3:
                Control_Reg_Write(0b001);
                break;
                case 4:
                Control_Reg_Write(0b000);
                break;
                case 5:
                Control_Reg_Write(0b001);
                break;
                case 6:
                Control_Reg_Write(0b010);
                break;
                case 8:
                Control_Reg_Write(0b100);
                break;
                case 17:
                Control_Reg_Write(0b110);
                break;
                default:
                break;
            }
        }
    }
}

/* [] END OF FILE */
