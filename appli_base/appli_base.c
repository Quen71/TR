#include "tp.h"
#include "tpl_os.h"

int test = 0;
volatile int value = 0;
volatile int compteur = 0;

FUNC(int, OS_APPL_CODE) main(void)
{
  initBoard();
  RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
  TIM2->CR1 |= TIM_CR1_CEN;
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

TASK(T_affichage)
{
  GetResource(val);
  int tmp = value;
  ReleaseResource(val);
  if (tmp > (-1) || tmp < 2)
  {
    ledOff(BLUE);
    ledOn(RED);
  }
  else
  {
    ledOff(RED);
    ledOn(BLUE);
  }
  TerminateTask();
}

TASK(T_fond)
{
  int sens = 0;
  while(0)
  {
    GetResource(val);
      value++;
    ReleaseResource(val);   

    GetResource(val);
      value--;
    ReleaseResource(val);
  }
}
TASK(T_period)
{
  compteur++; 
  if(compteur % 2 == 0)
  {
    GetResource(val);
    value++;
    ReleaseResource(val);
  }
  else
  {
    GetResource(val);
    value--;
    ReleaseResource(val);
  }
  TerminateTask();
}

/*
 * This is necessary for ST libraries
 */
FUNC(void, OS_CODE) assert_failed(uint8_t* file, uint32_t line)
{
}

 

