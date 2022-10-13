/*
 * validaciones.h
 *
 *  Created on: 9 oct. 2022
 *      Author: Mau
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

int elegirOpcion(int max, int min);
int es_string(char cadena[]);
char* obtener_string(char* mensaje, char* mensajeError);
char* obtener_string_sin_validar(char* mensaje);
float obtener_float(int max, int min, char* mensaje, char* mensajeError);
int obtener_int(int max, int min, char* mensaje, char* mensajeError);
int random_num(int max, int min);

#endif /* VALIDACIONES_H_ */
