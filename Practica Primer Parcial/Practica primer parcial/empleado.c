#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include <conio.h>
#include <ctype.h>

void inicializarEmpleados(eEmpleado emp[], int cantEmp)
{
    for(int i = 0; i < cantEmp; i++)
        {
            emp[i].isempty = 1;
        }
}
int menuAbm()
{
    int opcion;
    printf("  *** ABM Empleados ***\n\n");
    printf("1- Alta empleados\n");
    printf("2- Modificar Empleados\n");
    scanf("%d", &opcion);
    return opcion;
}
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

void mostrarEmpleado(eEmpleado emp, eSector sector[], int cantSec)
{
    char nombreSec[20];
    obtenerSector(emp.idSector, sector, nombreSec, cantSec);
    printf("%d       %10s     %c    %.2f    %02d/%02d/%04d %s\n",emp.legajo,emp.nombre, emp.sexo, emp.salario, emp.fechaIngreso.dia, emp.fechaIngreso.mes, emp.fechaIngreso.anio, nombreSec);

}

void mostrarEmpleados(eEmpleado emp[], eSector sector[], int cantEmp, int cantSec)
{
    int contador = 0;
    for(int i = 0; i < cantEmp; i++)
        {
            if(emp[i].isempty == 0)
                {
                    mostrarEmpleado(emp[i], sector, cantSec);
                    contador++;
                }
            if(contador == 0)
                {
                    printf("No hay nada que mostrar \n");
                }

        }
}

int buscarLibre(eEmpleado emp[], int cantEmp)
    {
        int indice = -1;
        for(int i = 0; i < cantEmp; i++)
            {
                if(emp[i].isempty == 1)
                    {
                        indice = i;
                    }
            }


        return indice;
    }

void altaEmpleado(eSector sector[], eEmpleado emp[], int cantEmp, int cantSec)
{
    int indice;
    int contador = 0;

    indice = buscarLibre(emp, cantEmp);

    if(indice == -1)
        {
            printf("No hay lugar en el sistema\n");

        }else
        {
            emp[indice].legajo = contador++;

            printf("Ingrese Apellido: ");
            fflush(stdin);
            gets(emp[indice].apellido);

            printf("Ingrese Nombre: ");
            fflush(stdin);
            gets(emp[indice].nombre);

            printf("Ingrese Sexo: ");
            fflush(stdin);
            scanf("%c", &emp[indice].sexo);
            while(emp[indice].sexo != 'f' && emp[indice].sexo != 'm')
                {   printf("Ingrese una opcion valida (m/f): ");
                    scanf("%c", &emp[indice].sexo);
                }
            printf("Ingrese Salario: ");
            scanf("%d", &emp[indice].salario);

            printf("Ingrese dia de ingreso(Enntre 1 y 31): ");
            scanf("%d", &emp[indice].fechaIngreso.dia);
                while(emp[indice].fechaIngreso.dia < 1 || emp[indice].fechaIngreso.dia >31)
                    {   printf("Ingrese una opcion valida (Entre 1 y 31): ");
                        scanf("%d", &emp[indice].fechaIngreso.dia);
                    }


            printf("Ingrese mes de ingreso(Entre 1 y 12): ");
            scanf("%d", &emp[indice].fechaIngreso.mes);
                while(emp[indice].fechaIngreso.mes < 1 || emp[indice].fechaIngreso.mes >12)
                    {
                        printf("Ingrese una opcion valida (Entre 1 y 12): ");
                        scanf("%d", &emp[indice].fechaIngreso.mes);
                    }


            printf("Ingrese anio de ingreso(Entre 1900 y 2019): ");
            scanf("%d", &emp[indice].fechaIngreso.anio);
                while(emp[indice].fechaIngreso.anio < 1900 || emp[indice].fechaIngreso.anio > 2019)
                    {
                        printf("Ingrese una opcion valida (Entre 1900 y 2019)");
                        scanf("%d", &emp[indice].fechaIngreso.anio);
                    }

            printf("Ingrese el id del sector: ");
            scanf("%d", &emp[indice].idSector);

            emp[indice].isempty = 0;

            printf("Alta exitosa!!!\n");

        }
}

int buscarEmpleado(eEmpleado emp[], int tam, int legajo)
    {

        int indice = -1;

         for(int i=0; i < tam; i++)
        {
            if(emp[i].isempty == 0 && emp[i].legajo == legajo){
                indice = i;
                break;
            }
        }

        return indice;
    }

