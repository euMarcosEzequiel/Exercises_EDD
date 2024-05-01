#include <stdio.h>
#include <stdlib.h>
#define maxAlunos 7

struct Aluno{
    char nome[100];
    float nota1;
    float nota2;
};

void imprimir(struct Aluno aluno){
    float media = (aluno.nota1 + aluno.nota2) / 2;
    printf("\n===================");
    printf("\nNome: %s", aluno.nome);
    printf("\nNota 1: %.2f", aluno.nota1);
    printf("\nNota 2: %.2f", aluno.nota2);
    printf("\nMedia: %.2f", media);
    if(media >= 6){
        printf("\nSituacao: APROVADO");
    }
    else{
        printf("\nSituacao: REPROVADO");
    }
}

main(){

    struct Aluno alunos[maxAlunos];
    struct Aluno novoAluno;

    for(int i = 0; i < maxAlunos; i++){
        system("cls");
        printf("Digite o nome do %i aluno(a): ", i+1);
        scanf("%s", &novoAluno.nome);
        do{
            printf("Digite a nota 1: ");
            scanf("%f", &novoAluno.nota1);
            if(novoAluno.nota1 < 0 || novoAluno.nota1 > 10){
                printf("Nota invalida! (Somente notas de 0 a 10)\n");
            }
        }while(novoAluno.nota1 < 0 || novoAluno.nota1 > 10);

        do{
            printf("Digite a nota 2: ");
            scanf("%f", &novoAluno.nota2);
            if(novoAluno.nota2 < 0 || novoAluno.nota2 > 10){
                printf("Nota invalida! (Somente notas de 0 a 10)\n");
            }
        }while(novoAluno.nota2 < 0 || novoAluno.nota2 > 10);

        alunos[i] = novoAluno;
    }

    for(int i = 0; i < maxAlunos; i++){
        imprimir(alunos[i]);
        printf("\n");
    }

    printf("\n\n");
}
