/*******************************************************************************
* File Name: LED_Yellow.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_LED_Yellow_H) /* Pins LED_Yellow_H */
#define CY_PINS_LED_Yellow_H

#include "cytypes.h"
#include "cyfitter.h"
#include "LED_Yellow_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} LED_Yellow_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   LED_Yellow_Read(void);
void    LED_Yellow_Write(uint8 value);
uint8   LED_Yellow_ReadDataReg(void);
#if defined(LED_Yellow__PC) || (CY_PSOC4_4200L) 
    void    LED_Yellow_SetDriveMode(uint8 mode);
#endif
void    LED_Yellow_SetInterruptMode(uint16 position, uint16 mode);
uint8   LED_Yellow_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void LED_Yellow_Sleep(void); 
void LED_Yellow_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(LED_Yellow__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define LED_Yellow_DRIVE_MODE_BITS        (3)
    #define LED_Yellow_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - LED_Yellow_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the LED_Yellow_SetDriveMode() function.
         *  @{
         */
        #define LED_Yellow_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define LED_Yellow_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define LED_Yellow_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define LED_Yellow_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define LED_Yellow_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define LED_Yellow_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define LED_Yellow_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define LED_Yellow_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define LED_Yellow_MASK               LED_Yellow__MASK
#define LED_Yellow_SHIFT              LED_Yellow__SHIFT
#define LED_Yellow_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in LED_Yellow_SetInterruptMode() function.
     *  @{
     */
        #define LED_Yellow_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define LED_Yellow_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define LED_Yellow_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define LED_Yellow_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(LED_Yellow__SIO)
    #define LED_Yellow_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(LED_Yellow__PC) && (CY_PSOC4_4200L)
    #define LED_Yellow_USBIO_ENABLE               ((uint32)0x80000000u)
    #define LED_Yellow_USBIO_DISABLE              ((uint32)(~LED_Yellow_USBIO_ENABLE))
    #define LED_Yellow_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define LED_Yellow_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define LED_Yellow_USBIO_ENTER_SLEEP          ((uint32)((1u << LED_Yellow_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << LED_Yellow_USBIO_SUSPEND_DEL_SHIFT)))
    #define LED_Yellow_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << LED_Yellow_USBIO_SUSPEND_SHIFT)))
    #define LED_Yellow_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << LED_Yellow_USBIO_SUSPEND_DEL_SHIFT)))
    #define LED_Yellow_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(LED_Yellow__PC)
    /* Port Configuration */
    #define LED_Yellow_PC                 (* (reg32 *) LED_Yellow__PC)
#endif
/* Pin State */
#define LED_Yellow_PS                     (* (reg32 *) LED_Yellow__PS)
/* Data Register */
#define LED_Yellow_DR                     (* (reg32 *) LED_Yellow__DR)
/* Input Buffer Disable Override */
#define LED_Yellow_INP_DIS                (* (reg32 *) LED_Yellow__PC2)

/* Interrupt configuration Registers */
#define LED_Yellow_INTCFG                 (* (reg32 *) LED_Yellow__INTCFG)
#define LED_Yellow_INTSTAT                (* (reg32 *) LED_Yellow__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define LED_Yellow_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(LED_Yellow__SIO)
    #define LED_Yellow_SIO_REG            (* (reg32 *) LED_Yellow__SIO)
#endif /* (LED_Yellow__SIO_CFG) */

/* USBIO registers */
#if !defined(LED_Yellow__PC) && (CY_PSOC4_4200L)
    #define LED_Yellow_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define LED_Yellow_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define LED_Yellow_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define LED_Yellow_DRIVE_MODE_SHIFT       (0x00u)
#define LED_Yellow_DRIVE_MODE_MASK        (0x07u << LED_Yellow_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins LED_Yellow_H */


/* [] END OF FILE */
