#include <iostream>
#include <stdio.h>
#include <stdio.h>

using namespace std;

struct caract{			//caracteristicas
	char nombre[50];			//para hacer una lista de los nombres de las máquinas con los valores
	char NombreMaquina[50];
	int Tension;
	int Corriente;
};

void agregar_maquina(struct caract *maq, int *cant);
void valmax(struct caract *maq, int cant);

//tengo que agregar una pantalla donde me deje ingresar el nombre del aparato 
//y los valores de tension y corriente
int main(int argc, char *argv[]) {
	int opcion;
	int cantidad=0;
	struct caract *maquina;
	
	/*int T,I;*/
	printf("\t Seleccione una opción\n1- Guardar máquina\n2- Mostrar 2 valores de maximos\n");
	scanf("%d", opcion);
	
	do{
		switch(opcion){
		case 1:
			agregar_maquina(&maquina, &cantidad);
			break;
			
		case 2:
			//			printf("Los valores Máximos de tensión y de corriente de la máquina son:\n");
			//			valmax(maquinas, &cantidad);
			break;
			
		case 3:
			opcion=3;
			break;
			
		default:
			printf("\n¡Opción Incorrecta!");
		}
	}while (opcion!=3);
	return 0;
}


void agregar_maquina(struct caract *maq, int *cant){		//para guardar los valores
	printf("Dar el nombre de la máquina %d: ", (*cant)+1);
	scanf("%s", &maq[*cant].NombreMaquina);
	printf("\nIngrese el valor de tensión: ");
	scanf("%d", &maq[*cant].Tension);
	printf("\nIngrese el valor de corrietente");
	scanf("%d", &maq[*cant].Corriente);
	
	*cant++;		//aumentamos para guardar más variables
}
	
//void valmax(struct caract *maq,int cant){
//	if (cant==0){
//		printf("No hay nada guardado");
//	}
//	for(int i=0, i<cantidad_elementos, i++){
//	
//	}
//}

