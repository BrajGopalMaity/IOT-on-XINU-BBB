
/* Embedded Xinu, Copyright (C) 2009.  All rights reserved. */

#include <gpio.h>
#include <xinu.h>
#include <stddef.h>

shellcmd xsh_led(int nargs, char *args[])
{
	uint32 led;                  /* led to control */
	uint32 gpio_addr = 0;
	volatile unsigned *adc_addr = NULL;
	volatile unsigned *tmr_addr = (volatile unsigned*)(0x44E10890);
	volatile unsigned *adc_evnt_addr = (volatile unsigned*)(0x44E10FD8);
	volatile unsigned *fifo_addr = (volatile unsigned*)(0x44E0D100);
	volatile unsigned *fifo_count = (volatile unsigned*)(0x44E0D0E4);
	volatile unsigned *step_con = (volatile unsigned*)(0x44E0D064);
	volatile unsigned *adc_stat_addr = (volatile unsigned*)(0x44E0D044);
	volatile unsigned *step_del = (volatile unsigned*)(0x44E0D068);
	volatile unsigned *step_en = (volatile unsigned*)(0x44E0D054);
	volatile unsigned *cntrl_addr = (volatile unsigned*)(0x44E0D040);
	volatile unsigned *sys_cfg = (volatile unsigned*)(0x00026004);
	volatile unsigned *clk_mdl = (volatile unsigned*)(0x44E004BC);
	volatile unsigned *clk_mdl_t4 = (volatile unsigned*)(0x44E00088);
	volatile unsigned *gpio_oe_addr = NULL;
	volatile char *gpio_setdataout_addr = NULL;
	volatile char *gpio_cleardataout_addr = NULL;
	uint32 yy;

	gpio_addr = (uint32)GPIO1_START_ADDR;
	adc_addr = (volatile unsigned*)ADC_BASE_ADDR;
	//uint32 creg = *(gpio_addr + GPIO_OE);
//	creg = creg & (~USR0_LED);
//	creg = creg & (~USR1_LED);
//	creg = creg & (~USR2_LED);
//	creg = creg & (~USR3_LED);

	//gpio_oe_addr = (char*)(GPIO1_START_ADDR | GPIO_OE );
	//gpio_setdataout_addr = (char*)(GPIO1_START_ADDR | GPIO_SETDATAOUT );
	//gpio_cleardataout_addr = (char*)(GPIO1_START_ADDR | GPIO_CLEARDATAOUT);

	//yy = (uint32)gpio_oe_addr + 21;
	//gpio_oe_addr =  (char *)yy;
	//printf("0x%X ",*(gpio_addr + GPIO_OE));
	//*gpio_oe_addr = *(gpio_addr + GPIO_OE) & (~USR0_LED); 
//	*(gpio_addr + GPIO_OE) = creg;
	//printf("0x%8x 0x%X 0x%X ", (gpio_addr + GPIO_OE), *(gpio_addr + GPIO_OE),USR0_LED);

	/* Output help, if '--help' argument was supplied */
	if (nargs == 2 && strncmp(args[1], "--help", 7) == 0)
	{
		printf("Usage: %s <DESCRIPTOR> <STATE>\n\n", args[0]);
		printf("Description:\n");
		printf("\tTurns a specified led on or off.\n");
		printf("Options:\n");
		printf("\t<DESCRIPTOR>\tuser0, user1, user2, user3\n");
		printf("\t<STATE>\t\ton, off\n");
		printf("\t--help\t\tdisplay this help and exit\n");
		return 0;
	}
	
	
	///* Check for correct number of arguments */
	if (nargs < 3)
	{
		fprintf(stderr, "%s: missing operand\n", args[0]);
		fprintf(stderr, "Try '%s --help' for more information\n",
		args[0]);
		return 1;
	}
	if (nargs > 3)
	{
		fprintf(stderr, "%s: too many arguments\n", args[0]);
		fprintf(stderr, "Try '%s --help' for more information\n",
		args[0]);
		return 1;
	}
	
	
		

	//led = 0;
	/* find led to change */
	if (strncmp(args[1], "user0", 5) == 0)
	{
		//led = 0;
		//uint32 creg=*(gpio_addr + GPIO_IN);
		//fprintf(stderr, "0x%8x",creg);
		//lsensor_read(gpio_addr,28);
		int flag=0;
		int exit=0;
		while(1)
		{
			if(lread(0))
			{
				flag=1;
				lwrite(0,"on");
			}
			else if(flag==1)
			{
				exit++;
				lwrite(0,"off");
				flag=0;
			}
			if(exit==10)
			{
				lwrite(0,"off");
				break;
			}
		}
		//lwrite(0,"on");
	}
	else if (strncmp(args[1], "user1", 5) == 0)
	{
		uint32 creg=lread(1);
		kprintf("Fi - %d",creg);
		//led = 1;
		//*(gpio_addr + GPIO_IN)=*(gpio_addr + GPIO_IN)&0;
		//*(sys_cfg) &= ~(OCP);
	/*	*(clk_mdl)&= 0xFFFFFFF0;
		*(clk_mdl) |= 0x2;
		*(clk_mdl_t4)&= 0xFFFFFFF0;
		*(clk_mdl_t4) |= 0x2;
		sleep(1);
		uint32 creg2=*(cntrl_addr);
		creg2 |= 5;
		creg2 &= ~(1<<9);
		*(cntrl_addr)=creg2;
		kprintf("stpenAdd - ");
		*(step_en) |= STEP_EN_1;
		*(step_con ) &= ~(CON_FIFO0);
		*(step_con ) >>2;
		*(step_con ) <<2;
		*(step_con ) |= 1;
	//	kprintf("2");
		*(step_del) &= (0x00003F00);
	//	kprintf("3");
	//	kprintf("cntAdd - 0x%8x", *cntrl_addr);
		uint32 creg=*adc_evnt_addr;
		creg=creg>>4;
		creg=creg<<4;
		creg=creg | 1;
		*adc_evnt_addr=creg;
	//	kprintf("ea - 0x%8x", *adc_evnt_addr);
		uint32 creg1=*tmr_addr;
		creg1=creg1>>7;
		creg1=creg1<<7;
		creg1=creg1 | 18;
		*tmr_addr=creg1;
		//kprintf("tm4 - 0x%8x", *tmr_addr);
		//uint32 creg = *(ADC_BASE_ADDR + FIFO0_ADDR_OFFSET);
		
	//	*(cntrl_addr) |= 1;
		//*(adc_addr + STEP_DEL_1 ) 
		*/
		//printf("SE - 0x%8x",*(adc_addr + STEP_EN_REG));
		//printf("SC - 0x%8x",*(adc_addr + STEP_CON_1 ));
		//kprintf("fi - 0x%8x", *fifo_addr);
	}
		else if (strncmp(args[1], "user2", 5) == 0)
	{
		uint32 fc=0;
		uint32 fcount= *fifo_count & 127;
		uint32 creg=0;
		if(fcount >= 1)
		{
			kprintf("u2 - %d \n", fcount);
			//sleep(1);
			while(*adc_stat_addr & 0x00000020);
			creg=*fifo_addr & 0x00000fff;
			kprintf("fifo - %d", creg);
			fc++;
		}
		fc=0;
		//uint32 creg = (gpio_addr + GPIO_OE);
		//fprintf(stderr, "OE - 0x%8x",gpio_addr + GPIO_OE);
		//fprintf(stderr, "DIN - 0x%8x",gpio_addr + GPIO_IN);
		//led = 2;
		//lsensor_write(gpio_addr,2,"off");
	}
	/*--	else if (strncmp(args[1], "user3", 5) == 0)
	{
		//uint32 creg = *(adc_addr + FIFO0_ADDR_OFFSET);
		//uint32 creg1 = *(adc_addr + ADC_CNTRL_REG_ADDR);
		//printf("FA - 0x%8x",fifo_addr);
		//printf("F - 0x%8x",*(fifo_addr));
		//printf("C - 0x%8x",*(cntrl_addr));
		//led = 3;
	}
		else if (strncmp(args[1], "user4", 5) == 0)
	{
		//uint32 creg = *(ADC_BASE_ADDR + FIFO0_ADDR_OFFSET);
		//*(adc_addr + STEP_EN_REG) |= STEP_EN_1;
		//*(adc_addr + STEP_CON_1 ) &= ~(CON_FIFO0);
		//*(adc_addr + STEP_DEL_1 ) 
		//fprintf(stderr, "FIFO1 - 0x%8x",ADC_BASE_ADDR + FIFO0_ADDR_OFFSET);
	//	printf("SE - 0x%8x",*(adc_addr + STEP_EN_REG));
	//	printf("SC - 0x%8x",*(adc_addr + STEP_CON_1 ));
		//led = 3;
	}
	else
	{
		fprintf(stderr, "%s: invalid DESCRIPTOR\n", args[0]);
		fprintf(stderr, "Try '%s --help' for more information\n",
		args[0]);
	} 
	uint32 xx; --*/
	//#ifdef GPIO_BASE
	/* change led state */
/* --	if (strncmp(args[2], "on", 2) == 0)
	{
		switch(led){
		case 0:*(gpio_addr + GPIO_OUT) = *(gpio_addr + GPIO_OUT) | USR0_LED;
			break;
		case 1:*(gpio_addr + GPIO_OUT) = *(gpio_addr + GPIO_OUT) | USR1_LED;
			break;
		case 2:*(gpio_addr + GPIO_OUT) = *(gpio_addr + GPIO_OUT) | USR2_LED;
			break;
		case 3:*(gpio_addr + GPIO_OUT) = *(gpio_addr + GPIO_OUT) | USR3_LED;
			break;
		}
	}
	else if (strncmp(args[2], "off", 3) == 0)
	{
		switch(led){
		case 0:*(gpio_addr + GPIO_OUT) = *(gpio_addr + GPIO_OUT) & (~USR0_LED);
			break;
		case 1:*(gpio_addr + GPIO_OUT) = *(gpio_addr + GPIO_OUT) & (~USR1_LED);
			break;
		case 2:*(gpio_addr + GPIO_OUT) = *(gpio_addr + GPIO_OUT) & (~USR2_LED);
			break;
		case 3:*(gpio_addr + GPIO_OUT) = *(gpio_addr + GPIO_OUT) & (~USR3_LED);
			break;
	}
	}
	else
	{
		fprintf(stderr, "%s: invalid STATE\n", args[0]);
		fprintf(stderr, "Try '%s --help' for more information\n",
		args[0]);
	}--*/
	//#endif                          /* GPIO_BASE */

	return 0;
}
