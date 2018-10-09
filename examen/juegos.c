#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#include "validaciones.h"
#include "juegos.h"
#include "clientes.h"
#include "alquileres.h"

#define ESC 27

/** \brief Inicializa el estado en un array de gamess
 * \param games el array donde hay que buscar
 * \param cantidad la longitud del array
 * \return devuelve void
 */

void inicializarJuego( eJuegos games[], int cantidad)
{
    int i;

    for(i=0; i<cantidad; i++)
    {
        games[i].estado = 0;
    }
}

/** \brief busca el primer lugar libre en el array
 * \param games el array donde se va a buscar
 * \param cantidad indica la longitud del array
 * \return  -1 si no hay espacio libre y (i) si hay la posicion del mismo
 */

int buscarEspacioLibreJuego(eJuegos games[], int cantidad)
{
    int i;
    int indice = -1;// devuelve -1 si no hay mas espaciop libre

    for(i=0; i<cantidad; i++)
    {
        if(games[i].estado == 0)
        {
            indice = i;// devolvera cualquier otro numero si encuentra un espacio libre
            break;
        }
    }
    return indice;
}

/**
 * \brief Busca la primer ocurrencia de un libro mediante su codigo
 * \param games Es el array en el cual buscar
 * \param cantidad Indica la logitud del array
 * \param codigo Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 */


int buscarJuegoPorCodigo(eJuegos games[], int cantidad, int auxCodGames)
{
    int i;
    int indice = -1;// el id no esta en la base de datos

    for(i=0; i<cantidad; i++)
    {
        if(games[i].estado == 1 && games[i].CodigoJuego == auxCodGames)
        {
            indice = i;// se encontro el id en la base de datos
            break;
        }
    }
    return indice;
}

void mostrarUnJuego(eJuegos games)
{
    printf("\n | %6d  | %18s | %6.2f |\n", games.CodigoJuego, games.Descripcion, games.importe);
}

/** \brief imprime los datos ingresados
 * \param games el array donde se buscara los datos
 * \param cantidad el numero de datos ingresados
 * \return no devuelve nada
 */

void mostrarTodosLosJuegos(eJuegos games[], int cantidad)
{
    int i;


    printf("---Lista de Juegos---\n\n");

    printf("\n | %6s  | %18s | %6s |\n", "Cod. juego", "Descripcion", "Importe");

    for(i=0; i < cantidad; i++)
    {
        if(games[i].estado != 0)
        {
            mostrarUnJuego(games[i]);
        }
    }


}

/**
 * \brief Carga los valores de los juegos
 * \param games Es el array de juegos
 * \param espacioLibre Indica la posicion a setear
 * \param auxCodJuegos es el codigo del juegos
 * \param auxDescripcion es la descriocion del juego
 * \param auximporte es el importe del juego
 * \return -
 */

void ingresoDatosJuegos(eJuegos games[],int espacioLibre, int auxCodJuegos,char auxDescripcion[], float auxImporte)
{
    games[espacioLibre].CodigoJuego = auxCodJuegos;
    strcpy(games[espacioLibre].Descripcion,auxDescripcion);
    games[espacioLibre].importe = auxImporte;
    games[espacioLibre].estado = 1;
}

/** \brief permite dar de alta a un empleado tomando datos
 * \param empleado en array donde se buscara
 * \param cantidad el numero de dato que se ingresara
 * \param identificacion el es codigo del empleado
 * \param nombre el nombre del empleado
 * \param apellido ingresara el apellido del empleado
 * \param sueldo es lo que ganara el empleado
 * \param sector el sector al cual pertenecera
 * \return no devuelve nada
 */

void altaJuego(eJuegos games[], int cantidad, int auxCodJuego, char auxDescripcion[], float auxImporte)
{
    int espacioLibre;
    int busqueda;

    system("cls");

    printf("\n\t-----Alta de Juegos-----\t\n\n");


    espacioLibre = buscarEspacioLibreJuego(games, cantidad);

    if(espacioLibre == -1)
    {
        printf("\nNo queda memoria libre...\n\n");
    }
    else
    {
        auxCodJuego = getValidInt("\nIngresa codigo de juego: \n", "\nIngrese solo numeros\n\n", 1, 1000);

        busqueda = buscarJuegoPorCodigo(games, cantidad, auxCodJuego);

        if(busqueda != -1)
        {
            printf("\nEl Codigo Ingresado ya existe.\n");
            printf("\n | %6s  | %18s | %6s |\n", "Cod. juego", "Descripcion", "Importe");
            mostrarUnJuego(games[busqueda]);

        }
        else
        {
            getValidString("Ingrese descripcion del juego: \n", "\nIngrese solo caracteres.\n\n", auxDescripcion,2,51);
            auxImporte = getValidFloat("Ingrese el importe del juego: \n", "\nIngrese numeros reales.\n\n",1.0, 10000.0);
            ingresoDatosJuegos(games, espacioLibre, auxCodJuego, auxDescripcion, auxImporte);

        }
    }
    system("pause");
}

