
/* Embedded Xinu, Copyright (C) 2009.  All rights reserved. */

#ifndef _BEAGLEBONE_GPIO_H_
#define _BEAGLEBONE_GPIO_H_

#define GPIO0_START_ADDR 0x44E07000     //GPIO chip 0 base address
#define GPIO1_START_ADDR 0x4804C000     //GPIO chip 1 base address
#define GPIO2_START_ADDR 0x481AC000     //GPIO chip 2 base address
#define GPIO3_START_ADDR 0x481AE000     //GPIO chip 3 base address

#define ADC_BASE_ADDR 0x44E0D000        //BBB ADC base address
#define FIFO0_ADDR_OFFSET 0x40          //BBB FIFO Queue base address
#define STEP_EN_REG 0x15                //Step Enable Register Offset 
#define STEP_CON_1 0x19                 //Step Config Register
#define STEP_DEL_1 0x20                 //
#define ADC_CNTRL_REG_ADDR 0x10         
#define CON_FIFO0 (1<<26)
#define STEP_EN_1 (1<<1)                
#define PRU_ICSS_CFG 0x00026000
#define SYS_CFG 0x4
#define OCP (1<<4)
#define TMR4_ADDR 0x44E10890
#define ADC_EVT_CAP_ADDR 0x44E10FD8
#define FIFO0_ADDR 0x44E0D100
#define FIFO_COUNT_ADDR 0x44E0D0E4
#define STEP_CONF_ADDR 0x44E0D064
#define STEP_DELAY_ADDR 0x44E0D068
#define STEP_ENABLE_ADDR 0x44E0D054
#define CNTRL_ADDR 0x44E0D040           //Control Register Address
#define CLK_MDL 0x44E004BC              
#define CLK_MDL_T4 0x44E00088
#define ADC_STAT 0x44E0D044

#define PIN9_12_ADDR (1<<28)

#define GPIO_OE 0x14d                   //GPIO Output Enable offset
#define GPIO_IN 0x14e                   //GPIO DataInput offset
#define GPIO_OUT 0x14f                  //GPIO DataOutput Offset

#define USR0_LED (1<<21)                //Onboard LED 1 Pin Offset
#define USR1_LED (1<<22)                //Onboard LED 2 Pin Offset
#define USR2_LED (1<<23)                //Onboard LED 3 Pin Offset
#define USR3_LED (1<<24)                //Onboard LED 4 Pin Offset

#endif                          /* _GPIO_H_ */
