#include <avr/io.h>
#include <util/delay.h>

int main()
{
    _PROTECTED_WRITE(CLKCTRL_OSCHFCTRLA, CLKCTRL_FREQSEL_24M_gc);

    PORTC.DIRCLR = PIN7_bm;
    PORTC.DIRSET = PIN6_bm;
    PORTC.PIN7CTRL |= PORT_PULLUPEN_bm; 

    while (1)
    {
        if (PORTC.IN & (PIN7_bm))
        {
            PORTC.OUTTGL = PIN6_bm;
            _delay_ms(500);
        }
    }
}