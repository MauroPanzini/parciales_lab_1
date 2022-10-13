/*
 * actor.c
 *
 *  Created on: 9 oct. 2022
 *      Author: Mau
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "actor.h"
#include "menu.h"
#include "validaciones.h"
#include "fecha.h"
#include "pelicula.h"



eActor pedir_datos_actor(ePelicula listaPeliculas[], int cantPelis){
	eActor actor;
	actor.codigo = obtener_int(100, 1, "\nIngrese el código del actor: \n", "Error, ingrese un código válido (debe estar entre 1 y 100): \n");
	strcpy(actor.nombre, obtener_string("Ingrese el nombre del actor: \n", "Error, ingrese nuevamente: \n"));
	strcpy(actor.apellido, obtener_string("Ingrese el apellido del actor: \n", "Error, ingrese nuevamente: \n"));
	strcpy(actor.personaje, obtener_string("Ingrese el nombre del personaje del actor: \n", "Error, ingrese nuevamente: \n"));
	menu_tresOpciones("Rol del actor:\n1)Heroe\n", "2)Villano\n", "3)Secundario\n");
	int aux = elegirOpcion(3, 1);
	switch(aux){
	case 1:
		strcpy(actor.rol, "HEROE");
		break;
	case 2:
		strcpy(actor.rol,"VILLANO");
		break;
	case 3:
		strcpy(actor.rol, "SECUNDARIO");
		break;
	}
	printf("Elija la pelicula en la que trabaja:\n");
	for(int i = 0; i< cantPelis; i++){
		printf("%d", i+1);
		printf(")%s\n",listaPeliculas[i].titulo);
	}
	int auxDos = elegirOpcion(cantPelis, 1);
	strcpy(actor.pelicula.titulo, listaPeliculas[auxDos-1].titulo);

	actor.contratoMensual = obtener_float(3000000, 0, "Introduzca el salario mensual: \n", "Error, ingrese un valor válido: \n");

	actor.inicioContrato.dia = obtener_int(31, 1, "Introduzca el día de inicio del contrato: \n", "Error, ingrese un valor válido: \n");
	actor.inicioContrato.mes = obtener_int(12, 1, "Introduzca el mes de inicio del contrato: \n", "Error, ingrese un valor válido: \n");
	actor.inicioContrato.anio = obtener_int(2080, 2022, "Introduzca el año de inicio del contrato: \n", "Error, ingrese un valor válido: \n");

	actor.finalContrato.dia = obtener_int(31, 1, "Introduzca el día del fin del contrato: \n", "Error, ingrese un valor válido: \n");
	actor.finalContrato.mes = obtener_int(12, 1, "Introduzca el mes del fin del contrato: \n", "Error, ingrese un valor válido: \n");
	actor.finalContrato.anio = obtener_int(2100, 2022, "Introduzca el año del fin del contrato: \n", "Error, ingrese un valor válido: \n");

	actor.ganoOscar = obtener_int(5, 0, "¿Ganó un premio Oscar?\n", "Error, ingrese un valor válido\n");

	actor.vacio = 1;
	return actor;
}


int alta_actor(eActor listaActores[], int tam, ePelicula listaPeliculas[], int cantPelis){
	int retorno = 0;
	for(int i = 0 ; i < tam ; i++){
		if(listaActores[i].vacio == 0){
			listaActores[i] = pedir_datos_actor(listaPeliculas, cantPelis);
			retorno = 1;
		    break;
		  }
    }
	return retorno;
}


int baja_actor(eActor listaActores[], int tam){
	int codigoActor;
	int retorno = 0;

	codigoActor = obtener_int(100, 1, "\nIngrese el codigo del actor a borrar: \n", "\nError, codigo inválido, ingrese nuevamente: \n");
	for(int i=0; i < tam; i++){
		if(listaActores[i].vacio == 1){
			if(listaActores[i].codigo == codigoActor){
				listaActores[i].vacio = 0;
	             retorno = 1;
	             break;
	            }
	        }
	    }
	return retorno;
}

int modificar_actor(eActor listaActores[], int tam, ePelicula listaPeliculas[], int cantPelis){
	int codigoActor;
	int opcion;
	int retorno = 0;
	codigoActor = obtener_int(100, 1, "\nIngrese el codigo del actor a modificar: \n", "\nError, codigo inválido, ingrese nuevamente: \n");

	for(int i=0; i < tam; i++){
		if(listaActores[i].vacio == 1){
			if(listaActores[i].codigo == codigoActor){
				//funcion para mostrar al actor//
				printf("\n¿Qué desea modificar?\n1)Nombre\n2)Apellido\n3)Nombre del personaje\n4)Rol\n5)Contrato mensual\n6)Inicio del contrato\n7)Fin del contrato\n8)Gano un Oscar\n9)Pelicula en la que participa\n10)Volver");
				opcion = elegirOpcion(10, 1);
				switch(opcion){
				case 1:
					strcpy(listaActores[i].nombre, obtener_string("Ingrese el nombre del actor: \n", "Error, ingrese nuevamente: \n"));
					break;
				case 2:
					strcpy(listaActores[i].apellido,obtener_string("Ingrese el apellido del actor: \n", "Error, ingrese nuevamente: \n"));
					break;
				case 3:
					strcpy(listaActores[i].personaje,obtener_string("Ingrese el personaje del actor: \n", "Error, ingrese nuevamente: \n"));
					break;
				case 4:
					menu_tresOpciones("1)Heroe\n", "2)Villano\n", "3)Secundario\n");
					int aux = elegirOpcion(3, 1);
					switch(aux){
					case 1:
						strcpy(listaActores[i].rol,"HEROE");
						break;
					case 2:
						strcpy(listaActores[i].rol,"VILLANO");
						break;
					default:
						strcpy(listaActores[i].rol,"SECUNDARIO");
						break;
						}
					break;
				case 5:
					listaActores[i].contratoMensual = obtener_float(3000000, 0, "Introduzca el salario mensual: \n", "Error, ingrese un valor válido: \n");
					break;
				case 6:
					listaActores[i].inicioContrato.dia = obtener_int(31, 1, "Introduzca el día de inicio del contrato: \n", "Error, ingrese un valor válido: \n");
					listaActores[i].inicioContrato.mes = obtener_int(12, 1, "Introduzca el mes de inicio del contrato: \n", "Error, ingrese un valor válido: \n");
					listaActores[i].inicioContrato.anio = obtener_int(2080, 2022, "Introduzca el año de inicio del contrato: \n", "Error, ingrese un valor válido: \n");
					break;
				case 7:
					listaActores[i].finalContrato.dia = obtener_int(31, 1, "Introduzca el día del fin del contrato: \n", "Error, ingrese un valor válido: \n");
					listaActores[i].finalContrato.mes = obtener_int(12, 1, "Introduzca el mes del fin del contrato: \n", "Error, ingrese un valor válido: \n");
					listaActores[i].finalContrato.anio = obtener_int(2100, 2022, "Introduzca el año del fin del contrato: \n", "Error, ingrese un valor válido: \n");
					break;
				case 8:
					listaActores[i].ganoOscar = obtener_int(5, 0, "¿Ganó un premio Oscar?\n", "Error, ingrese un valor válido\n");
					break;
				case 9:
					printf("Elija la pelicula en la que trabaja:\n");
						for(int i = 0; i < cantPelis; i++){
							printf("%d", i+1);
							printf(")%s\n",listaPeliculas[i].titulo);
						}
						int auxDos = elegirOpcion(cantPelis, 1);
						strcpy(listaActores[i].pelicula.titulo, listaPeliculas[auxDos-1].titulo);
						break;
				default:
					break;
				}
           }
        }
	}
	return retorno;
}

void inicializar_lista_actores(eActor listaActores[], int tam){
    for(int i = 0 ; i < tam ; i++)
    {
        listaActores[i].vacio = 0;
       /* strcpy(listaActores[i].nombre,"vacio");
        strcpy( listaActores[i].apellido,"vacio");
        strcpy(listaActores[i].personaje,"vacio");
        strcpy(listaActores[i].rol,"vacio");
        listaActores[i].contratoMensual = 0;
        listaActores[i].inicioContrato.dia = 0;
        listaActores[i].inicioContrato.mes = 0;
        listaActores[i].inicioContrato.anio = 0;
        listaActores[i].finalContrato.dia = 0;
        listaActores[i].finalContrato.mes = 0;
        listaActores[i].finalContrato.anio = 0;
        listaActores[i].ganoOscar = 0;*/

    }
}

