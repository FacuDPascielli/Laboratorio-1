#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "empleado.h"
#define CANT_EMP 3
#define CANT_SEC 5

int main()
{
    char seguir = 's';
    char confirma;
    eEmpleado lista[CANT_EMP];
    eSector sectores[CANT_SEC]= {{1,"Sistemas"}, {2,"Planta"}, {3,"Administracion"}, {4,"R.R.H.H"}, {5,"Logistica"}};
    inicializarEmpleados(lista, CANT_EMP);

    do
    {
        switch(menuAbm())
        {

            case 1:
                altaEmpleado(sectores, lista, CANT_EMP, CANT_SEC);
                system("pause");
                break;

            case 2:
                modificarEmpleado(lista, CANT_EMP, sectores, CANT_SEC);

                break;
    /*
            case 3:

                break;

            case 4:

                break;

            case 5:

                break;

            case 6:

                break;

            case 7:

                break;
    */
            case 8:
                printf("\nConfirma salida s/n?: ");
                fflush(stdin);
                confirma = getche();

                if( tolower(confirma) == 's')
                {
                    seguir = 'n';
                }
                break;

            default:
                printf("\n Opcion invalida\n\n");
                system("break");
        }
    }while(seguir == 's');

    return 0;
}
