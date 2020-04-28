#include <stdio.h>    /* Funciones principales */
#include <string.h>   /* operaciones de manipulaci�n de memoria */
#include <stdlib.h>   /* Gesti�n de memoria din�mica, control de procesos, etc */
#include <locale.h>   /* configuraci�n regional actual */
 
#define MAX  100
#define VALOR_CENTINELA -1
 
struct informacion {
    int codigo;
    char nombre[MAX];
    char descripcion[MAX];
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
            sscanf(linea, "%s", &informacion.descripcion);
 
            printf("\tArchivo: ");
            leecad(informacion.archivo, MAX);
            sscanf(linea, "%s", &informacion.archivo);
             
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

void menuMostrar()
{
    Informacion *informaciones;
    int numeroInformaciones;
    int i;
    char respuesta[MAX];
 
    system("cls");
    tituloPrincipal();
    informaciones = obtenerInformaciones(&numeroInformaciones); /* Retorna un vector din�mico de la informacion */
 
    if (numeroInformaciones == 0) {
        printf("\n\tEl archivo est� vac�o!!\n");
        system("pause>nul");
 
    } else {
        printf("\n\t\t    ==> LISTADO DE REGISTROS INGRESADOS <==\n");
        printf(" ------------------------------------------------------------------------------\n");
        printf("%8s\t%-20s%15s%15s\n", "FECHA O NUMERO", "NOMBRE DEL REGISTRO", "DESCRIPCION", "ARCHIVO");
        printf(" ------------------------------------------------------------------------------\n");
 
        /* Se recorre el vector din�mico de productos */
        for (i = 0; i < numeroInformaciones; i++) {
            if (informaciones[i].codigo != VALOR_CENTINELA) {
                printf("%7s \t%-20s%15s%15s\n", informaciones[i].codigo, informaciones[i].nombre, informaciones[i].descripcion, informaciones[i].archivo);
            }
        }

        printf("\n\tDesea guardar el reporte en un archivo de texto? [S/N]: ");
        leecad(respuesta, MAX);
 
        if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
            if (guardarReporte()) {
                printf("\n\tEl reporte fue guardado con �xito\n");
            } else {
                printf("\n\tOcurri� un error al guardar el reporte\n");
            }
 
            system("pause>nul");
        }
    }
}

void menuModificar()
{
    Informacion informacion;
    int codigoInformacion;
    char repite = 1;
    char respuesta[MAX];
 
    do {
        system("cls");
        tituloPrincipal();
        printf("\n\t\t\t==> MODIFICAR REGISTRO POR FECHA O NUMERO <==\n");
 
        /* Se pide la fecha o el numero del registro a modificar */
        printf("\n\tFecha o numero del registro: ");
        leecad(linea, MAX);
        sscanf(linea, "%s", &codigoInformacion);
 
        /* Se verifica que el producto a buscar exista */
        if (existeInformacion(codigoInformacion, &informacion)) {
 
            /* Se muestran los datos del registro */
            printf("\n\tNombre del registro: %s\n", informacion.nombre);
            printf("\tDescripcion: %s\n", informacion.descripcion);
            printf("\tArchivo: %s\n", informacion.archivo);
 
            printf("\n\tElija los datos a modificar\n");
 
            /* Modificaci�n del nombre del registro */
            printf("\n\tNombre del registro actual: %s\n", informacion.nombre);
            printf("\tDesea modificar el nombre del registro? [S/N]: ");
            leecad(respuesta, MAX);
            if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
                printf("\tNuevo nombre del registro: ");
                leecad(informacion.nombre, MAX);
            }
 
            /* Modificaci�n de la descripcion del registro */
            printf("\n\tDescripcion: %s\n", informacion.descripcion);
            printf("\tDesea modificar la descripcion? [S/N]: ");
            leecad(respuesta, MAX);
            if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
                printf("\tNueva descripcion del registro: ");
                leecad(linea, MAX);
                sscanf(linea, "%s", &informacion.descripcion);
            }
 
            /* Modificaci�n del archivo del registro */
            printf("\n\tArchivo del registro actual: %s\n", informacion.archivo);
            printf("\tDesea modificar el archivo del registro? [S/N]: ");
            leecad(respuesta, MAX);
            if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
                printf("\tNuevo archivo del registro: ");
                leecad(linea, MAX);
                sscanf(linea, "%s", &informacion.archivo);
            }
 
            printf("\n\tEst� seguro que desea modificar los datos del registro? [S/N]: ");
            leecad(respuesta, MAX);
 
            if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
                /* Se modifica el registro en el archivo */
                if (modificarInformacion(informacion)) {
                    printf("\n\tEl registro fue modificado correctamente\n");
 
                } else {
                    printf("\n\tOcurri� un error al intentar modificar el registro\n");
                    printf("\tInt�ntelo mas tarde\n");
                }
            }
        } else {
            /* El registro no existe */
            printf("\n\tEl registro de la fecha o del numero %s no existe.\n", codigoInformacion);
        }
 
        printf("\n\tDesea modificar alg�n otro registro? [S/N]: ");
        leecad(respuesta, MAX);
 
        if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0)) {
            repite = 0;
        }
 
    } while (repite);
}

