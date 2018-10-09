typedef struct
{
    int CodigoJuego;
    char Descripcion[51];
    float importe;
    int estado;

}eJuegos;

void inicializarJuego( eJuegos games[], int cantidad);
int buscarEspacioLibreJuego(eJuegos games[], int cantidad);
int buscarJuegoPorCodigo(eJuegos games[], int cantidad, int auxCodGames);

void mostrarUnJuego(eJuegos games);
void mostrarTodosLosJuegos(eJuegos games[], int cantidad);
void ingresoDatosJuegos(eJuegos games[],int espacioLibre, int auxCodJuegos,char auxDescripcion[], float auxImporte);

void altaJuego(eJuegos games[], int cantidad, int auxCodJuego, char auxDescripcion[], float auxImporte);
void modificarJuego(eJuegos games[], int cantidad, int auxCodJuego, char auxDescripcion[], float auxImporte);
void bajaJuego(eJuegos games[], int cantidad, int auxCodJuego);

void ordenarPorImporteYDescripcion(eJuegos games[], int cantidad);

void adminJuegos(eJuegos games[], int cantidad);

