/**
    Escreva um algoritmo que peça para o usuário 5 valores decimais, posteriormente mais 5.
    Ao final faça a soma desses valor conforme sua ordem
*/

#include <stdio.h>
#define maxNumeros 5

int main(){

    float numeros1[maxNumeros];
    float numeros2[maxNumeros];

    for(int i = 0; i < maxNumeros; i++){
        printf("Digite o %i numero: ", i+1);
        scanf("%f", &numeros1[i]);
    }

    printf("\n\n");
    for(int i = 0; i < maxNumeros; i++){
        printf("Digite o %i numero: ", i+1);
        scanf("%f", &numeros2[i]);
    }

    printf("\n\n");
    for(int i = 0; i < maxNumeros; i++){
        printf("\n%.3f + %.3f = %.3f", numeros1[i], numeros2[i], numeros1[i] + numeros2[i]);
    }

    printf("\n\n");
    return 0;
}
