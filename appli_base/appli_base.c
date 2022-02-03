#include "tp.h"
#include "tpl_os.h"

int test = 0;
volatile int led = 0;

FUNC(int, OS_APPL_CODE) main(void)
{
  initBoard();
  RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
  TIM2->CR1 |= TIM_CR1_CEN;
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

ISR (button)
{
  ActivateTask(T_blink);
  led++;
  if (led == 4)
  {
    led = 0;
  }
}

TASK(T_blink)
{
  if (led == 0)
  {
    ledOn(GREEN);
    delay(500);
    ledOff(GREEN);
  }
  if (led == 1)
  {
    ledOn(BLUE);
    delay(500);
    ledOff(BLUE);
  } 
  if (led == 2)
  {
    ledOn(RED);
    delay(500);
    ledOff(RED);
  }
  if (led == 3)
  {
    ledOn(ORANGE);
    delay(500);
    ledOff(ORANGE);
  }

  TerminateTask();
}


/*
 * This is necessary for ST libraries
 */
FUNC(void, OS_CODE) assert_failed(uint8_t* file, uint32_t line)
{
}

 

