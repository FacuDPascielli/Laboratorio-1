#include <stdio.h>
#include <stdlib.h>

int main()
{
    int hora;

    printf("Ingrese una hora\n");
    scanf("%d", &hora);

    switch(hora)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        printf("A dormir\n");
        break;
    case 7:
    case 8:
        printf("Buenos dias \n");
        break;
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
            printf("Buenas noches\n");
            break;
    default:
        printf("No es una hora valida");
    }

    return 0;
}
