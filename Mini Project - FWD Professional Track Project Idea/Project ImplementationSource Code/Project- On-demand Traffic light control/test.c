/********************************LIB*********************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**********************************MCAL******************************/
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "NVIC_Interface.h"
#include "EXTI_interface.h"
#include "AFIO_interface.h"


int main(void)
{
/******************************void setup****************************/
MCAL_RCC_InitSysClock();
MCAL_RCC_EnablePeripheral(RCC_APB2,RCC_APB2ENR_IOPAEN);
MCAL_RCC_EnablePeripheral(RCC_APB2,RCC_APB2ENR_IOPBEN);
MCAL_NVIC_EnableIRQ(NVIC_EXTI0_IRQn);
void EXTI_vInit(void);
EXTI_EnableLine(EXTI_LINE0);
MCAL_NVIC_EnableIRQ(NVIC_EXTI0_IRQn);
MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN1,GPIO_OUTPUT_PUSH_PULL_2MHZ);
MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN2,GPIO_OUTPUT_PUSH_PULL_2MHZ);
MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN3,GPIO_OUTPUT_PUSH_PULL_2MHZ);
MCAL_GPIO_SetPinMode(GPIO_PORTB,GPIO_PIN0,GPIO_INPUT_PULL_UP);
MCAL_GPIO_SetPinMode(GPIO_PORTB,GPIO_PIN1,GPIO_OUTPUT_PUSH_PULL_2MHZ);
MCAL_GPIO_SetPinMode(GPIO_PORTB,GPIO_PIN2,GPIO_OUTPUT_PUSH_PULL_2MHZ);
MCAL_GPIO_SetPinMode(GPIO_PORTB,GPIO_PIN3,GPIO_OUTPUT_PUSH_PULL_2MHZ);

	
/******************************void loop****************************/
	

while(1)
{	
	MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_HIGH);
	MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_HIGH);
	MCAL_STK_SetDelay_ms(10000);
	MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_LOW);
	MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_LOW);
	MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_HIGH);
	MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_HIGH);
	MCAL_STK_SetDelay_ms(5000);
	MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_LOW);
	MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_LOW);
	MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_HIGH);
	MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_HIGH);
	MCAL_STK_SetDelay_ms(10000);
	MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_LOW);
	MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_LOW);
		
	


}



}

void EXTI0_IRQHandler(void)
{ 

u8 PIN_CAR_STATUS;
u8 PIN_PEDESTRIAN_STATUS;
MCAL_GPIO_GetPinValue(GPIO_PORTA,GPIO_PIN3,&PIN_CAR_STATUS);
MCAL_GPIO_GetPinValue(GPIO_PORTB,GPIO_PIN1,&PIN_PEDESTRIAN_STATUS);

if(PIN_CAR_STATUS == GPIO_HIGH && PIN_PEDESTRIAN_STATUS == GPIO_HIGH)
{
MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_LOW);
MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_LOW);
MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_HIGH);
MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_HIGH);
MCAL_STK_SetDelay_ms(5000);
MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_LOW);
MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_LOW);
MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_HIGH);
MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_HIGH);
MCAL_STK_SetDelay_ms(5000);
MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_LOW);
MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_LOW);
EXTI_Exit_IRQHandler(EXTI_LINE0);
MCAL_NVIC_ClearPendingIRQ(NVIC_EXTI0_IRQn);

	
}
else
	return;

}
