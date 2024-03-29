/*
 * utils.h
 *
 *  Created on: Jun 5, 2014
 *      Author: chuzz
 */

#ifndef UTILHS_H_
#define UTILHS_H_

// bytes necessari per contenere x bits (anche non multipli di 8!)
#define BYTES_FOR(x) (x/8 + (x%8? 1:0))

// li ho messi fissi anche se all'inizio li passavo in giro come parametri
#define WIDTH 320
#define HEIGHT 240


// immagine etichettata, 255 etichette possibili, 1 byte per pixel
typedef unsigned char label_t;

// immagine B/N, 1 bit per pixel
typedef unsigned char bitimg_t;

// estrai bit in posizione (x,y) da bitimg
inline static unsigned char at(bitimg_t buff[], unsigned int x, unsigned int y){
	return (buff[y * BYTES_FOR(WIDTH) + (x / 8)] & (0x80 >> (x % 8)));
}

// setta a 0 bit in posizione (x,y) da bitimg
inline static void clear_at(bitimg_t buff[], unsigned int x, unsigned int y){
	buff[y * BYTES_FOR(WIDTH) + (x / 8)] &= ~(0x80 >> (x % 8));
}

// setta a 1 bit in posizione (x,y) da bitimg
inline static void set_at(bitimg_t buff[], unsigned int x, unsigned int y){
	buff[y * BYTES_FOR(WIDTH) + (x / 8)] |= (0x80 >> (x % 8));
}


// scrivi bitimg su file
void dump_bitimg(char filename[], bitimg_t buff[]);

#endif /* UTILS_H_ */
