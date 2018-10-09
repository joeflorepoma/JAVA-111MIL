typedef struct
{
    int CodigoCliente;
    char Apellido[51];
    char Nombre[51];
    char Domicilio[51];
    char telefono[21];
    int estado;

}eClientes;

void inicializarClientes(eClientes client[], int cantidad);
int buscarEspacioLibreCliente(eClientes client[], int cantidad);
int buscarClientePorCodigo(eClientes client[], int cantidad, int auxCodCliente);

void mostrarUnCliente(eClientes client);
void mostrarTodosLosClientes(eClientes client[], int cantidad);
void ingresoDatosClientes(eClientes client[],int espacioLibre, int auxCodCliente,char auxNombre[], char auxApellido[], char auxDomicilio[], char auxTelefono[]);

void altaCliente(eClientes client[], int cantidad, int auxCodCliente, char auxNombre[], char auxApellido[], char auxDomicilio[], char auxTelefono[]);
void modificarCliente(eClientes client[], int cantidad, int auxCodCliente, char auxNombre[], char auxApellido[], char auxDomicilio[], char auxTelefono[]);
void bajaCliente(eClientes client[], int cantidad, int auxCodCliente);

void ordenarPorApellidoNombre(eClientes client[], int cantidad);

void adminClientes(eClientes client[], int cantidad);