void menuEliminarFisica(){
	
    char respuesta[MAX];
 
    system("cls");
    tituloPrincipal();
    printf("\n\t\t==> ELIMINAR F�SICAMENTE REGISTROS DEL ARCHIVO <==\n");
 
    /* Se pide el c�digo del registro a eliminar */
    printf("\n\tSeguro que desea proceder con la eliminaci�n f�sica? [S/N]: ");
    leecad(respuesta, MAX);
 
    if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
        if (eliminacionFisica()) {
            printf("\n\tLa eliminaci�n f�sica se realiz� con �xito.\n");
        } else {
            printf("\n\tOcurri� alg�n error en la eliminaci�n f�sica.\n");
        }
 
        system("pause>nul");
    }
}

Informacion *obtenerInformaciones(int *n){
	
    FILE *archivo;
    Informacion informacion;
    Informacion *informaciones; /* Vector din�mico de informacion */
    int i;
 
    /* Abre el archivo en modo lectura */
    archivo = fopen("informacion.dat", "rb");
 
    if (archivo == NULL) { /* Si no se pudo abrir el archivo, el valor de archivo es NULL */
        *n = 0; /* No se pudo abrir. Se considera n  */
        informaciones = NULL;
 
    } else {
 
        fseek(archivo, 0, SEEK_END); /* Posiciona el cursor al final del archivo */
        *n = ftell(archivo) / sizeof(Informacion); /* # de registros almacenados en el archivo. (# de registros) */
        informaciones = (Informacion *)malloc((*n) * sizeof(Informacion)); /* Se reserva memoria para todos los registros almacenados en el archivo */
 
        /* Se recorre el archivo secuencialmente */
        fseek(archivo, 0, SEEK_SET); /* Posiciona el cursor al principio del archivo */
        fread(&informacion, sizeof(informacion), 1, archivo);
        i = 0;
        while (!feof(archivo)) {
            informaciones[i++] = informacion;
            fread(&informacion, sizeof(informacion), 1, archivo);
        }
 
        /* Cierra el archivo */
        fclose(archivo);
    }
 
    return informaciones;
}

char existeInformacion(int codigoInformacion, Informacion *informacion)
{
    FILE *archivo;
    char existe;
 
    /* Abre el archivo en modo lectura */
    archivo = fopen("informacion.dat", "rb");
 
    if (archivo == NULL) { /* Si no se pudo abrir el archivo, el valor de archivo es NULL */
        existe = 0;
 
    } else {
        existe = 0;
 
        /* Se busca el registro cuyo c�digo coincida con codigoInformacion */
        fread(&(*informacion), sizeof(*informacion), 1, archivo);
        while (!feof(archivo)) {
            if ((*informacion).codigo == codigoInformacion) {
                existe = 1;
                break;
            }
            fread(&(*informacion), sizeof(*informacion), 1, archivo);
        }
 
        /* Cierra el archivo */
        fclose(archivo);
    }
 
    return existe;
}

char insertarInformacion(Informacion informacion)
{
    FILE *archivo;
    char insercion;
 
    /* Abre el archivo para agregar datos al final */
    archivo = fopen("Informacion.dat", "ab");    /* A�ade datos al final. Si el archivo no existe, es creado */
 
    if (archivo == NULL) { /* Si no se pudo abrir el archivo, el valor de archivo es NULL */
        insercion = 0;
 
    } else {
        fwrite(&informacion, sizeof(informacion), 1, archivo);
        insercion = 1;
 
        /* Cierra el archivo */
        fclose(archivo);
    }
 
    return insercion;
}

