/*
 * pelicula.h
 *
 *  Created on: 11 oct. 2022
 *      Author: mauropanzini
 */

#ifndef PELICULA_H_
#define PELICULA_H_
#include "fecha.h"

typedef struct{
	int vacio;
	int codigo;
	char titulo[30];
	int duracion;
	char director[30];
	eFecha fechaEstreno;
	int recaudacion;
	int ganoOscar;

} ePelicula;

void inicializar_lista_peliculas(ePelicula listaPeliculas[], int tam);
int hardcodeo_peliculas(ePelicula listaPeliculas[], int tam);
int alta_pelicula(ePelicula listaPeliculas[], int tam);
int baja_pelicula(ePelicula listaPeliculas[], int tam);
void recaudacion_peliculas(ePelicula listaPeliculas[], int tam);

#endif /* PELICULA_H_ */
