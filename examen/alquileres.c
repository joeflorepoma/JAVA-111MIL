#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "validaciones.h"
#include "juegos.h"
#include "clientes.h"
#include "alquileres.h"

#define CANTJUE 6
#define CANTCLI 3
#define CANTALQ 18
#define ESC 27

/** \brief Inicializa el estado en un array de gamess
 * \param games el array donde hay que buscar
 * \param cantidad la longitud del array
 * \return devuelve void
 */

void inicializarAlquiler(eAlquileres rent[], int cantidad)
{
    int i;

    for(i=0; i<cantidad; i++)
    {
        rent[i].estado = 0;
    }
}

/** \brief busca el primer lugar libre en el array
 * \param games el array donde se va a buscar
 * \param cantidad indica la longitud del array
 * \return  -1 si no hay espacio libre y (i) si hay la posicion del mismo
 */

int buscarEspacioLibreAlquiler(eAlquileres rent[], int cantidad)
{
    int i;
    int indice = -1;// devuelve -1 si no hay mas espaciop libre

    for(i=0; i<cantidad; i++)
    {
        if(rent[i].estado == 0)
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


int buscarAlquilerPorCodigo(eAlquileres rent[], int cantidad, int auxCodAlquiler)
{
    int i;
    int indice = -1;// el id no esta en la base de datos

    for(i=0; i<cantidad; i++)
    {
        if(rent[i].estado == 1 && rent[i].CodigoAlquiler == auxCodAlquiler)
        {
            indice = i;// se encontro el id en la base de datos
            break;
        }
    }
    return indice;
}

void mostrarUnAlquiler(eAlquileres rent)
{
    printf("\n | %13d  | %13d | %13d | %5d | %5d | %5d |\n", rent.CodigoAlquiler, rent.idCliente, rent.idJuego, rent.date.dia, rent.date.mes, rent.date.anio);
}

void mostrarTodosLosAlquileres(eAlquileres rent[], int cantidad)
{
    int i;

    system("cls");
    printf("---Lista de Alquileres---\n\n");

    printf("\n | %13s  | %13s | %13s | %5s | %5s | %5s\n", "Cod.Alquiler", "Cod.IdJuego", "Cod.IdCliente", "Dia", "Mes", "anio");

    for(i=0; i < cantidad; i++)
    {
        if(rent[i].estado != 0)
        {
            mostrarUnAlquiler(rent[i]);
        }
    }

    system("pause");
}


void ingresoDatosAlquileres(eAlquileres rent[],int espacioLibre, int auxCodAlquiler, int auxIdCliente, int auxIdJuego, int auxDia, int auxMes, int auxAnio)
{
    rent[espacioLibre].CodigoAlquiler = auxCodAlquiler;
    rent[espacioLibre].idCliente = auxIdCliente;
    rent[espacioLibre].idJuego = auxIdJuego;
    rent[espacioLibre].date.dia = auxDia;
    rent[espacioLibre].date.mes = auxMes;
    rent[espacioLibre].date.anio = auxAnio;
    rent[espacioLibre].estado = 1;
}

void altaAlquiler(eAlquileres rent[], int cantidad, int auxCodAlquiler, int auxIdCliente, int auxIdJuego, int auxDia, int auxMes, int auxAnio)
{
    int espacioLibre;
    int busqueda;

    system("cls");

    printf("\n\t-----Alta de Alquileres-----\t\n\n");


    espacioLibre = buscarEspacioLibreAlquiler(rent, cantidad);

    if(espacioLibre == -1)
    {
        printf("\nNo queda memoria libre...\n\n");
    }
    else
    {
        auxCodAlquiler = getValidInt("\nIngresa codigo de Alquiler: \n", "\nIngrese solo numeros\n\n", 1, 1000);

        busqueda = buscarAlquilerPorCodigo(rent, cantidad, auxCodAlquiler);

        if(busqueda != -1)
        {
            printf("\nEl Codigo Ingresado ya existe.\n");
            printf("\n | %6s  | %11s | %11s | %11s | %11s | %11s \n", "Cod. alquiler", "Cod.Cliente", "Cod. juego", "Dia", "Mes", "anio");
            mostrarUnAlquiler(rent[busqueda]);

        }
        else
        {
            auxIdCliente = getValidInt("Ingrese el codigo de cliente: \n", "\nIngrese solo numeros.\n", 1, 10000);
            auxIdJuego = getValidInt("Ingrese el codigo de juego; \n", "\nIngrese solo numeros.\n", 1, 10000);
            auxDia = getValidInt("Ingrese el dia: \n", "\nIngrese solo numeros.\n", 1, 31);
            auxMes = getValidInt("Ingrese el mes: \n", "\nIngrese solo numeros.\n", 1, 12);
            auxDia = getValidInt("Ingrese el anio: \n", "\nIngrese solo numeros.\n", 1, 9999);

            ingresoDatosAlquileres(rent, espacioLibre, auxCodAlquiler, auxIdCliente, auxIdJuego, auxDia, auxMes, auxAnio);
        }
    }

    system("pause");
}

void adminAlquileres(eAlquileres rent[], int cantidad)
{

    int auxCodigoAlquiler = 0;
    int auxIdCliente = 0;
    int auxIdJuego = 0;
    int auxDia = 0;
    int auxMes = 0;
    int auxAnio = 0;

    char opcion;

    do
    {
        system("cls");
        printf("\n-------\tABM ALQUILERES\t-------\n");
        printf("\n1.- Alta: \n2.- Modificacion : \n3.- Baja : \n4.- Listar: \nESC.- Para salir...\n\n");

        opcion = getch();

        switch(opcion)
        {
        case '1':
            altaAlquiler(rent, cantidad, auxCodigoAlquiler,auxIdCliente,auxIdJuego,auxDia,auxMes,auxAnio);

            break;
        case '2':

            break;
        case '3':

            break;
        case '4':
            mostrarTodosLosAlquileres(rent, cantidad);
            break;
        case ESC:
            system("cls");
            break;
        default:
            system("cls");
            printf("\n\nOpcion no encontrada, ingrese una opcion valida...\n");
            system("pause");
            break;
        }

    }
    while(opcion != ESC);
}

void totalPromedio(eJuegos games[], int cantJuegos, eAlquileres rent[], int cantAlquileres)
{
    int i;
    int auxIdGames;
    int contador=0;
    int contadorJuegos=0;
    float promedio=0;
    float totalImporte = 0;

    for(i=0; i<cantAlquileres; i++)
    {
        if(rent[i].estado != 0)
        {
            auxIdGames = buscarJuegoPorCodigo(games, cantJuegos, rent[i].idJuego);

            if(auxIdGames != -1)
            {
                //printf("%.2f\n", games[auxIdGames].importe);
                totalImporte += games[auxIdGames].importe;
                contador++;
            }

        }
    }
    printf("El importe total de los juegos alquilados es: %.2f\n", totalImporte);
    promedio = totalImporte/contador;
    printf("El promedio total de los juegos es: %.2f\n", promedio);

    for(i=0; i<cantJuegos; i++)
    {
        if(games[i].estado != 0)
        {
            if(games[i].importe < promedio)
            {
                contadorJuegos++;
            }
        }
    }

    printf("La cantidad de juegos por debajo del promedio son: %d\n", contadorJuegos);
}

void mostrarClientesYJuegos(eClientes client[], int cantClientes, eAlquileres rent[], int cantAlquileres)
{
    int i;
    int auxIdCliente;
    char auxCliente[51];

    printf("\n---LISTA DE CLIENTES Y JUEGOS---\n");
    printf("\n%10s | %10s | %5s\n", "Id.Cliente", "apellido", "Cod.Juego");

    for(i=0; i<cantAlquileres; i++)
    {
        if(rent[i].estado != 0)
        {
            auxIdCliente = buscarClientePorCodigo(client, cantClientes, rent[i].idCliente);

            if(auxIdCliente != -1)
            {
                //printf("%d\n", auxIdCliente);
                strcpy(auxCliente, client[auxIdCliente].Apellido);

            }else
            {
                sprintf(auxCliente, "? (Id:%d)", rent[i].idCliente);

            }

            printf("%10d | %10s | %5d\n", rent[i].idCliente, auxCliente, rent[i].idJuego);

        }
    }
}

void mostrarLosJuegosImporte(eJuegos games[], int cantidad)
{
    int i;


    printf("\n---Lista de Juegos Ordenado Por Importe---\n\n");

    printf("\n | %6s  | %18s | %6s |\n", "Cod. juego", "Descripcion", "Importe");

    for(i=0; i < cantidad; i++)
    {
        if(games[i].estado != 0)
        {
            mostrarUnJuego(games[i]);
        }
    }


}

void ordenarPorImporte(eJuegos games[], int cantJuegos)
{
    int i, j;
    eJuegos auxiliar;

    for(i=0; i<cantJuegos-1; i++)
    {
        if(games[i].estado == 0)
        {
            continue;
        }
        for(j=i+1; j<cantJuegos; j++)
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

        }
    }

}

void juegosMenos(eAlquileres rent[], int cantAlquiler)
{
    int i;
    int j;
    //int auxJuegos;
    int contador=0;

    for(i=0; i<cantAlquiler-1; i++)
    {
        if(rent[i].estado == 0)
        {
            continue;
        }

        for(j=i+1; j<cantAlquiler; j++)
        {
            if(rent[i].estado == 0)
            {
                continue;
            }

            if(rent[i].idJuego == rent[j].idCliente)
            {
                contador++;
            }
        }

    }

    printf("%d \n", contador);
}
