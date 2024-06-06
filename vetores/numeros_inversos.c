/**
    Escreva um algoritmo que peça para usuário 10 números inteiros
    e mostre esses números em ordem inversa.
**/

#include <stdio.h>
#define maxNumeros 10

int main(){

    int numeros[maxNumeros];

    for(int i = 0; i < maxNumeros; i++){
        printf("Digite o %i numero: ", i+1);
        scanf("%i", &numeros[i]);
    }

    printf("\n\nOrdem: ");
    for(int i = 0; i < maxNumeros; i++){
        printf(" [%i] ", numeros[i]);
    }

    printf("\nOrdem inversa: ");
    for(int i = maxNumeros-1; i >= 0; i--){
        printf(" [%i] ", numeros[i]);
    }

    printf("\n\n");
    return 0;
}
