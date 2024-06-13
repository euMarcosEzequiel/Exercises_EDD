#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_CURSOS 6
#define MAX_REQUISITOS 50
#define MAX_ALUNOS 100

typedef struct {
    int idadeMinima;
    char requisitos[MAX_REQUISITOS][50];
} Requisitos;

typedef struct {
    char nome[50];
    char categoria[20];
    Requisitos requisitos;
    int vagasDisponiveis;
} Curso;

typedef struct {
    char nome[50];
    char rg[20];
    char endereco[100];
    int idade;
    bool possuiDiploma;
    bool possuiHistorico;
} Aluno;

bool verificaRequisitos(Aluno aluno, Requisitos requisitos) {
    if (aluno.idade < requisitos.idadeMinima)
        return false;

    for (int i = 0; i < MAX_REQUISITOS && requisitos.requisitos[i][0] != '\0'; i++) {
        char *requisito = requisitos.requisitos[i];

        if (strcmp(requisito, "conhecimento em software autocad") == 0) {
            if (aluno.idade < 18)
                return false;
        }
        else if (strcmp(requisito, "diploma ensino medio") == 0) {
            if (!aluno.possuiDiploma)
                return false;
        }
        else if (strcmp(requisito, "historico escolar") == 0) {
            if (!aluno.possuiHistorico)
                return false;
        }
    }

    return true;
}

void realizarMatricula(Curso cursos[], int numCursos, Aluno aluno, char nomeCurso[]) {
    for (int i = 0; i < numCursos; i++) {
        if (strcmp(cursos[i].nome, nomeCurso) == 0) {
            if (cursos[i].vagasDisponiveis > 0 && verificaRequisitos(aluno, cursos[i].requisitos)) {
                cursos[i].vagasDisponiveis--;
                printf("\nMatricula realizada com sucesso no curso %s!\n", cursos[i].nome);
                system("pause");
                return;
            } else {
                printf("Desculpe, nao foi possivel realizar a matricula no curso %s.\n", cursos[i].nome);
                return;
            }
        }
    }
    printf("Curso nao encontrado.\n");
}

void inicializarCursos(Curso cursos[]) {
    strcpy(cursos[0].nome, "Tecnicas de impressao 3D");
    strcpy(cursos[0].categoria, "Aperfeicoamento");
    cursos[0].requisitos.idadeMinima = 16;
    strcpy(cursos[0].requisitos.requisitos[0], "Conhecimento em software AutoCAD");
    cursos[0].vagasDisponiveis = 10;

    strcpy(cursos[1].nome, "Logica de programacao com microcontroladores");
    strcpy(cursos[1].categoria, "Aperfeicoamento");
    cursos[1].requisitos.idadeMinima = 14;
    strcpy(cursos[1].requisitos.requisitos[0], "");
    cursos[1].vagasDisponiveis = 15;

    strcpy(cursos[2].nome, "Tecnico em quimica");
    strcpy(cursos[2].categoria, "Tecnico");
    cursos[2].requisitos.idadeMinima = 16;
    strcpy(cursos[2].requisitos.requisitos[0], "");
    cursos[2].vagasDisponiveis = 20;

    strcpy(cursos[3].nome, "Tecnico em administracao");
    strcpy(cursos[3].categoria, "Tecnico");
    cursos[3].requisitos.idadeMinima = 16;
    strcpy(cursos[3].requisitos.requisitos[0], "");
    cursos[3].vagasDisponiveis = 18;

    strcpy(cursos[4].nome, "Tecnico em informatica");
    strcpy(cursos[4].categoria, "Tecnico");
    cursos[4].requisitos.idadeMinima = 16;
    strcpy(cursos[4].requisitos.requisitos[0], "");
    cursos[4].vagasDisponiveis = 25;

    strcpy(cursos[5].nome, "Engenharia mecanica");
    strcpy(cursos[5].categoria, "Graduacao");
    cursos[5].requisitos.idadeMinima = 18;
    strcpy(cursos[5].requisitos.requisitos[0], "Diploma ensino medio");
    strcpy(cursos[5].requisitos.requisitos[1], "Historico escolar");
    cursos[5].vagasDisponiveis = 30;
}

void menuCursos(){
    printf("\n\n=== Cursos disponiveis: ===");
    printf("\n\nAperfeicoamento:");
    printf("\nTecnicas de impressao 3D: (16 anos, conhecimento em software AutoCAD)");
    printf("\nLogica de programacao com microcontroladores: (14 anos, nenhum)");
    printf("\n\nTecnicos:");
    printf("\nTecnico em quimica");
    printf("\nTecnico em administracao");
    printf("\nTecnico em informatica");
    printf("\n\nGraduacao:");
    printf("\nEngenharia mecanica");
    printf("\nEngenharia florestal");
    printf("\nLicenciatura em fisica");
}

int main() {
    Curso cursos[MAX_CURSOS];
    Aluno alunos[MAX_ALUNOS];
    int numAlunos = 0;

    inicializarCursos(cursos);

    Aluno aluno;

    printf("Informe o nome do aluno: ");
    scanf("%s", aluno.nome);

    printf("Informe o RG do aluno: ");
    scanf("%s", aluno.rg);

    printf("Informe o endereco do aluno: ");
    scanf(" %[^\n]s", aluno.endereco);

    printf("Informe a idade do aluno: ");
    scanf("%d", &aluno.idade);

    printf("O aluno possui diploma de ensino medio (1 - Sim, 0 - Nao)? ");
    scanf("%d", &aluno.possuiDiploma);

    printf("O aluno possui historico escolar (1 - Sim, 0 - Nao)? ");
    scanf("%d", &aluno.possuiHistorico);

    char nomeCurso[50];

    menuCursos();
    printf("\n\nInforme o nome do curso desejado: ");
    scanf(" %[^\n]s", nomeCurso);

    realizarMatricula(cursos, MAX_CURSOS, aluno, nomeCurso);

    return 0;
}