void modificarEmpleado(eEmpleado emp[], int cantEmp, eSector sector[], int cantSec)
{
    char confirma;
    char seguir = 's';
    int opcion;
    int indice;
    char confirma1;
    int legajo;



        printf("Ingrese el legajo del empleado a modificar: ");
        scanf("%d", &legajo);

        indice = buscarEmpleado(emp, cantEmp, legajo);


    if(indice != -1)
        {


        while(confirma != 'n' && confirma != 's')
            {
                mostrarEmpleado(emp[indice], sector, cantSec);
                printf("\nEste es el empleado?  s/n\n");
                scanf("%c", &confirma);
            }

        if(tolower(confirma) == 's')
            {
            printf("Que desea modificar?\n");
            printf("1- Modificar Nombre.\n");
            printf("2- Modificar Apellido.\n");
            printf("3- Modificar Sexo.\n");
            printf("4- Modificar Salario.\n");
            printf("5- Modificar fecha de ingreso.\n");
            printf("6- Modificar el id del sector");
            printf("7- Salir");
            scanf("%d", &opcion);

            do{
                switch(opcion)
                {


                            case 1:


                                                printf("Su nombre actual es %s", emp[indice].nombre);
                                                printf("Ingrese su nuevo nombre: ");
                                                gets(emp[indice].nombre);
                                                printf("Su nuevo nombre es %s", emp[indice].nombre);
                                                printf("Confirma la modificacion del nombre? s/n");
                                                scanf("%c", &confirma1);
                                                while(confirma1 != 'n' && confirma1 != 's')
                                                    {
                                                        printf("Ingrese opcion valida, confirma la modificacion de nombre? s/n");
                                                        scanf("%c", &confirma1);
                                                    }

                                        break;

                            case 2:
                                            printf("Su apellido actual es %s", emp[indice].apellido);
                                    do
                                        {
                                            printf("Ingrese su nuevo apellido: ");
                                            gets(emp[indice].apellido);
                                            printf("Su nuevo apellido es %s", emp[indice].apellido);
                                            printf("Confirma la modificacion del apellido? s/n");
                                            scanf("%c", &confirma1);
                                            while(confirma1 != 'n' && confirma1 != 's')
                                                {
                                                    printf("Ingrese opcion valida, confirma la modificacion de apellido? s/n");
                                                    scanf("%c", &confirma1);
                                                }

                                        }while(confirma1 == 's');

                                        break;
                            case 3:
                                            printf("Su sexo actual es %c", emp[indice].sexo);
                                    do
                                        {
                                            printf("Ingrese su nuevo sexo: ");
                                            scanf("%c", &emp[indice].sexo);
                                            printf("Su nuevo sexo es %c", emp[indice].sexo);
                                            printf("Confirma la modificacion del sexo? s/n");
                                            scanf("%c", &confirma1);
                                            while(confirma1 != 'n' && confirma1 != 's')
                                                {
                                                    printf("Ingrese opcion valida, confirma la modificacion del sexo? s/n");
                                                    scanf("%c", &confirma1);
                                                }

                                        }while(confirma1 == 's');

                                        break;
                            case 4:
                                            printf("Su salario actual es %d", emp[indice].salario);
                                    do
                                        {
                                            printf("Ingrese su nuevo salario: ");
                                            scanf("%d", &emp[indice].salario);
                                            printf("Su nuevo salario es %d", emp[indice].salario);
                                            printf("Confirma la modificacion del salario? s/n");
                                            scanf("%c", &confirma1);
                                            while(confirma1 != 'n' && confirma1 != 's')
                                                {
                                                    printf("Ingrese opcion valida, confirma la modificacion de salario? s/n");
                                                    scanf("%c", &confirma1);
                                                }

                                        }while(confirma1 == 's');

                                        break;
                            case 5:
                                            printf("Su fecha de ingreso actual es %02d/%02d/%04d", emp[indice].fechaIngreso.dia, emp[indice].fechaIngreso.mes, emp[indice].fechaIngreso.anio);
                                    do
                                        {
                                            printf("Ingrese su nueva fecha de ingreso: \n");
                                            printf("Dia: ");
                                            scanf("%d", &emp[indice].fechaIngreso.dia);
                                            printf("Mes: ");
                                            scanf("%d", &emp[indice].fechaIngreso.mes);
                                            printf("Anio: ");
                                            scanf("%d", &emp[indice].fechaIngreso.anio);
                                            printf("Su nueva fecha de ingreso es %02d/%02d/%04d", emp[indice].fechaIngreso.dia, emp[indice].fechaIngreso.mes, emp[indice].fechaIngreso.anio);
                                            printf("Confirma la modificacion del ingreso? s/n");
                                            scanf("%c", &confirma1);
                                            while(confirma1 != 'n' && confirma1 != 's')
                                                {
                                                    printf("Ingrese opcion valida, confirma la modificacion de ingreso? s/n");
                                                    scanf("%c", &confirma1);
                                                }

                                        }while(confirma1 == 's');

                                        break;
                            case 6:
                                            printf("Su sector actual es %d", emp[indice].idSector);
                                    do
                                        {
                                            printf("Ingrese el nuevo id de su sector: ");
                                            scanf("%d", &emp[indice].idSector);
                                            printf("El id de su nuevo sector es %d", emp[indice].idSector);
                                            printf("Confirma la modificacion del sector? s/n");
                                            scanf("%c", &confirma1);
                                            while(confirma1 != 'n' && confirma1 != 's')
                                                {
                                                    printf("Ingrese opcion valida, confirma la modificacion de sector? s/n");
                                                    scanf("%c", &confirma1);
                                                }

                                        }while(confirma1 == 's');
                                        break;
                            case 7:
                                            printf("\nConfirma salida s/n?: ");
                                            fflush(stdin);
                                            confirma = getche();

                                            if( tolower(confirma) == 's')
                                            {
                                                seguir = 'n';
                                            }
                                        break;
                            default:
                                            printf("Opcion invalida\n");
                                            system("break");

                }
            }while(seguir == 's');
        }



        }else
            {
                printf("No se encontro a nadie con ese legajo\n");
            }

}




