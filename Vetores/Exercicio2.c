#include <stdio.h>

main(){

    int numeros[] = {12, 45, 39, 49, 34, 56};
    int maxElementos = sizeof(numeros) / sizeof(numeros[0]);

    printf("Quantidade maxima de elementos: %i", maxElementos);
    printf("\n");
}
