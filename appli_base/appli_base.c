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
  if (led == 0)
  {
    led = 1;
  }
  else 
  {
    led = 0;
  }
}

TASK(T_chase)
{
  EventMaskType event_got;
  
  while (1)
  {
    WaitEvent(ev1 | ev2 | ev3 | ev4);
    GetEvent(T_chase, &event_got);

    if (event_got & ev1)
    {
      ClearEvent(ev1);
      ledOn(BLUE);
      delay(250);
      ledOff(BLUE);
    }
    if (event_got & ev2)
    {
      ClearEvent(ev2);
      ledOn(GREEN);
      delay(250);
      ledOff(GREEN);
    }
    if (event_got & ev3)
    {
      ClearEvent(ev3);
      ledOn(ORANGE);
      delay(250);
      ledOff(ORANGE);
    }
    if (event_got & ev4)
    {
      ClearEvent(ev4);
      ledOn(RED);
      delay(250);
      ledOff(RED);
    }
  }
  TerminateTask();
}


/*
 * This is necessary for ST libraries
 */
FUNC(void, OS_CODE) assert_failed(uint8_t* file, uint32_t line)
{
}

 

