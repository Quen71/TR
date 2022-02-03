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
  if (led == 0)
    led = 1;
  else
    led = 0;
}

TASK(T_blink)
{
  while (1)
  {
    if (led == 0)
    {
      WaitEvent(ev1);
      ClearEvent(ev1);
      ledToggle(BLUE);
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

 

