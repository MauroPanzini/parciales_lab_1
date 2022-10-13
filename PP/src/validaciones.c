/*
 * validaciones.c
 *
 *  Created on: 9 oct. 2022
 *      Author: Mau
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int elegirOpcion(int max, int min){
	int retorno;
	printf("\nIngrese una opcion:\n");
	scanf("%d", &retorno);
	while(retorno > max || retorno < min){
		printf("\nOpcion invalida, ingrese nuevamente:\n");
		scanf("%d", &retorno);
	}
	return retorno;
}

int es_string(char cadena[]){
	int retorno = 1;
	for(int i = 0; i <= (strlen(cadena)-1); i++){
		if(!(isalpha(cadena[i]))){
			retorno = 0;
			break;
		}
	}

	return retorno;
}

char* obtener_string(char* mensaje, char* mensajeError){
	static char retorno[30];

	printf("\n%s", mensaje);

	scanf("\n%s", retorno);
	while(es_string(retorno) == 0){
		printf("%s", mensajeError);
		scanf("%s", retorno);
	}

	return retorno;
}

char* obtener_string_sin_validar(char* mensaje){
	static char retorno[30];
	printf("\n%s", mensaje);
	fpurge (stdin);
	scanf("\n%s", retorno);

	return retorno;
}

float obtener_float(int max, int min, char* mensaje, char* mensajeError){
	float retorno = 0;
	printf("\n%s", mensaje);
	scanf("\n%f", &retorno);
	while(retorno < min || retorno > max){
		printf("\n%s", mensajeError);
		scanf("\n%f", &retorno);
	}
	return retorno;
}
int obtener_int(int max, int min, char* mensaje, char* mensajeError){
	int retorno = 0;
	printf("\n%s", mensaje);
	scanf("\n%d", &retorno);
	while(retorno < min || retorno > max){
		printf("\n%s", mensajeError);
		scanf("\n%d", &retorno);
	}
	return retorno;
}
int random_num(int max, int min){
	int retorno;

	srand(time(NULL));
	retorno = (rand() % (max-min + 1)) + min;

	return retorno;
}

