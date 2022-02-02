#include "tp.h"
#include "tpl_os.h"

int test = 0;

FUNC(int, OS_APPL_CODE) main(void)
{
  initBoard();
  RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
  TIM2->CR1 |= TIM_CR1_CEN;
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

TASK(a_task)
{
  ActivateTask(task_blink);
  ChainTask(task_blink);
  TerminateTask();
}

TASK(blink_task)
{
  ledOn(BLUE);
  delay(500);
  ledOff(BLUE);
  delay(500);
  TIM2->CNT = 0;
  TerminateTask();
}


/*
 * This is necessary for ST libraries
 */
FUNC(void, OS_CODE) assert_failed(uint8_t* file, uint32_t line)
{
}

 