void mostrar_actor(eActor actor){
	//printf("| Nombre |-| Apellido |-| Personaje |-|   Rol   |-|  Valor  |-| Fecha Inicio |-|Fecha Final|-| Gano Oscar |\n");
	printf("| %s |-| %s |-| %s |-| %s  |-| %s |-|  $%.2f |-| %d/%d/%d |-| %d/%d/%d |-| %d |\n", actor.nombre, actor.apellido, actor.personaje, actor.rol, actor.pelicula.titulo, actor.contratoMensual, actor.inicioContrato.dia, actor.inicioContrato.mes, actor.inicioContrato.anio, actor.finalContrato.dia, actor.finalContrato.mes, actor.finalContrato.anio, actor.ganoOscar);
}

void mostrar_actores(eActor listaActores[], int tam){
	for(int i = 0; i < tam; i++){
		if(listaActores[i].vacio == 1){
			mostrar_actor(listaActores[i]);
		}
	}
}


int ordenar_actores_contrato(eActor listaActores[], int tam){
	eActor auxiliar;
	int retorno = 0;
	for(int i = 0; i < tam - 1; i ++){
		for(int j = i + 1; j < tam ; j ++ ){
			if(listaActores[i].contratoMensual < listaActores[j].contratoMensual){
				auxiliar = listaActores[i];
				listaActores[i] = listaActores[j];
				listaActores[j] = auxiliar;
				retorno = 1;
			}
		}
	}
	mostrar_actores(listaActores, tam);
	return retorno;
}

int ordenar_actores_pelicula(eActor listaActores[], int tam){
	eActor auxiliar;
	int retorno = 0;
	for(int i = 0; i < tam - 1; i ++){
		for(int j = i + 1; j < tam ; j ++ ){
				if(strcmp(listaActores[i].pelicula.titulo, listaActores[j].pelicula.titulo) > 0){
					auxiliar = listaActores[i];
					listaActores[i]=listaActores[j];
					listaActores[j]= auxiliar;
					retorno = 1;
				}
		}
	}
	mostrar_actores(listaActores, tam);
	return retorno;
}
