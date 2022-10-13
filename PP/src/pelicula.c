/*
 * pelicula.c
 *
 *  Created on: 11 oct. 2022
 *      Author: mauropanzini
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "actor.h"
#include "menu.h"
#include "pelicula.h"
#include "validaciones.h"
#include "fecha.h"

ePelicula pedir_datos_pelicula(void){
	ePelicula pelicula;
	pelicula.codigo = obtener_int(100, 1, "\nIngrese el código de la pelicula: \n", "Error, ingrese un código válido (debe estar entre 1 y 100): \n");
	strcpy(pelicula.titulo, obtener_string_sin_validar("\nIngrese el nombre de la película: \n"));
	pelicula.duracion = obtener_int(500, 60, "\nIngrese la duración de la película: \n", "Error, ingrese un valor válido: \n");
	strcpy(pelicula.director, obtener_string("\n Ingrese el nombre del director: \n", "Error, ingrese un nombre válido: \n"));

	pelicula.fechaEstreno.dia = obtener_int(31, 1, "Introduzca el día de estreno: \n", "Error, ingrese un valor válido: \n");
	pelicula.fechaEstreno.mes = obtener_int(12, 1, "Introduzca el mes de estreno: \n", "Error, ingrese un valor válido: \n");
	pelicula.fechaEstreno.anio= obtener_int(2120, 2022, "Introduzca el año de estreno: \n", "Error, ingrese un valor válido: \n");

	pelicula.recaudacion = random_num(750000000, 150000000);

	return pelicula;
}
int alta_pelicula(ePelicula listaPeliculas[], int tam){
	int retorno = 0;
	for(int i = 0 ; i < tam ; i++){
		if(listaPeliculas[i].vacio == 0){
			listaPeliculas[i] = pedir_datos_pelicula();
			retorno = 1;
			break;
		  }
	}
	return retorno;
}
int hardcodeo_peliculas(ePelicula listaPeliculas[], int tam){
	int retorno = 0;
	int i = 0;
		listaPeliculas[i].codigo = i;
		strcpy(listaPeliculas[i].titulo,"IronGirl 27");
		listaPeliculas[i].duracion = 127;
		strcpy(listaPeliculas[i].director, "Jeff Bezos");
		listaPeliculas[i].fechaEstreno.dia = 12;
		listaPeliculas[i].fechaEstreno.mes = 9;
		listaPeliculas[i].fechaEstreno.anio= 2059;
		listaPeliculas[i].ganoOscar = random_num(0, 5);

		i++;
		listaPeliculas[i].codigo = i;
		strcpy(listaPeliculas[i].titulo,"Wakanda forthewin");
		listaPeliculas[i].duracion = 80;
		strcpy(listaPeliculas[i].director, "Elon Musk");
		listaPeliculas[i].fechaEstreno.dia = 8;
		listaPeliculas[i].fechaEstreno.mes = 12;
		listaPeliculas[i].fechaEstreno.anio= 2070;
		listaPeliculas[i].ganoOscar = random_num(0, 5);

		i++;
		listaPeliculas[i].codigo = i;
		strcpy(listaPeliculas[i].titulo,"The he/she hulk");
		listaPeliculas[i].duracion = 127;
		strcpy(listaPeliculas[i].director, "Paul Rudd");
		listaPeliculas[i].fechaEstreno.dia = 3;
		listaPeliculas[i].fechaEstreno.mes = 5;
		listaPeliculas[i].fechaEstreno.anio= 2047;
		listaPeliculas[i].ganoOscar = random_num(0, 5);

		i++;
		listaPeliculas[i].codigo = i;
		strcpy(listaPeliculas[i].titulo,"What if not?");
		listaPeliculas[i].duracion = 250;
		strcpy(listaPeliculas[i].director, "Emma Watson");
		listaPeliculas[i].fechaEstreno.dia = 20;
		listaPeliculas[i].fechaEstreno.mes = 9;
		listaPeliculas[i].fechaEstreno.anio= 2063;
		listaPeliculas[i].ganoOscar = random_num(0, 5);

		i++;
		listaPeliculas[i].codigo = i;
		strcpy(listaPeliculas[i].titulo,"Mickey Love n Thunder");
		listaPeliculas[i].duracion = 250;
		strcpy(listaPeliculas[i].director, "Walter Disney");
		listaPeliculas[i].fechaEstreno.dia = 15;
		listaPeliculas[i].fechaEstreno.mes = 11;
		listaPeliculas[i].fechaEstreno.anio= 2050;
		listaPeliculas[i].ganoOscar = random_num(0, 5);
		return retorno;
}

void inicializar_lista_peliculas(ePelicula listaPeliculas[], int tam){
    for(int i = 0 ; i < tam ; i++)
    {
        listaPeliculas[i].vacio = 0;
    }
}
void recaudacion_peliculas(ePelicula listaPeliculas[], int tam){
	for(int i = 0 ; i < tam ; i++)
	    {
	        listaPeliculas[i].recaudacion = random_num(750000000, 150000000);
	    }
}
int baja_pelicula(ePelicula listaPeliculas[], int tam){
	int codigoPelicula;
	int retorno = 0;
	codigoPelicula = obtener_int(5, 1, "\nIngrese el codigo de la pelicula a borrar: \n", "\nError, codigo inválido, ingrese nuevamente: \n");
	for(int i=0; i < tam; i++){
		if(listaPeliculas[i].vacio == 1){
			if(listaPeliculas[i].codigo == codigoPelicula){
				listaPeliculas[i].vacio = 0;
	             retorno = 1;
	             break;
	            }
	        }
	    }
	return retorno;
}

