/*
 * File:   CONTEO0AF.c
 * Author: Licea
 *
 * Created on November 27, 2023, 11:38 AM
 */


#define F_CPU 1000000UL
#include <XC.h>
#include <util/delay.h>

#define PUERTO_COLUMNA PORTD
#define PUERTO_FILA PORTC
#define true 1
#define false 0

int main()
{
   uint8_t millares,centenas,decenas,unidades,repeticiones,salida,dato[11];

   dato[1] = ~63; // Invertido para ánodo común
   dato[2] = ~6;
   dato[3] = ~91;
   dato[4] = ~79;
   dato[5] = ~102;
   dato[6] = ~109;
   dato[7] = ~120;
   dato[8] = ~7;
   dato[9] = ~127;
   dato[10] = ~103;
   
   DDRD = 0xFF;
   DDRC = 0xFF;
   while (1)
   {
      for(millares = 0; millares <= 9; millares++)
      {
         for(centenas = 0; centenas <= 9; centenas++)
         {
            for(decenas = 0; decenas <= 9; decenas++)
            {
               for(unidades = 0; unidades <= 9; unidades++)
               {
                      for(repeticiones = 0; repeticiones <= 9; repeticiones++)
                  {
                     PORTD = dato[unidades+1];
                     PORTC = 8;
                     _delay_ms(7); // Aumentado a 5ms
                     PORTD = dato[decenas+1];
                     PORTC = 4;
                     _delay_ms(7); // Aumentado a 5ms
                     PORTD = dato[centenas+1];
                     PORTC = 2;
                     _delay_ms(0.5);
                     PORTD = dato[millares+1];
                     PORTC = 1;
                     _delay_ms(0.5);
                  }
               }
            }
         }
      }
      salida = false;
      if (salida == true) break;
   }

   return 0;
}