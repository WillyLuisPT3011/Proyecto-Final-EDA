#include <stdio.h>

struct datos{
	char asunto[30];
	char fecha[30];
	char info[30];
};
typedef struct datos DATO;


char menu();
void insertar();
void mostrar();

int main(void){
	char op;
	do{
		op = menu();
		switch(op){
			case '1':
				system("cls");
				insertar();
			break;
			case '2':
				system("cls");
				mostrar();
			break;
		}
	}while(op!='3');
	return 0;
}
char menu(){
	char op;
	system("cls");
	printf("\n  * * MENU * *");
	printf("\n (1)INSERTAR REGISTRO :");
	printf("\n (2)MOSTRAR REGISTROS :");
	printf("\n (3)SALIR");
	printf("\n Opcion --> "); fflush(stdin);
	op = getch();
	return op;
}

void insertar(){
	FILE *fich;
	DATO e;
	
	if((fich = fopen("Registro","ab"))==NULL){
		printf("\nFichero no existe! ");
	}else{
		
		printf("\n Ingrese Asunto: "); fflush(stdin);
		gets(e.asunto);
		printf(" Ingrese Fecha: "); fflush(stdin);
		scanf("%s",&e.fecha);
		printf(" Ingrese Informacion: "); fflush(stdin);
		gets(e.info);
		
		fwrite(&e,sizeof(e),1,fich);	// Escribe todo lo que tenemos en la estructura en el fichero . . . .. . 
		fclose(fich);	//Cierra el fichero para que no quede abierto . . . . .
	}
}

void mostrar(){
	FILE *fich;
	DATO e;
	
	if((fich = fopen("Registro","rb")) == NULL){
		printf("\n Fichero no existe ");
	}else{
		
		fread(&e,sizeof(e),1,fich);	// Lee los registros del Fichero Posicion por posicion . . . .
		while(! feof(fich)){	// Recorriendo el Fichero . . . .
			printf("\n ____________________________");
			printf("\n Nombre......: %s",e.asunto);
			printf("\n Edad........: %s",e.fecha);
			printf("\n Ciudad......: %s",e.info);
			printf("\n ____________________________");
			fread(&e,sizeof(e),1,fich);
		}
	}
	fclose(fich);
	getch();
}

