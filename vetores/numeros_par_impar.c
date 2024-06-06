/**
    Escreva um algoritmo que solicite 10 números ao usuário e ao final mostre os números pares e ímpares.
*/

#include <stdio.h>
#define maxNumeros 10

int main(){

    int numeros[maxNumeros];

    for(int i = 0; i < maxNumeros; i++){
        printf("Digite o %i numero: ", i+1);
        scanf("%i", &numeros[i]);
    }

    printf("\n\n\Numeros: ");
    for(int i = 0; i < maxNumeros; i++){
        printf(" [%i] ", numeros[i]);;
    }

    printf("\nPares: ");
    for(int i = 0; i < maxNumeros; i++){
        if(numeros[i] % 2 == 0){
            printf(" [%i] ", numeros[i]);
        }
    }

    printf("\nImpares: ");
    for(int i = 0; i < maxNumeros; i++){
        if(numeros[i] % 2 == 1){
            printf(" [%i] ", numeros[i]);
        }
    }

    printf("\n\n");
    return 0;
}
