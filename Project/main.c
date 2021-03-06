#include "adc.h"
#include "exti.h"
#include "qi.h"
#include "pid.h"
#include "tim2.h"
#include "pwm.h"
#include "stm8s.h"


/*
    延时函数
*/
void delay(void)
{
    long i,j;
    for(i=0;i<3000;i++)
    { 
      for(j=0;j<100;j++){
        
      }
    }
}

void GPIO_Config(void)
{
  GPIOB->CR1|=1<<5;
  GPIOB->DDR|=1<<5;
  GPIOB->ODR|=1<<5;
  
  GPIOA->CR1|=1<<2;
  GPIOA->DDR|=1<<2;  

  GPIOB->CR1|=1<<4;
  GPIOB->DDR|=1<<4;
  delay();
  GPIOB->DDR &=~(1<<4);
  delay();
  GPIOA->ODR|=1<<2;
  delay();
}


void main(void)
{

  WPCQi_Phase = Ping_Phase;
  Voltage_State =2;
  CLK_Configuration();
  TIM2_Init();
  ADC_Config();
  pwm_init();
  GPIO_Config();
  exti_init();                //外部中断实验，使用的引脚与PWM冲突
  TIM4_Init();
  enableInterrupts(); 
  while(1)
  {
       WPC_QI();
  }
}


#ifdef USE_FULL_ASSERT                           //断言(参考官方)

void assert_failed(u8* file, u32 line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

