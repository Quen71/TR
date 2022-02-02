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

TASK(T_master)
{
  ActivateTask(T_1);
  ActivateTask(T_2);
  ActivateTask(T_3);

  EventMaskType event_got;
  
  while (1)
  {
    WaitEvent(ev1 | ev2 | ev3);
    GetEvent(T_master, &event_got);

    if (event_got & ev1)
    {
      ClearEvent(ev1);
      ActivateTask(T_1);
    }
    if (event_got & ev2)
    {
      ClearEvent(ev2);
      ActivateTask(T_2);
    }
    if (event_got & ev3)
    {
      ClearEvent(ev3);
      ActivateTask(T_3);
    }
  }
  

  TerminateTask();
}

TASK(T_1)
{
  ledOn(BLUE);
  delay(500);
  ledOff(BLUE);
  delay(500);
  SetEvent(T_master, ev1);
  TerminateTask();
}

TASK(T_2)
{
  ledOn(RED);
  delay(500);
  ledOff(RED);
  delay(500);
  SetEvent(T_master, ev2);
  TerminateTask();
}

TASK(T_3)
{
  ledOn(GREEN);
  delay(500);
  ledOff(GREEN);
  delay(500);
  SetEvent(T_master, ev3);
  TerminateTask();
}


/*
 * This is necessary for ST libraries
 */
FUNC(void, OS_CODE) assert_failed(uint8_t* file, uint32_t line)
{
}

 

