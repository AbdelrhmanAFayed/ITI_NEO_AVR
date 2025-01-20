#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_INTERFACE.h"



void main (void)
{


    while(1)
    {
        DIO_voidSetPinDirection(PORTA, PIN_0, PIN_OUTPUT);
        
        DIO_voidSetPinValue(PORTA, PIN_0, PIN_HIGH);
    }


}