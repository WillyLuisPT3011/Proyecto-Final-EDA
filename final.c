#include <stdio.h>    /* Funciones principales */
#include <string.h>   /* operaciones de manipulación de memoria */
#include <stdlib.h>   /* Gestión de memoria dinámica, control de procesos, etc */
#include <locale.h>   /* configuración regional actual */
 
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
Informacion *obtenerInformaciones(int *n); /* Obtiene un vector dinámico de archivos */
char existeInformacion(int codigoInformacion, Informacion *informacion); 
char insertarInformacion(Informacion informacion); 
char eliminarInformacion(int codigoInformacion); 
char eliminacionFisica(); 
char modificarInformacion(Informacion informacion); 
char guardarReporte(); /* Genera un archivo TXT */
 
/* Función de lectura de cadenas */
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
    /* Cuando el usuario ingresa texto en lugar de ingresar una opción. El programa no modifica
    el valor de opcion. En ese caso, no se debe de ingresar a ninguno de los case, por eso se está
    inicializando la variable opcion con un valor que no permita ejecutar ningún case. Simplemente,
    volver a interar y pedir nuevamente la opción. */
 
    do {
        system("cls");
 
        tituloPrincipal();
 
        printf("\n\t\t\t\tMENU PRINCIPAL\n");
        printf("\n\t\t[1]. Insertar nuevo registro\n");
        printf("\t\t[2]. Mostrar listado de registros\n");
        printf("\t\t[3]. Eliminar un registro\n");
        printf("\t\t[4]. Buscar registro por numero o fecha\n");
        printf("\t\t[5]. Modificar un registro\n");
        printf("\t\t[6]. Eliminación física de registros\n");
        printf("\t\t[7]. Salir\n");
        printf("\n\t\tIngrese su opción: [ ]\b\b");
 
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
