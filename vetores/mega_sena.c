#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int numeros_mega[5];
    int numeros_user[5];
    int pontos = 0;

    srand(time(NULL));

    for (int i = 0; i < 5; i++) {
        numeros_mega[i] = (rand() % 15) + 1;
    }

    printf("Escolha 5 numeros entre 1 e 15: ");
    for (int i = 0; i < 5; i++){
        printf("\n %i numero: ", i+1);
        scanf("%i", &numeros_user[i]);
    }

    for(int i = 0; i < 5; i++){
        if(numeros_user[i] == numeros_mega[i]){
            pontos++;
        }
    }

    printf("\n\nNumeros sorteados: ");
    for (int i = 0; i < 5; i++) {
        printf(" [ %d ] ", numeros_mega[i]);
    }

    printf("\n\nNumeros escolhidos: ");
    for (int i = 0; i < 5; i++) {
        printf(" [ %d ] ", numeros_user[i]);
    }

    printf("\n\nAcertos: %i", pontos);

    printf("\n\n");
    return 0;
}

