#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN PB5  // вбудований в Arduino nano світлодіод
#define LETTER_DELAY 300

void blink_led_dot(uint8_t times) {
    for (uint8_t i = 0; i < times; i++) {
        PORTB |= (1 << LED_PIN);   // включити світлодіод
        _delay_ms(100);    // затримка
        PORTB &= ~(1 << LED_PIN); // виключити світлодіод
        _delay_ms(100); 
    }
}

void blink_led_dash(uint8_t times) {
    for (uint8_t i = 0; i < times; i++) {
        PORTB |= (1 << LED_PIN); // включити світлодіод
        _delay_ms(300);   // затримка
        PORTB &= ~(1 << LED_PIN); // виключити світлодіод
        _delay_ms(100); 
    }
}
int main(void)
{
    DDRB |= (1 << LED_PIN);
    while (1) {
        // S: ...
        blink_led_dot(3);
        _delay_ms(LETTER_DELAY);

        // O: ---
        blink_led_dash(3);
        _delay_ms(LETTER_DELAY);
        
        // S: ...
        blink_led_dot(3);
        _delay_ms(LETTER_DELAY);
    }
    return 0;
}
