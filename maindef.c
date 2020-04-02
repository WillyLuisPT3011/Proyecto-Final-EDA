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
//void buscarDato();

int main(){
	short opcion = 0;
	
	while(1){       
		printf("\n\t*** BASE DE DATOS ***\n");         
			printf("1) INSERTAR REGISTRO :\n");
			printf("2) MOSTRAR REGISTROS :\n");
			//printf("3) BUSCAR REGISTRO :\n");
			//printf("4) ELIMINAR REGISTRO :\n");   
     		printf("3) SALIR.\n"); //5)        
			scanf("%d", &opcion);         
			switch(opcion){             
				case 1:                 
					ingresarDato();                
					break;             
				case 2:                 
					mostrarDato();                
					break;
				//case 3:
					//buscarDato();
					//break;
				//case 4:
					//eliminarDato();
					//break;              
				case 3: //case 5:                 
					return 0;             
				default:                 
					printf("Opción no válida.\n");         
		     
	 		}
	}
	return 0;
}

void ingresarDato(){
	FILE *fich;
	DATO e;
	
	if((fich = fopen("Registro","ab"))==NULL){
		printf("\nFichero no existe! ");
	}else{
		
		printf("\n Ingrese Asunto o Nombre: "); fflush(stdin);
		gets(e.asunto);
		printf(" Ingrese Fecha[Separar los dias, meses y año con /] o numero: "); fflush(stdin);
		scanf("%s",&e.fecha);
		printf(" Ingrese Informacion (poner el nombre del archivo y/o imagen con []): "); fflush(stdin);
		gets(e.info);
		fwrite(&e,sizeof(e),1,fich);	// Escribe todo lo que tenemos en la estructura en el fichero . . . .. . 
		fclose(fich);	//Cierra el fichero para que no quede abierto . . . . .
	}
}

void mostrarDato(){
	FILE *fich;
	DATO e;
	
	if((fich = fopen("Registro","rb")) == NULL){
		printf("\n Fichero no existe ");
	}else{
		
		fread(&e,sizeof(e),1,fich);	// Lee los registros del Fichero Posicion por posicion . . . .
		while(! feof(fich)){	// Recorriendo el Fichero . . . .
			printf("\n ____________________________");
			printf("\n Nombre/Asunto......: %s",e.asunto);
			printf("\n Fecha/Numero........: %s",e.fecha);
			printf("\n Informacion......: %s",e.info);
			printf("\n ____________________________");
			fread(&e,sizeof(e),1,fich);
		}
	}
	fclose(fich);
	getch();
}

//void buscarDato();

//void eliminarDato();


	

 