/** \brief permite modificar a un empleado tomando datos
 * \param empleado en array donde se buscara
 * \param cantidad el numero de dato que se ingresara
 * \param identificacion el es codigo del empleado
 * \param nombre el nombre del empleado
 * \param apellido ingresara el apellido del empleado
 * \param sueldo es lo que ganara el empleado
 * \param sector el sector al cual pertenecera
 * \return no devuelve nada
 */

void modificarJuego(eJuegos games[], int cantidad, int auxCodJuego, char auxDescripcion[], float auxImporte)
{
    int busqueda;

    system("cls");

    printf("\n\t-----Modificacion de Juegos-----\t\n\n");


    auxCodJuego = getValidInt("\nIngrese el codigo de juego a modificar: \n", "\nIngrese solo numeros.\n\n", 1, 1000);

    busqueda = buscarJuegoPorCodigo(games, cantidad, auxCodJuego);

    if(busqueda == -1)
    {
        printf("\nEl Codigo del juego no se encuentra en la base de datos.\n");
    }
    else
    {
        printf("\n | %6s  | %18s | %6s |\n", "Cod. juego", "Descripcion", "Importe");
        mostrarUnJuego(games[busqueda]);

        getValidString("Re-ingrese descripcion del juego: \n", "\nIngrese solo caracteres.\n\n", auxDescripcion,2,51);
        auxImporte = getValidFloat("Re-ingrese el importe del juego: \n", "\nIngrese numeros reales.\n\n", 1.0, 10000.0);

        ingresoDatosJuegos(games, busqueda, auxCodJuego, auxDescripcion, auxImporte);
    }

    system("pause");
}

/** \brief permite dar de baja a un empleado tomando datos
 * \param empleado en array donde se buscara
 * \param cantidad el numero de dato que se ingresara
 * \param identificacion el es codigo del empleado
 * \param nombre el nombre del empleado
 * \param apellido ingresara el apellido del empleado
 * \param sueldo es lo que ganara el empleado
 * \param sector el sector al cual pertenecera
 * \return no devuelve nada
 */

void bajaJuego(eJuegos games[], int cantidad, int auxCodJuego)
{
    int busqueda;
    char confirma;

    system("cls");

    printf("\n\t-----Baja de Juegos-----\t\n\n");

    auxCodJuego = getValidInt("\nIngrese codigo a dar de baja: \n", "Ingrese solo numeros.\n", 1, 10000);

    busqueda = buscarJuegoPorCodigo(games, cantidad, auxCodJuego);

    if(busqueda == -1)
    {
        printf("\n El Codigo a dar de baja no se encuentra en la base de dato.\n\n");

    }
    else
    {
        printf("\n | %6s  | %18s | %6s |\n", "Cod. juego", "Descripcion", "Importe");
        mostrarUnJuego(games[busqueda]);

        do
        {
            printf("\n\nConfirma baja? [s|n]: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
        }
        while(confirma != 's' && confirma != 'n');

        if(confirma == 's')
        {
            games[busqueda].estado = 0;
            printf("\nSe ha realizado la baja\n\n");
        }
        else
        {
            printf("\nSe ha cancelado la baja\n\n");
        }
    }

    system("pause");
}

void ordenarPorImporteYDescripcion(eJuegos games[], int cantidad)
{
    int i, j;
    eJuegos auxiliar;

    for(i=0; i<cantidad-1; i++)
    {
        if(games[i].estado == 0)
        {
            continue;
        }
        for(j=i+1; j<cantidad; j++)
        {
            if(games[i].estado == 0)
            {
                continue;
            }

            if(games[i].importe > games[j].importe)
            {
                auxiliar = games[i];
                games[i] = games[j];
                games[j] = auxiliar;
            }
            else if(games[i].importe == games[j].importe && strcpy(games[i].Descripcion, games[j].Descripcion)>0)
            {
                    auxiliar = games[i];
                    games[i] = games[j];
                    games[j] = auxiliar;

            }

        }
    }
}

void adminJuegos(eJuegos games[], int cantidad)
{

    int auxCodigoJuego = 0;
    char auxDescripcion[51];
    float auxImporte = 0;

    char opcion;


    do
    {
        system("cls");
        printf("\n-------\tABM JUEGOS\t-------\n");
        printf("\n1.- Alta: \n2.- Modificacion : \n3.- Baja : \n4.- Listar: \nESC.- Para salir...\n\n");

        opcion = getch();

        switch(opcion)
        {
        case '1':
            altaJuego(games, cantidad, auxCodigoJuego, auxDescripcion, auxImporte);

            break;
        case '2':

            modificarJuego(games, cantidad, auxCodigoJuego, auxDescripcion, auxImporte);
            break;
        case '3':

            bajaJuego(games, cantidad, auxCodigoJuego);
            break;
        case '4':

            ordenarPorImporteYDescripcion(games, cantidad);
            mostrarTodosLosJuegos(games, cantidad);
            break;
        case ESC:
            system("cls");
            printf("\n\nPrograma finalizado.\n");
            break;
        default:
            system("cls");
            printf("\n\nOpcion no encontrada, ingrese una opcion valida...\n");
            system("pause");
            break;
        }

    }while(opcion != ESC);
}

