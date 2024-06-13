#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define maxCarroBlocoA 1
#define maxCarroBlocoB 5

void menu(){
    printf("  Veiculo   | Valor por hora | Convenio");
    printf("\nCarro Peq   |     R$ 3,00    |   Sim");
    printf("\nCarro Peq   |     R$ 3,50    |   Nao");
    printf("\nCarro Med   |     R$ 4,00    |   Sim");
    printf("\nCarro Med   |     R$ 4,50    |   Nao");
    printf("\nCaminhonete |     R$ 5,50    |   Sim");
    printf("\nCaminhonete |     R$ 6,50    |   Nao");
}

void calcular(float valor, int qtdHoras){
    float valorFinal = valor * qtdHoras;

    if(qtdHoras >= 3){
        valorFinal = valorFinal - (valorFinal * 0.10);
        printf("\nVoce recebeu o desconto de 10%% por ter ficado mais de 3 horas");
    }

    printf("\nValor final a pagar: R$ %.2f", valorFinal);
}

int main(){

    int blocoA[maxCarroBlocoA];
    int qtdCarroBlocoA = 0;
    int blocoB[maxCarroBlocoB];
    int qtdCarroBlocoB = 0;

    char opcao;
    char tipo;
    char convenio;

    do{
        opcao = 'I';
        tipo = 'I';
        convenio = 'I';

        system("cls");
        printf("A - Estacionar no Bloco A | Vagas disponiveis: %i", maxCarroBlocoA - qtdCarroBlocoA);
        printf("\nB - Estacionar no Bloco B | Vagas disponiveis: %i", maxCarroBlocoB - qtdCarroBlocoB);
        printf("\nS - Sair \n\n");

        do{
            fflush(stdin);
            printf("Escolha um opcao?");
            scanf("%c", &opcao);

            switch(toupper(opcao)){
                case 'A':{
                    if(maxCarroBlocoA == qtdCarroBlocoA){
                        printf("O Bloco A esta lotado! \n");
                        opcao = 'I';
                    }
                    else{
                        opcao = 'A';
                    }
                    break;
                }
                case 'B':{
                    if(maxCarroBlocoB == qtdCarroBlocoB){
                        printf("O Bloco B esta lotado! \n");
                        opcao = 'I';
                    }
                    else{
                        opcao = 'B';
                    }
                    break;
                }
                case 'S':{
                    opcao = 'S';
                    break;
                }
                default:{
                    printf("Opcao invalida! \n");
                    break;
                }
            }
        }while(toupper(opcao) != 'A' && toupper(opcao) != 'B' && toupper(opcao) != 'S');

        if(toupper(opcao) != 'S'){
            system("cls");
            menu();

            printf("\n\nP - Carro Peq");
            printf("\nM - Carro Med");
            printf("\nG - Caminhonete \n\n");

            do{
                fflush(stdin);
                printf("Qual o tipo do veiculo?");
                scanf("%c", &tipo);

                switch(toupper(tipo)){
                    case 'P':{
                        tipo = 'P';
                        break;
                    }
                    case 'M':{
                        tipo = 'M';
                        break;
                    }
                    case 'G':{
                        tipo = 'G';
                        break;
                    }
                    default:{
                        printf("Opcao invalida! \n");
                        break;
                    }
                }
            }while(toupper(tipo) != 'P' && toupper(tipo) != 'M' && toupper(tipo) != 'G');

            system("cls");
            menu();

            printf("\n\nS - Sim");
            printf("\nN - Nao \n\n");

            do{
                fflush(stdin);
                printf("Possui convenio? ");
                scanf("%c", &convenio);

                switch(toupper(convenio)){
                    case 'S':{
                        convenio = 'S';
                        break;
                    }
                    case 'N':{
                        convenio = 'N';
                        break;
                    }
                    default:{
                        printf("Opcao invalida! \n");
                        break;
                    }
                }
            }while(toupper(convenio) != 'S' && toupper(convenio) != 'N');

            system("cls");
            float valor;

            if(toupper(tipo) == 'P' && toupper(convenio) == 'S'){
                printf("Tipo de veiculo: Carro Peq");
                printf("\nConvenio: Sim");
                printf("\nValor por hora: R$ 3,00");
                valor = 3;
            }
            if(toupper(tipo) == 'P' && toupper(convenio) == 'N'){
                printf("Tipo de veiculo: Carro Peq");
                printf("\nConvenio: Nao");
                printf("\nValor por hora: R$ 3,50");
                valor = 3.5;
            }
            if(toupper(tipo) == 'M' && toupper(convenio) == 'S'){
                printf("Tipo de veiculo: Carro Med");
                printf("\nConvenio: Sim");
                printf("\nValor por hora: R$ 4,00");
                valor = 4;
            }
            if(toupper(tipo) == 'M' && toupper(convenio) == 'N'){
                printf("Tipo de veiculo: Carro Med");
                printf("\nConvenio: Nao");
                printf("\nValor por hora: R$ 4,50");
                valor = 4.5;
            }
            if(toupper(tipo) == 'G' && toupper(convenio) == 'S'){
                printf("Tipo de veiculo: Caminhonete");
                printf("\nConvenio: Sim");
                printf("\nValor por hora: R$ 5,50");
                valor = 5.5;
            }
            if(toupper(tipo) == 'G' && toupper(convenio) == 'N'){
                printf("Tipo de veiculo: Caminhonete");
                printf("\nConvenio: Nao");
                printf("\nValor por hora: R$ 6,50");
                valor = 6.5;
            }

            int qtdHoras;
            printf("\n\nQuantas horas ficou no estacionamento? ");
            scanf("%i", &qtdHoras);
            calcular(valor, qtdHoras);

            if(toupper(opcao) == 'A'){
                blocoA[qtdCarroBlocoA] = 1;
                qtdCarroBlocoA++;
            }
            if(toupper(opcao) == 'B'){
                blocoB[qtdCarroBlocoB] = 1;
                qtdCarroBlocoB++;
            }

            printf("\n\n");
            system("pause");
        }

    }while(toupper(opcao) != 'S');

    system("cls");
    printf("Sistema encerrado!");
    printf("\n\n");

    return 0;
}
