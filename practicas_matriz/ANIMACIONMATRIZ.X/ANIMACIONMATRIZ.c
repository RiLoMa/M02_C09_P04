/*
 * File:   ANIMACIONMATRIZ.c
 * Author: Licea
 *
 * Created on November 27, 2023, 11:20 AM
 */


#include <avr/io.h>
#include <util/delay.h>

// Definiciones de pines para filas y columnas de la matriz de LED
#define PORT_Fila PORTA
#define DDR_Fila DDRA

#define PORT_Columna PORTB
#define DDR_Columna DDRB

// Matriz que representa una cara feliz en una matriz de 8x8 LED
const uint8_t cara_feliz[8] = {
    0x3C, // 00111100
    0x42, // 01000010
    0xA5, // 10100101
    0x81, // 10000001
    0xA5, // 10100101
    0x99, // 10011001
    0x42, // 01000010
    0x3C  // 00111100
};

// Matriz que representa una cara feliz que guiñe el ojo en una matriz de 8x8 LED
const uint8_t cara_guino[8] = {
    0x3C, // 00111100
    0x42, // 01000010
    0xA5, // 10100101 // Cambiar este valor de 0x25 a 0xA5
    0x81, // 10000001
    0xA5, // 10100101
    0x99, // 10011001
    0x42, // 01000010
    0x3C  // 00111100
};

void encenderLetra(const uint8_t letra[8], int tiempo) {
    for (int i = 0; i < 8; i++) {
        PORT_Fila = letra[i]; // Activar las filas según la letra
        
        // Configurar las columnas para encender el LED correspondiente
        PORT_Columna = ~(1 << i);
        
        _delay_ms(tiempo); // Retardo según el tiempo indicado
    }
}

int main() {
    DDR_Fila = 0xFF; // Configurar filas como salidas
    DDR_Columna = 0xFF; // Configurar columnas como salidas

    while (1) {
        encenderLetra(cara_feliz); // Mostrar la cara feliz por 50 milisegundos
        encenderLetra(cara_guino); // Mostrar la cara que guiñe el ojo por 50 milisegundos
    }

    return 0;
}