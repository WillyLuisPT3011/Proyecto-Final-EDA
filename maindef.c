#include <stdio.h>

/*     
	Programa para el almacenamiento de cualquier tipo de informacion 
*/ 

struct datos{
	char asunto[30];
	char fecha[30];
	char info[30];
};
typedef struct datos DATO;

void ingresarDato();
void mostrarDato(); 
void buscarDato();
void eliminarDato();

int main(){
	short opcion = 0;
	
	while(1){       
		printf("\n\t*** BASE DE DATOS ***\n");         
			printf("1) INSERTAR REGISTRO :\n");
			printf("2) MOSTRAR REGISTROS :\n");
			printf("3) BUSCAR REGISTROS :\n");
			printf("4) ELIMINAR REGISTROS :\n");
     		printf("5) SALIR.\n");         
			scanf("%d", &opcion);         
			switch(opcion){             
				case 1:                 
					ingresarDato();                
					break;             
				case 2:                 
					mostrarDato();                
					break;
				case 3:
					buscarDato();
					break;
				case 4:
					eliminarDato();
					break;              
				case 5:                 
					return 0;             
				default:                 
					printf("Opción no válida.\n");         
		     
	 		}
	}
	return 0;
}

void ingresarDato(){
}

void mostrarDato(){
}

void buscarDato(){
}

void eliminarDato(){
}
	

 
