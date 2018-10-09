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

int main()
{
    eJuegos juegos[CANTJUE] = {{1,"evil",123.123,1},
                                {2,"zelda",32.13,1},
                                {3,"pacman",11.32,1},
                                {4,"tetris",13.23,1},
                                {5,"caballeros", 154.33,1},
                                {6,"street",10.23,1},};
    //inicializarJuego(juegos, CANTJUE);

    eClientes clientes[CANTCLI] = {{1,"flores","joseph","alberti 965","1123948998",1},
                                    {2,"bodoque","benito","alberto 743","1123324334",1},
                                    {3, "poma","elizabeth","maipu 132","1143345445",1},};
    //inicializarClientes(clientes, CANTCLI);

    eAlquileres renta[CANTALQ];
    inicializarAlquiler(renta, CANTALQ);
    // espacio libre alquiler cliente juego dia mes año
    ingresoDatosAlquileres(renta, 0, 11, 3, 1, 11, 9, 1999);
    ingresoDatosAlquileres(renta, 1, 22, 3, 2, 15, 9, 1999);
    ingresoDatosAlquileres(renta, 2, 33, 3, 5, 10, 9, 2001);
    ingresoDatosAlquileres(renta, 3, 44, 3, 6, 9, 3, 2002);
    ingresoDatosAlquileres(renta, 4, 55, 1, 1, 29, 1, 1999);
    ingresoDatosAlquileres(renta, 5, 66, 2, 2, 18, 2, 1999);
    ingresoDatosAlquileres(renta, 6, 77, 2, 3, 11, 7, 1997);
    ingresoDatosAlquileres(renta, 7, 88, 3, 5, 26, 3, 2001);
    ingresoDatosAlquileres(renta, 8, 99, 1, 5, 11, 6, 2002);

    char opcion;

    do
    {
        system("cls");
        printf("\n------------  MENU PRINCIPAL ------------");
        printf("\n1 - ABM JUEGOS \n2 - ABM CLIENTES \n3 - ABM ALQUILERES \n4 - RESULTADOS \nESC - SALIR\n\n\n");
        opcion = getch();

        switch(opcion)
        {
        case '1':
            system("cls");
            adminJuegos(juegos, CANTJUE);
            break;
        case '2':
            system("cls");
            adminClientes(clientes, CANTCLI);
            break;
        case '3':
            system("cls");
            adminAlquileres(renta, CANTALQ);
            break;
        case '4':
            system("cls");
            totalPromedio(juegos, CANTJUE, renta, CANTALQ);
            mostrarClientesYJuegos(clientes, CANTCLI, renta, CANTALQ);
            ordenarPorImporte(juegos, CANTJUE);
            mostrarLosJuegosImporte(juegos, CANTJUE);
            juegosMenos(renta, CANTALQ);
            system("pause");
            break;
        case ESC:
            system("cls");
            printf("\n\nPrograma finalizado.\n");
            system("pause");
            break;
        default:
            system("cls");
            printf("\n\nOpcion no encontrada, ingrese una opcion valida...\n");
            system("pause");
            break;
        }

    }
    while(opcion != ESC);

    return 0;
}
