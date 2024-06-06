/**
    Escreva um algoritmo para auxiliar o professor no cálculo da média aritmética dos alunos,
    o algoritmo deve solicitar primeiramente a quantidade de alunos, seus nomes e duas notas.
*/

#include <stdio.h>

struct aluno{
    char nome[100];
    float nota1;
    float nota2;
};

int main(){

    int qtdAlunos;

    printf("Digite a quantidade de alunos: ");
    scanf("%i", &qtdAlunos);

    struct aluno alunos[qtdAlunos];

    for(int i = 0; i < qtdAlunos; i++){
        struct aluno novoAluno;
        printf("\nDigite o nome do %i aluno: ", i+1);
        scanf("%s", &novoAluno.nome);
        printf("Digite a 1 nota do(a) %s: ", novoAluno.nome);
        scanf("%f", &novoAluno.nota1);
        printf("Digite a 2 nota do(a) %s: ", novoAluno.nome);
        scanf("%f", &novoAluno.nota2);

        alunos[i] = novoAluno;
    }

    printf("\n\n=== Resumo ===");
    for(int i = 0; i < qtdAlunos; i++){
        struct aluno aluno;
        aluno = alunos[i];
        printf("\n\nNome: %s", aluno.nome);
        printf("\nNota 1: %.2f", aluno.nota1);
        printf("\nNota 2: %.2f", aluno.nota2);
        printf("\nMedia: %.2f", (aluno.nota1 + aluno.nota2)/2);
    }

    printf("\n\n");
    return 0;
}
