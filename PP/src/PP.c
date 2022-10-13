/*
 ============================================================================
 Name        : PP.c
 Author      : Mauro Panzini
 Version     :
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "actor.h"
#include "fecha.h"
#include "pelicula.h"
#include "menu.h"

#define TAM 5
#define ROJO_F     "\x1b[41m"



int main(void) {
	setbuf(stdout, NULL);
	int opcion = 0;
	int banderaIngresoPelicula = 0;
	int ingresoActor;
	int ingresoPelicula;
	int cantPelis;
	int z;
	eActor listaActores[TAM];
	ePelicula listaPeliculas[TAM];
	inicializar_lista_actores(listaActores, TAM);
	inicializar_lista_peliculas(listaPeliculas, TAM);
	do {
		printf("***BIENVENIDO A " ROJO_F "MARIANVEL STUDIOS\x1b[0m***\n");
		menu_cuatroOpciones("1)Gestionar Actores\n", "2)Gestionar Peliculas\n", "3)Generar Informes\n", "4)Salir\n");
		opcion = elegirOpcion(4,1);
		switch(opcion){
		case 1:
			z = 0;
			if (banderaIngresoPelicula == 1) {
				do {
					menu_cincoOpciones("1)Alta actor\n", "2)Modificar actor\n", "3)Baja actor\n","4)Ver listado\n" ,"5)Volver\n");
					z = elegirOpcion(5,1);
					switch(z){
					case 1:
						ingresoActor = alta_actor(listaActores, TAM, listaPeliculas, cantPelis);
						printf("%d", ingresoActor);
						break;
					case 2:
						modificar_actor(listaActores, TAM, listaPeliculas, cantPelis);
						break;
					case 3:
						baja_actor(listaActores, TAM);
						break;
					case 4:
						mostrar_actores(listaActores, TAM);
						break;
					default:
						break;
						}
				}while (z != 5);

			}else{
				printf("\nPor favor, ingrese las películas antes de cargar actores\n");
			}
			break;
		case 2:
			z = 0;
			do {
				menu_cuatroOpciones("1)Hardcodeo peliculas\n", "2)Baja peliculas\n", "3)Calcular recaudacion\n", "4)Volver\n");
				z = elegirOpcion(4,1);
				switch(z){
				case 1:
					ingresoPelicula = hardcodeo_peliculas(listaPeliculas, TAM);
					banderaIngresoPelicula = 1;
					cantPelis = 5;
					break;
				case 2:
					baja_pelicula(listaPeliculas, TAM);
					cantPelis--;
					break;
				case 3:
					recaudacion_peliculas(listaPeliculas, TAM);
					break;
				default:
					break;
				}

			} while (z != 4);
			break;
		case 3:
			do{
				menu_nueveOpciones("\n1)Ordenar actores alfabéticamente por título de pelicula y mostrar\n","2)Ordenar actores por valor mensual de contrato y mostrar\n","3)Premiar actores\n","4)Listar actores ganadores de Oscar en pelicula ganadora de Oscar\n","5)Listar Películas ordenadas por fecha de estreno.\n","6)Listar las películas con todos sus personajes ordenados por rol.\n","7)Listar las películas estrenadas por recaudación y como segundo criterio duración.\n","8)Ganancias o perdidas.\n","9)Volver");
				z = elegirOpcion(9,1);
				switch(z){
				case 1:
					if(ordenar_actores_pelicula(listaActores, TAM) == 1){
						printf("Se ordenó satisfactoriamente");
					}
					break;
				case 2:
					if(ordenar_actores_contrato(listaActores, TAM) == 1){
						printf("Se ordenó satisfactoriamente");
					}
					break;
				case 3:
					break;
				case 4:
					break;
				case 5:
				break;
				case 6:
					break;
				case 7:
					break;
				case 8:
					break;
				default:
					break;
				}
			}while (z != 9);
		}
	} while(opcion != 4);

}
