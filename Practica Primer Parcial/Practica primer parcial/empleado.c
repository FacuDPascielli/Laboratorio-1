#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"

/*int menu()
{
    int opcion;
    printf("  *** ABM Empleados ***\n\n");
    printf("1-");
    scanf("%d", &opcion);
    return opcion;
}*/
void obtenerSector(int idSector, eSector sector[], char nombreSec[20], int cantSec)
{
    for(int i = 0; i < cantSec; i++)
        {
            if(idSector == sector[i].id)
                {
                    strcpy(nombreSec, sector[i].descripcion);
                    break;
                }
        }
}

void mostrarEmpleado(eEmpleado emp, eSector sector[], int cantEmp, int cantSec)
{
    char nombreSec[20];
    obtenerSector(emp.idSector, sector, nombreSec, cantSec);
    printf("%d       %10s     %c    %.2f    %02d/%02d/%04d %s\n",emp.legajo,emp.nombre, emp.sexo, emp.salario, emp.fechaIngreso.dia, emp.fechaIngreso.mes, emp.fechaIngreso.anio, nombreSec);

}

void mostrarEmpleados(eEmpleado emp, eSector sector[], int cantEmp, int cantSec, int cantEmp)
{
    int contador = 0;
    for(int i = 0, i < cantEmp; i++)
        {
            if(emp[i].isempty == 0)
                {
                    mostrarEmpleado(emp, sector[i], cantEmp, cantSec);
                    contador++;
                }
            if(contador == 0)
                {
                    printf("No hay nada que mostrar \n");
                }

        }
}

int buscarLibre(eEmpleado emp, int cantEmp)
    {
        int indice = -1
        for(int i = 0; i < cantEmp; i++)
            {
                if(emp.isempty = 0)
                    {
                        indice = i
                    }
            }
        return indice;
    }

void altaEmpleado(eSector sector[], eEmpleado emp[], int cantEmp, int cantSec)
{
    int indice;
    int legajo;
    int esta;
    int contador = 0;

    indice = buscarLibre(emp, cantEmp);

    if(indice == -1)
        {
            printf("No hay lugar en el sistema\n");

        }else
        {
            emp[indice].legajo == contador++;

            printf("Ingrese Apellido: ");
            fflush(stdin);
            gets(emp[indice].apellido);

            printf("Ingrese Nombre: ");
            fflush(stdin);
            gets(emp[indice].nombre);

            printf("Ingrese Sexo: ");
            fflush(stdin);
            scanf("%c", &emp.sexo);
            while(emp[indice].sexo != 'f' && emp[indice].sexo != 'm')
                {   printf("Ingrese una opcion valida (m/f): ");
                    scanf("%c", &vec[indice].sexo);
                }
            printf("Ingrese Salario: ")
            scanf("%d", &emp[indice].salario);

            printf("Ingrese dia de ingreso: ");


        }
}


