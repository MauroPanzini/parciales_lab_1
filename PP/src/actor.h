/*
 * actor.h
 *
 *  Created on: 9 oct. 2022
 *      Author: Mau
 */

#ifndef ACTOR_H_
#define ACTOR_H_
#include "fecha.h"
#include "pelicula.h"



typedef struct{
	int vacio;
	int codigo;
	char nombre[20];
	char apellido[20];
	char personaje[20];
	char rol[20];
	float contratoMensual;
	eFecha inicioContrato;
	eFecha finalContrato;
	int ganoOscar;
	ePelicula pelicula;

} eActor;

eActor pedir_datos_actor(ePelicula listaPeliculas[], int cantPelis);
int alta_actor(eActor listaActores[], int tam, ePelicula listaPeliculas[], int cantPelis);
int baja_actor(eActor listaActores[], int tam);
int modificar_actor(eActor listaActores[], int tam, ePelicula listaPeliculas[], int cantPelis);
void inicializar_lista_actores(eActor listaActores[], int tam);
int a_b_m(eActor listaActores[], int tam, int opcion);
void mostrar_actor(eActor actor);
void mostrar_actores(eActor listaActores[], int tam);
int ordenar_actores_contrato(eActor listaActores[], int tam);
int ordenar_actores_pelicula(eActor listaActores[], int tam);
#endif /* ACTOR_H_ */