/* ELiminaci�n l�gica de un registro */
char eliminarInformacion(int codigoInformacion)
{
    FILE *archivo;
    FILE *auxiliar;
    Informacion informacion;
    char elimina;
 
    /* Abre el archivo para leer */
    archivo = fopen("Informacion.dat", "r+b");    /* Modo lectura/escritura. Si el archivo no existe, es creado */
 
    if (archivo == NULL) { /* Si no se pudo abrir el archivo, el valor de archivo es NULL */
        elimina = 0;
 
    } else {
        /* Se busca el registro que se quiere borrar. Cuando se encuentra, se sit�a en esa posici�n mediante la 
        funci�n fseek y luego se modifica el campo clave de ese registro mediante alg�n valor centinela, eso se logra 
        con fwrite. Hasta all� se ha logrado una eliminaci�n L�GICA. Porque el registro sigue ocupando espacio en el archivo f�sico */
 
        elimina = 0;
        fread(&informacion, sizeof(informacion), 1, archivo);
        while (!feof(archivo)) {
            if (informacion.codigo == codigoInformacion) {
                fseek(archivo, ftell(archivo) - sizeof(informacion), SEEK_SET);
                informacion.codigo = VALOR_CENTINELA;
                fwrite(&informacion, sizeof(informacion), 1, archivo);
                elimina = 1;
                break;
            }
            fread(&informacion, sizeof(informacion), 1, archivo);
        }
 
        /* Cierra el archivo */
        fclose(archivo);
    }
 
    return elimina;
}

char eliminacionFisica()
{
    FILE *archivo;
    FILE *temporal;
    Informacion informacion;
    char elimina = 0;
 
    archivo = fopen("Informacion.dat", "rb");
    temporal = fopen("temporal.dat", "wb");
 
    if (archivo == NULL || temporal == NULL) {
        elimina = 0;
    } else {
        /* Se copia en el archivo temporal los registros v�lidos */
        fread(&informacion, sizeof(informacion), 1, archivo);
        while (!feof(archivo)) {
            if (informacion.codigo != VALOR_CENTINELA) {
                fwrite(&informacion, sizeof(informacion), 1, temporal);
            }
            fread(&informacion, sizeof(informacion), 1, archivo);
        }
        /* Se cierran los archivos antes de borrar y renombrar */
        fclose(archivo);
        fclose(temporal);
 
        remove("Informacion.dat");
        rename("temporal.dat", "Informacion.dat");
 
        elimina = 1;
    }
 
    return elimina;
}

char modificarInformacion(Informacion informacion)
{
    FILE *archivo;
    char modifica;
    Informacion informacion2;
 
    /* Abre el archivo para lectura/escritura */
    archivo = fopen("Informacion.dat", "rb+");
 
    if (archivo == NULL) { /* Si no se pudo abrir el archivo, el valor de archivo es NULL */
        modifica = 0;
 
    } else {
        modifica = 0;
        fread(&informacion2, sizeof(informacion2), 1, archivo);
        while (!feof(archivo)) {
            if (informacion2.codigo == informacion.codigo) {
                fseek(archivo, ftell(archivo) - sizeof(informacion), SEEK_SET);
                fwrite(&informacion, sizeof(informacion), 1, archivo);
                modifica = 1;
                break;
            }
            fread(&informacion2, sizeof(informacion2), 1, archivo);
        }
 
        fclose(archivo);
    }
 
    /* Cierra el archivo */
    return modifica;
}

char guardarReporte()
{
    FILE *archivo;
    char guardado;
    Informacion *informaciones;
    int numeroInformaciones;
    int i;
 
    informaciones = obtenerInformaciones(&numeroInformaciones); /* Retorna un vector din�mico de registros */
 
    if (numeroInformaciones == 0) {
        guardado = 0;
 
    } else {
        /* Abre el archivo en modo texto para escritura */
        archivo = fopen("reporte.txt", "w");
 
        if (archivo == NULL) { /* Si no se pudo abrir el archivo, el valor de archivo es NULL */
            guardado = 0;
 
        } else {
            fprintf(archivo, "\n\t\t    ==> LISTADO DE PRODUCTOS REGISTRADOS <==\n");
            fprintf(archivo, " ------------------------------------------------------------------------------\n");
            fprintf(archivo, "%8s\t%-20s%15s%15s\n", "FECHA O NUMERO", "NOMBRE DEL REGISTRO", "DESCRIPCION", "ARCHIVO");
            fprintf(archivo, " ------------------------------------------------------------------------------\n");
 
            /* Se recorre el vector din�mico de registros */
            for (i = 0; i < numeroInformaciones; i++) {
                if (informaciones[i].codigo != VALOR_CENTINELA) {
                    fprintf(archivo, "%7s \t%-20.20s%15s%15s\n", informaciones[i].codigo, informaciones[i].nombre, informaciones[i].descripcion, informaciones[i].archivo);
                }
            }
            
            guardado = 1;
 
            /* Cierra el archivo */
            fclose(archivo);
        }
    }
 
    return guardado;
}

