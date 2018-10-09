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

void inicializarClientes(eClientes client[], int cantidad)
{
    int i;

    for(i=0; i<cantidad; i++)
    {
        client[i].estado = 0;
    }
}

/** \brief busca el primer lugar libre en el array
 * \param games el array donde se va a buscar
 * \param cantidad indica la longitud del array
 * \return  -1 si no hay espacio libre y (i) si hay la posicion del mismo
 */

int buscarEspacioLibreCliente(eClientes client[], int cantidad)
{
    int i;
    int indice = -1;// devuelve -1 si no hay mas espaciop libre

    for(i=0; i<cantidad; i++)
    {
        if(client[i].estado == 0)
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


int buscarClientePorCodigo(eClientes client[], int cantidad, int auxCodCliente)
{
    int i;
    int indice = -1;// el id no esta en la base de datos

    for(i=0; i<cantidad; i++)
    {
        if(client[i].estado == 1 && client[i].CodigoCliente == auxCodCliente)
        {
            indice = i;// se encontro el id en la base de datos
            break;
        }
    }
    return indice;
}

void mostrarUnCliente(eClientes client)
{
    printf("\n | %6d  | %18s | %18s | %18s | %18s |\n", client.CodigoCliente, client.Nombre, client.Apellido, client.Domicilio, client.telefono);
}

/** \brief imprime los datos ingresados
 * \param games el array donde se buscara los datos
 * \param cantidad el numero de datos ingresados
 * \return no devuelve nada
 */

void mostrarTodosLosClientes(eClientes client[], int cantidad)
{
    int i;

    system("cls");
    printf("---Lista de Clientes---\n\n");

    printf("\n | %6s  | %18s | %18s | %18s | %18s |\n", "Cod. Cliente", "Nombre", "Apellido", "Domicilio", "Telefono");

    for(i=0; i < cantidad; i++)
    {
        if(client[i].estado != 0)
        {
            mostrarUnCliente(client[i]);
        }
    }

    system("pause");
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

void ingresoDatosClientes(eClientes client[],int espacioLibre, int auxCodCliente, char auxNombre[], char auxApellido[], char auxDomicilio[], char auxTelefono[])
{
    client[espacioLibre].CodigoCliente = auxCodCliente;
    strcpy(client[espacioLibre].Nombre,auxNombre);
    strcpy(client[espacioLibre].Apellido,auxApellido);
    strcpy(client[espacioLibre].Domicilio,auxDomicilio);
    strcpy(client[espacioLibre].telefono,auxTelefono);
    client[espacioLibre].estado = 1;
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

void altaCliente(eClientes client[], int cantidad, int auxCodCliente, char auxNombre[], char auxApellido[], char auxDomicilio[], char auxTelefono[])
{
    int espacioLibre;
    int busqueda;

    system("cls");

    printf("\n\t-----Alta de Clientes-----\t\n\n");


    espacioLibre = buscarEspacioLibreCliente(client, cantidad);

    if(espacioLibre == -1)
    {
        printf("\nNo queda memoria libre...\n\n");
    }
    else
    {
        auxCodCliente = getValidInt("\nIngresa codigo de cliente: \n", "\nIngrese solo numeros\n\n", 1, 1000);

        busqueda = buscarClientePorCodigo(client, cantidad, auxCodCliente);

        if(busqueda != -1)
        {
            printf("\nEl Codigo Ingresado ya existe.\n");
            printf("\n | %6s  | %18s | %18s | %18s | %18s |\n", "Cod. Cliente", "Nombre", "Apellido", "Domicilio", "Telefono");
            mostrarUnCliente(client[busqueda]);

        }
        else
        {
            getValidString("Ingrese nombre del cliente: \n", "\nIngrese solo caracteres.\n\n", auxNombre,2,51);
            getValidString("Ingrese el apellido del cliente: \n", "\nIngrese solo caracteres.\n\n", auxApellido,2,51);
            getValidAlfaNumerico("Ingrese el domicilio del cliente: \n", "\nsolo caracteres y numeros.\n\n", auxDomicilio);
            getString("Ingrese el telefono: \n", auxTelefono);

            ingresoDatosClientes(client, espacioLibre, auxCodCliente, auxNombre, auxApellido, auxDomicilio, auxTelefono);
        }
    }
    system("pause");
}

void modificarCliente(eClientes client[], int cantidad, int auxCodCliente, char auxNombre[], char auxApellido[], char auxDomicilio[], char auxTelefono[])
{
    int busqueda;

    system("cls");

    printf("\n\t-----Modificacion de Clientes-----\t\n\n");


    auxCodCliente = getValidInt("\nIngrese el codigo de cliente a modificar: \n", "\nIngrese solo numeros.\n\n", 1, 1000);

    busqueda = buscarClientePorCodigo(client, cantidad, auxCodCliente);

    if(busqueda == -1)
    {
        printf("\nEl Codigo del cliente no se encuentra en la base de datos.\n");
    }
    else
    {
        printf("\n | %6s  | %18s | %18s | %18s | %18s |\n", "Cod. Cliente", "Nombre", "Apellido", "Domicilio", "Telefono");
        mostrarUnCliente(client[busqueda]);

        getValidString("Re-ingrese nombre del cliente: \n", "\nIngrese solo caracteres.\n\n", auxNombre,2,52);
        getValidString("Re-ingrese el apellido del cliente: \n", "\nIngrese solo caracteres.\n\n", auxApellido,2,52);
        getValidAlfaNumerico("Re-ingrese el domicilio del cliente: \n", "\nsolo caracteres y numeros.\n\n", auxDomicilio);
        getString("Re-ingrese el telefono: \n", auxTelefono);

        ingresoDatosClientes(client, busqueda, auxCodCliente, auxNombre, auxApellido, auxDomicilio, auxTelefono);
    }

    system("pause");
}

void bajaCliente(eClientes client[], int cantidad, int auxCodCliente)
{
    int busqueda;
    char confirma;

    system("cls");

    printf("\n\t-----Baja de Cliente-----\t\n\n");

    auxCodCliente = getValidInt("\nIngrese codigo a dar de baja: \n", "Ingrese solo numeros.\n", 1, 10000);

    busqueda = buscarClientePorCodigo(client, cantidad, auxCodCliente);

    if(busqueda == -1)
    {
        printf("\n El Codigo a dar de baja no se encuentra en la base de dato.\n\n");

    }
    else
    {
        printf("\n | %6s  | %18s | %18s | %18s | %18s |\n", "Cod. Cliente", "Nombre", "Apellido", "Domicilio", "Telefono");
        mostrarUnCliente(client[busqueda]);

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
            client[busqueda].estado = 0;
            printf("\nSe ha realizado la baja\n\n");
        }
        else
        {
            printf("\nSe ha cancelado la baja\n\n");
        }
    }

    system("pause");
}

void ordenarPorApellidoNombre(eClientes client[], int cantidad)
{
    int i, j;
    eClientes auxiliar;

    for(i=0; i<cantidad-1; i++)
    {
        if(client[i].estado == 0)
        {
            continue;
        }
        for(j=i+1; j<cantidad; j++)
        {
            if(client[i].estado == 0)
            {
                continue;
            }

            if(strcmp(client[i].Apellido, client[j].Apellido)>0)
            {
                auxiliar = client[i];
                client[i] = client[j];
                client[j] = auxiliar;
            }
            else if(strcmp(client[i].Apellido, client[j].Apellido)==0 && strcmp(client[i].Nombre, client[j].Nombre)>0)
            {
                    auxiliar = client[i];
                    client[i] = client[j];
                    client[j] = auxiliar;

            }

        }
    }
}

void adminClientes(eClientes client[], int cantidad)
{

    int auxCodigoCliente = 0;
    char auxNombre[51];
    char auxApellido[51];
    char auxDireccion[51];
    char auxTelefono[21];

    char opcion;

    do
    {
        system("cls");
        printf("\n-------\tABM CLIENTES\t-------\n");
        printf("\n1.- Alta: \n2.- Modificacion : \n3.- Baja : \n4.- Listar: \nESC.- Para salir...\n\n");

        opcion = getch();

        switch(opcion)
        {
        case '1':
            altaCliente(client, cantidad, auxCodigoCliente, auxNombre, auxApellido, auxDireccion, auxTelefono);

            break;
        case '2':

            modificarCliente(client, cantidad, auxCodigoCliente, auxNombre, auxApellido, auxDireccion, auxTelefono);
            break;
        case '3':

            bajaCliente(client, cantidad, auxCodigoCliente);
            break;
        case '4':

            ordenarPorApellidoNombre(client, cantidad);
            mostrarTodosLosClientes(client, cantidad);
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

    }while(opcion != ESC);
}
