typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct
{
    int id;
    char descripcion[31];

}eSector;

typedef struct
{
    char descripcion[31];
    int id;

}menu;

typedef struct
{
    int id;
    eFecha fecha;

}eAlmuerzo;

typedef struct
{
    int legajo;
    char nombre[31];
    char apellido[31];
    char sexo;
    eFecha fechaIngreso;
    int salario;
    int idSector;
    int isempty;

}eEmpleado;

void inicializarEmpleados(eEmpleado emp[], int cantEmp);
int menuAbm();
void obtenerSector(int idSector, eSector sector[], char nombreSec[20], int cantSec);
void mostrarEmpleado(eEmpleado emp, eSector sector[], int cantSec);
void mostrarEmpleados(eEmpleado emp[], eSector sector[], int cantEmp, int cantSec);
int buscarLibre(eEmpleado emp[], int cantEmp);
void altaEmpleado(eSector sector[], eEmpleado emp[], int cantEmp, int cantSec);
int buscarEmpleado(eEmpleado vec[], int tam, int legajo);
void modificarEmpleado(eEmpleado emp[], int cantEmp, eSector sector[], int cantSec);


