#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
int ana_sayi=0; //saymaya başla
int tekrar_sayisi=0;
int i=0;
int main(void)
{
  DDRD &= 0xF0;  //d4-d7 arası giriş
  DDRB &= 0x3C;  //b2-b5 arası giriş
  DDRC = 0x0F; //c0-c3 çıkış
  DDRC &= 0x10; //c4 giris
  while(1)
  { 
    ana_sayi=(PIND & 0xF0)>>4;//bit 4 saga kaydır
    tekrar_sayisi=(PINB & 0x3C)>>2;// bit  2 saga kaydır
    if(PINC & 0x10)
    {
      for(int j=0;i<=tekrar_sayisi;i++){
       for(int i=0;i<=ana_sayi;i++){
         PORTC=i;
         _delay_ms(500); 
        }
      }
      PORTC &= 0b11110000; //ledleri kapat
    }
    else{
      PORTC &= 0b11110000; //ledleri kapat
    }
  }
}
