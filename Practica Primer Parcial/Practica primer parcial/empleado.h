typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct
{
    int descripcion[31];
    int id;

}eSector;

typedef struct
{
    int descripcion[31];
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

void obtenerSector(int idSector, eSector sector[], char nombreSec[20], int cantSec);
void mostrarEmpleados(eEmpleado emp, eSector sector[], int cantEmp, int cantSec, int cantEmp);
int buscarLibre(eEmpleado emp, int cantEmp);
