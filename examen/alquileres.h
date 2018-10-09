typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int CodigoAlquiler;
    int idJuego;
    int idCliente;
    eFecha date;
    int estado;
}eAlquileres;

void inicializarAlquiler(eAlquileres rent[], int cantidad);
int buscarEspacioLibreAlquiler(eAlquileres rent[], int cantidad);
int buscarAlquilerPorCodigo(eAlquileres rent[], int cantidad, int auxCodAlquiler);

void mostrarUnAlquiler(eAlquileres rent);
void ingresoDatosAlquileres(eAlquileres rent[],int espacioLibre, int auxCodAlquiler, int auxCodCliente, int auxCodJuego, int auxDia, int auxMes, int auxAnio);
void mostrarTodosLosAlquileres(eAlquileres rent[], int cantidad);

void altaAlquiler(eAlquileres rent[], int cantidad, int auxCodAlquiler, int auxIdCliente, int auxIdJuego, int auxDia, int auxMes, int auxAnio);

void adminAlquileres(eAlquileres rent[], int cantidad);

void totalPromedio(eJuegos games[], int cantJuegos, eAlquileres rent[], int cantAlquileres);
void mostrarClientesYJuegos(eClientes client[], int cantClientes, eAlquileres rent[], int canAlquileres);
void mostrarLosJuegosImporte(eJuegos games[], int cantidad);
void ordenarPorImporte(eJuegos games[], int cantJuegos);
void juegosMenos(eAlquileres rent[], int cantAlquiler);
