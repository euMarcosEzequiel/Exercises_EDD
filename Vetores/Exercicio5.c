#include <stdio.h>
#define maxElementos 10

main(){
    int numeros[maxElementos];

    for(int i = 0; i < maxElementos; i++){
        printf("Digite o %i numero: ", i+1);
        scanf("%i", &numeros[i]);
    }

    int soma = 0, maior = numeros[0], menor = numeros[0];

    for(int i = 0; i < maxElementos; i++){
        soma += numeros[i];

        if(numeros[i] > maior){
            maior = numeros[i];
        }

        if(numeros[i] < menor){
            menor = numeros[i];
        }
    }

    printf("\n\nSoma: %i", soma);
    printf("\nMaior: %i", maior);
    printf("\nMenor: %i", menor);
    printf("\n");
}
