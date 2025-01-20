#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_INTERFACE.h"
#include "DIO_Private.h"




void DIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction)
{

    switch (Copy_u8Port)
    {
    
    case PORTA:

        if(Copy_u8Direction == PIN_OUTPUT)
        {
            SET_BIT(DDRA_Register, Copy_u8Pin);
        }
        else if(Copy_u8Direction == PIN_INPUT)
        {
            CLR_BIT(DDRA_Register, Copy_u8Pin);
        }
        else
        {
        }

        break;

    case PORTB:

        if(Copy_u8Direction == PIN_OUTPUT)
        {
            SET_BIT(DDRB_Register, Copy_u8Pin);
        }
        else if(Copy_u8Direction == PIN_INPUT)
        {
            CLR_BIT(DDRB_Register, Copy_u8Pin);
        }
        else
        {
        }
    
        break;

    case PORTC:

        if(Copy_u8Direction == PIN_OUTPUT)
        {
            SET_BIT(DDRC_Register, Copy_u8Pin);
        }
        else if(Copy_u8Direction == PIN_INPUT)
        {
            CLR_BIT(DDRC_Register, Copy_u8Pin);
        }
        else
        {
        }
    
        break;

    case PORTD:

        if(Copy_u8Direction == PIN_OUTPUT)
        {
            SET_BIT(DDRD_Register, Copy_u8Pin);
        }
        else if(Copy_u8Direction == PIN_INPUT)
        {
            CLR_BIT(DDRD_Register, Copy_u8Pin);
        }
        else
        {
        }
    
        break;
    
    default:
        break;
    }

}
void DIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
        switch (Copy_u8Port)
    {
    
    case PORTA:

        if(Copy_u8Value == PIN_HIGH)
        {
            SET_BIT(PORTA_Register, Copy_u8Pin);
        }
        else if(Copy_u8Value == PIN_LOW)
        {
            CLR_BIT(PORTA_Register, Copy_u8Pin);
        }
        else
        {
        }

        break;

    case PORTB:

        if(Copy_u8Value == PIN_HIGH)
        {
            SET_BIT(PORTB_Register, Copy_u8Pin);
        }
        else if(Copy_u8Value == PIN_LOW)
        {
            CLR_BIT(PORTB_Register, Copy_u8Pin);
        }
        else
        {
        }
         
        break;

    case PORTC:

        if(Copy_u8Value == PIN_HIGH)
        {
            SET_BIT(PORTC_Register, Copy_u8Pin);
        }
        else if(Copy_u8Value == PIN_LOW)
        {
            CLR_BIT(PORTC_Register, Copy_u8Pin);
        }
        else
        {
        }
        
    
        break;

    case PORTD:

        if(Copy_u8Value == PIN_HIGH)
        {
            SET_BIT(PORTD_Register, Copy_u8Pin);
        }
        else if(Copy_u8Value == PIN_LOW)
        {
            CLR_BIT(PORTD_Register, Copy_u8Pin);
        }
        else
        {
        }
        
    
        break;
    
    default:
        break;
    }

}



