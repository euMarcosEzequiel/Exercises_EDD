#include <stdio.h>

main(){

    int numeros[] = {12, 45, 39, 49, 34, 56};

    for(int i = 0; i < sizeof(numeros)/sizeof(numeros[0]); i++){
        printf("\nPosicao %i: %i",i, numeros[i]);
    }
    printf("\n");
}
