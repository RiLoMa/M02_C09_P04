/*
 * File:   CONTEO0A9.c
 * Author: Licea
 *
 * Created on November 27, 2023, 11:33 AM
 */


#define F_CPU 1000000UL
#include <XC.h>
#include <util/delay.h>
#include <avr/io.h>

#define PUERTO_COLUMNA PORTD //haciendo un comentario 
#define PUERTO_FILA PORTC
#define true 1
#define false 0

int main()
{
   uint8_t millares,centenas,decenas,unidades,repeticiones,salida,dato[16];

   dato[0] = ~63;  // N�mero 0
   dato[1] = ~6;   // N�mero 1
   dato[2] = ~91;  // N�mero 2
   dato[3] = ~79;  // N�mero 3
   dato[4] = ~102; // N�mero 4
   dato[5] = ~109; // N�mero 5
   dato[6] = ~125; // N�mero 6
   dato[7] = ~7;   // N�mero 7
   dato[8] = ~127; // N�mero 8
   dato[9] = ~111; // N�mero 9
   dato[10] = ~97; // N�mero A
   dato[11] = ~119; // N�mero B
   dato[12] = ~31; // N�mero C
   dato[13] = ~75; // N�mero D
   dato[14] = ~113; // N�mero E
   dato[15] = ~112; // N�mero F

   DDRD = 0xFF;
   DDRC = 0xFF;
   while (1)
   {
      millares =0;
      while (millares <= 15)
      {
         centenas =0;
         while (centenas <= 15)
         {
            decenas =0;
            while (decenas <= 15)
            {
               unidades =0;
               while (unidades <= 15)
               {
                  repeticiones =0;
                  while (repeticiones <= 15)
                  {
                     PORTD =dato[unidades];
                     PORTC =8;
                     _delay_ms(5); // corregido de 0.5 a 5
                     PORTC =0;
                     PORTD =dato[decenas];
                     PORTC =4;
                     _delay_ms(5); // corregido de 0.5 a 5
                     PORTC =0;
                     PORTD =dato[centenas];
                     PORTC =2;
                     _delay_ms(5); // corregido de 0.5 a 5
                     PORTC =0;
                     PORTD =dato[millares];
                     PORTC =1;
                     _delay_ms(5); // corregido de 0.5 a 5
                     PORTC =0;
                     repeticiones++;
                  }
                  unidades++;
               }
               decenas++;
            }
            centenas++;
         }
         millares++;
      }
      salida =false;
      if (salida==true) break;
   }

   return 0;
}