int leecad(char *cad, int n)
{
    int i, c;
 
    /* Hay que verificar si el buffer est� limpio o si hay un '\n'
      dejado por scanf y, en ese caso, limpiarlo:
    */
 
    /* 1 COMPROBACI�N DE DATOS INICIALES EN EL BUFFER */
 
    /* Empezamos leyendo el primer caracter que haya en la entrada. Si es
      EOF, significa que no hay nada por leer, as� que cerramos la cadena,
      dej�ndola "vac�a" y salimos de la funci�n retornando un valor de 0
      o falso, para indicar que hubo un error */
    c = getchar();
    if (c == EOF) {
        cad[0] = '\0';
        return 0;
    }
 
    /* Si el valor le�do es '\n', significa que hab�a un caracter de nueva l�nea
    dejado por un scanf o funci�n similar. Simplemente inicializamos i a 0,
    para indicar que los siguientes caracteres que leamos iremos asignando a
    partir del primer caracter de la cadena. */
    if (c == '\n') {
        i = 0;
    } else {
    /* Si no hab�a un '\n', significa que el caracter que le�mos es el primer
      caracter de la cadena introducida. En este caso, lo guardamos en la
      posici�n 0 de cad, e inicializamos i a 1, porque en este caso, como ya
      tenemos el primer caracter de la cadena, continuaremos agregando 
      caracteres a partir del segundo.
 
    */
        cad[0] = c;
        i = 1;
    }
 
    /* 2. LECTURA DE LA CADENA */
 
    /* El for empieza con un ; porque estamos omitiendo la inicializaci�n del contador,
    ya que fue inicializado en el punto anterior.
    Este c�digo lee un caracter a la vez,lo agrega a cad, y se repite hasta que
    se encuentre un fin de l�nea, fin de archivo, o haya le�do la cantidad m�xima
    de caracteres que se le indic�. Luego, cierra la cadena agregando un '\0'
    al final. Todo esto es muy similar a la forma en que los compiladores suelen
    implementar la funci�n fgets, s�lo que en lugar de getchar usan getc o fgetc
    */
    for (; i < n - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        cad[i] = c;
    }
    cad[i] = '\0';
 
    /*3. LIMPIEZA DEL BUFFER */
 
    /* Finalmente limpiamos el buffer si es necesario */
    if (c != '\n' && c != EOF) /* es un caracter */
        while ((c = getchar()) != '\n' && c != EOF);
 
    /* La variable c contiene el �ltimo caracter le�do. Recordemos que hab�a 3 formas
    de salir del for: que hayamos encontrando un '\n', un EOF, o que hayamos llegado
    al m�ximo de caracteres que debemos leer. Si se da cualquiera de los dos
    primeros casos, significa que le�mos todo lo que hab�a en el buffer, por lo que
    no hay nada que limpiar. En el tercer caso, el usuario escribi� m�s caracteres
    de los debidos, que a�n est�n en el buffer, por lo que hay que quitarlos, para
    lo cual usamos el m�todo que vimos poco m�s arriba
    */
 
    return 1;
}

void tituloPrincipal()
{
    int i;
    printf("\n     ======================================================================\n");
    printf("\t\t\t     PROYECTO FINAL\n");
    printf("\t   Base de datos: Creaci�n, reportes, eliminaci�n, b�squeda y actualizaci�n\n");
    printf("\t\t    Arroyo Chavarria Jose Luis\n");
    printf("     ======================================================================\n");
 
    i = 0;
    putchar('\n');
    for (; i < 80; i++) {
        putchar('_');
    }
}
