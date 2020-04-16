#include <stdio.h>    /* Funciones principales */
#include <string.h>   /* operaciones de manipulaci�n de memoria */
#include <stdlib.h>   /* Gesti�n de memoria din�mica, control de procesos, etc */
#include <locale.h>   /* configuraci�n regional actual */
 
#define MAX 100 
#define VALOR_CENTINELA -1
 
struct informacion {
    char numero[MAX];
    char nombre[MAX];
    char info[MAX];
    char archivo[MAX];
    
};
 
typedef struct informacion Informacion;
 
void menuPrincipal();
void menuInsertar();
void menuBuscar();
void menuEliminar();
void menuMostrar();
void menuModificar();
void menuEliminarFisica();
 
/* Funciones para manejar el archivo directamente */
Informacion *obtenerInformaciones(int *n); /* Obtiene un vector din�mico de archivos */
char existeInformacion(int codigoInformacion, Informacion *informacion); 
char insertarInformacion(Informacion informacion); 
char eliminarInformacion(int codigoInformacion); 
char eliminacionFisica(); 
char modificarInformacion(Informacion informacion); 
char guardarReporte(); /* Genera un archivo TXT */
 
/* Funci�n de lectura de cadenas */
int leecad(char *cad, int n);
 
/* Titular del programa */
void tituloPrincipal();
 
char linea[MAX];
 
int main()
{
    setlocale(LC_ALL, "spanish"); /* Permite imprimir caracteres con tilde */
    menuPrincipal();
 
    return 0;
}
 
void menuPrincipal()
{
    char repite = 1;
    int opcion = -1;
    /* Cuando el usuario ingresa texto en lugar de ingresar una opci�n. El programa no modifica
    el valor de opcion. En ese caso, no se debe de ingresar a ninguno de los case, por eso se est�
    inicializando la variable opcion con un valor que no permita ejecutar ning�n case. Simplemente,
    volver a interar y pedir nuevamente la opci�n. */
 
    do {
        system("cls");
 
        tituloPrincipal();
 
        printf("\n\t\t\t\tMENU PRINCIPAL\n");
        printf("\n\t\t[1]. Insertar nuevo registro\n");
        printf("\t\t[2]. Mostrar listado de registros\n");
        printf("\t\t[3]. Eliminar un registro\n");
        printf("\t\t[4]. Buscar registro por numero o fecha\n");
        printf("\t\t[5]. Modificar un registro\n");
        printf("\t\t[6]. Eliminaci�n f�sica de registros\n");
        printf("\t\t[7]. Salir\n");
        printf("\n\t\tIngrese su opci�n: [ ]\b\b");
 
        /* Lectura segura de un entero */
        leecad(linea, MAX);
        sscanf(linea, "%d", &opcion);
 
        switch (opcion) {
 
            case 1:
                menuInsertar();
                break;
 
            case 2:
                menuMostrar();
                break;
 
            case 3:
                menuEliminar();
                break;
 
            case 4:
                menuBuscar();
                break;
 
            case 5:
                menuModificar();
                break;
 
            case 6:
                menuEliminarFisica();
                break;
 
            case 7:
                repite = 0;
                break;
        }
 
    } while (repite);
}

