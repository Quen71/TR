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
  ActivateTask(task_1);
  ActivateTask(task_2);
  delay(3000);
  ledOn(BLUE);
  TIM2->CNT = 0;
  TerminateTask();
}

TASK(task_1)
{
  delay(3000);
  ledOn(GREEN);
  TIM2->CNT = 0;
  TerminateTask();
}

TASK(task_2)
{
  delay(3000);
  ledOn(RED);
  TIM2->CNT = 0;
  TerminateTask();
}


/*
 * This is necessary for ST libraries
 */
FUNC(void, OS_CODE) assert_failed(uint8_t* file, uint32_t line)
{
}

 

