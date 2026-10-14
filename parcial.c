#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50
struct Maquina{
	char NombreMaquina[MAX];
	int Tension;
	int Corriente;
};

struct Maquina* agregarMaquina(struct Maquina *arreglo, int *cantidad);
void mostrarDosMaximos(struct Maquina *arreglo, int cantidad);
void mostrarCadenas(struct Maquina *arreglo, int cantidad);

int main() {
	struct Maquina *maquinas = NULL; 
	int cantidad = 0;        
	int opcion;
	
	do {
		printf("\n1. Agregar\n2. Mostrar 2 Maximos\n3. Ver todas\n0. Salir\nOpcion: ");
		scanf("%d", &opcion);
		
		switch (opcion) {
		case 1:
			maquinas = agregarMaquina(maquinas, &cantidad);
			break;
		case 2:
			mostrarDosMaximos(maquinas, cantidad);
			break;
		case 3:
			mostrarCadenas(maquinas, cantidad);
			break;
		}
	} while (opcion != 0);
	
	free(maquinas);
	return 0;
}

/**
* Agrega una nueva maquina al arreglo usando memoria dinamica.
* @param arreglo Puntero al arreglo de maquinas.
* @param cantidad Puntero a la variable que guarda la cantidad actual de maquinas.
* Entrada: Pide al usuario nombre, tension y corriente.
* Salida: Retorna el puntero al arreglo redimensionado.
*/

struct Maquina* agregarMaquina(struct Maquina *arreglo, int *cantidad) {
	// Estiramos la memoria para 1 maquina más
	arreglo = (struct Maquina *)realloc(arreglo, (*cantidad + 1) * sizeof(struct Maquina));
	
	// Puntero apuntando al espacio nuevo
	struct Maquina *nueva = (arreglo + *cantidad);
	
	printf("Nombre de la maquina: ");
	getchar();
	fgets(nueva->NombreMaquina, MAX ,stdin);
	*(nueva->NombreMaquina + strcspn(nueva->NombreMaquina, "\n")) = '\0';  //elimino el enter
	
	printf("Tension: ");
	scanf("%d", &(nueva->Tension));
	
	printf("Corriente: ");
	scanf("%d", &(nueva->Corriente));
	
	(*cantidad)++; // Sumamos 1 al total
	return arreglo; 
}


/**
* Busca e imprime en pantalla los 2 valores maximos seleccionados.
* @param arreglo Puntero al arreglo de maquinas.
* @param cantidad Cantidad total de maquinas registradas.
* Entrada: Solicita al usuario elegir entre Tension o Corriente.
* Comportamiento: Compara valores y guarda las posiciones de los mayores.
*/

void mostrarDosMaximos(struct Maquina *arreglo, int cantidad) {
	int opcion_var;
	printf("Buscar por:\n1. Tension\n2. Corriente\nOpcion: ");
	scanf("%d", &opcion_var);
	
	int max1 = 0, max2 = 1; 
	
	for (int i = 0; i < cantidad; i++) {
		int valorActual, valorMax1, valorMax2;
		
		if (opcion_var == 1) {
			valorActual = (arreglo + i)->Tension;
			valorMax1 = (arreglo + max1)->Tension;
			valorMax2 = (arreglo + max2)->Tension;
		} else {
			valorActual = (arreglo + i)->Corriente;
			valorMax1 = (arreglo + max1)->Corriente;
			valorMax2 = (arreglo + max2)->Corriente;
		}
		
		if (valorActual > valorMax1) {
			max2 = max1; 
			max1 = i;    
		} else if (valorActual > valorMax2 && i != max1) {
			max2 = i;    
		}
	}
	
	printf("\n-- LOS 2 MAS GRANDES --\n");
	if (opcion_var == 1) {
		printf("1. %s (%dV)\n", (arreglo + max1)->NombreMaquina, (arreglo + max1)->Tension);
		printf("2. %s (%dV)\n", (arreglo + max2)->NombreMaquina, (arreglo + max2)->Tension);
	} else {
		printf("1. %s (%dA)\n", (arreglo + max1)->NombreMaquina, (arreglo + max1)->Corriente);
		printf("2. %s (%dA)\n", (arreglo + max2)->NombreMaquina, (arreglo + max2)->Corriente);
	}
}

/**
* Muestra el listado de todas las maquinas registradas con sus valores.
* @param arreglo Puntero al arreglo de maquinas.
* @param cantidad Cantidad total de maquinas registradas.
* Comportamiento: Usa strcpy y strcat para formatear el texto antes de imprimir.
*/

void mostrarCadenas(struct Maquina *arreglo, int cantidad) {
	for (int i = 0; i < cantidad; i++) {
		char texto[100]; 
		strcpy(texto, "Maquina: "); 
		
		// CONCATENAR
		strcat(texto, (arreglo + i)->NombreMaquina);
		
		printf("%s | Tension: %d | Corriente: %d\n", 
			   texto, (arreglo + i)->Tension, (arreglo + i)->Corriente);
	}
}