void menuInsertar(){
	
    Informacion informacion;
    int codigoInformacion = 0;
    char repite = 1;
    char respuesta[MAX];
 
    do {
        system("cls");
        tituloPrincipal();
        printf("\n\t\t\t==> INSERTAR INFORMACION <==\n");
 
        /* Se pide el c�digo del producto a insertar */
        printf("\n\tFecha o numero: ");
        leecad(linea, MAX);
        sscanf(linea, "%s", &codigoInformacion);
 
        /* Se verifica que el producto no haya sido almacenado anteriormente */
        if (!existeInformacion(codigoInformacion, &informacion)){
 
            informacion.codigo = codigoInformacion;
 
            /* Se piden los dem�s datos del producto a insertar */
            printf("\tNombre del registro: ");
            leecad(informacion.nombre, MAX);
 
            printf("\tDescripcion: ");
            leecad(informacion.descripcion, MAX);
 
            printf("\tArchivo: ");
            leecad(informacion.archivo, MAX);
             
            if (insertarInformacion(informacion)) {
                printf("\n\tEl registro fue insertado correctamente\n");
 
            } else {
                printf("\n\tOcurri� un error al intentar insertar el registro\n");
                printf("\tInt�ntelo mas tarde\n");
            }
        } else {
            /* El registro ya existe, no puede ser insertado. */
            printf("\n\tLa informaci�n de fecha o numero %f ya existe.\n", codigoInformacion);
            printf("\tNo puede ingresar dos registros distintos con el mismo c�digo.\n");
        }
 
        printf("\n\tDesea seguir ingresando registros? [S/N]: ");
        leecad(respuesta, MAX);
 
        if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0)) {
            repite = 0;
        }
 
    } while (repite);
}

void menuBuscar(){
    Informacion informacion;
    int codigoInformacion;
    char repite = 1;
    char respuesta[MAX];
 
    do {
        system("cls");
        tituloPrincipal();
        printf("\n\t\t\t==> BUSCAR REGISTRO POR FECHA O NUMERO <==\n");
 
        /* Se pide el c�digo del producto a buscar */
        printf("\n\tFecha o numero del registro: ");
        leecad(linea, MAX);
        sscanf(linea, "%s", &codigoInformacion);
 
        /* Se verifica que el registro a buscar, exista */
        if (existeInformacion(codigoInformacion, &informacion)) {
 
            /* Se muestran los datos del producto */
            printf("\n\tFecha o numero del registro: %s\n", informacion.codigo);
            printf("\tNombre del registro: %s\n", informacion.nombre);            
            printf("\tDescripcion del registro: %s\n", informacion.descripcion);
            printf("\tArchivo del registro: %s\n", informacion.archivo);
 
        } else {
            /* El producto no existe */
            printf("\n\tEl registro de la fecha o numero %s no existe.\n", codigoInformacion);
        }
 
        printf("\n\tDesea seguir buscando alg�n producto? [S/N]: ");
        leecad(respuesta, MAX);
 
        if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0)) {
            repite = 0;
        }
 
    } while (repite);
}

void menuEliminar()
{
    Informacion informacion;
    int codigoInformacion;
    char repite = 1;
    char respuesta[MAX];
 
    do {
        system("cls");
        tituloPrincipal();
        printf("\n\t\t\t==> ELIMINAR REGISTRO POR FECHA O NUMERO <==\n");
 
        /* Se pide la fecha o el numero del registro a eliminar */
        printf("\n\tFecha o numero del registro: ");
        leecad(linea, MAX);
        sscanf(linea, "%s", &codigoInformacion);
 
        /* Se verifica que el registro a buscar, exista */
        if (existeInformacion(codigoInformacion, &informacion)) {
 
            /* Se muestran los datos del registro */
            printf("\n\tFecha o numero del registro: %d\n", informacion.codigo);
            printf("\tNombre del registro: %s\n", informacion.nombre);            
            printf("\tDescripcion del registro: %s\n", informacion.descripcion);
            printf("\tArchivo del registro: %s\n", informacion.archivo);
 
            printf("\n\tSeguro que desea eliminar el registro? [S/N]: ");
            leecad(respuesta, MAX);
            if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
                if (eliminarInformacion(codigoInformacion)) {
                    printf("\n\tRegistro eliminado satisfactoriamente.\n");
                } else {
                    printf("\n\tEl registro no pudo ser eliminado\n");
                }
            }
 
        } else {
            /* El registro no existe */
            printf("\n\tEl registro de la fecha o numero %d no existe.\n", codigoInformacion);
        }
 
        printf("\n\tDesea eliminar otro registro? [S/N]: ");
        leecad(respuesta, MAX);
 
        if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0)) {
            repite = 0;
        }
 
    } while (repite);
}
