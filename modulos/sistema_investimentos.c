#include <stdio.h>
#include <stdlib.h>

void menuInvestimento(){
    printf("Tipos de investimentos: ");
    printf("\n\t1 - Poupanca | Rendimento 8%% ao ano.  | Risco: Baixo");
    printf("\n\t2 - Acoes    | Rendimento 10%% ao ano. | Risco: Medio");
    printf("\n\t3 - Imoveis  | Rendimento 12%% ao ano. | Risco: Alto");
    printf("\n\n");
}

float redimentoPoupanca(float capital, int anos){
    float rendimento = capital;
    for(int i = 0; i < anos; i++){
        rendimento += capital * 0.08;
    }

    return rendimento;
}

float redimentoAcoes(float capital, int anos){
    float rendimento = capital;
    for(int i = 0; i < anos; i++){
        rendimento += capital * 0.10;
    }

    return rendimento;
}

float redimentoImoveis(float capital, int anos){
    float rendimento = capital;
    for(int i = 0; i < anos; i++){
        rendimento += capital * 0.12;
    }

    return rendimento;
}

void imprimir(float capital, int anos, float rendimento, int opcao){
    system("cls");
    printf("Capital inicial: R$ %.2f", capital);
    printf("\nTempo de investimento: %i anos", anos);
    if(opcao == 1){
        printf("\nTipo de investimento: Poupanca.");
        printf("\nTaxa anual: 8%% ao ano.");
    }
    else if(opcao == 2){
        printf("\nTipo de investimento: Acoes.");
        printf("\nTaxa anual: 10%% ao ano.");
    }
    else{
        printf("\nTipo de investimento: Imoveis.");
        printf("\nTaxa anual: 12%% ao ano.");
    }

    printf("\nRendimento: R$ %.2f", rendimento);
}

int main(){

    float capital;
    int anos, opcao;

    printf("Qual valor deseja investir? ");
    scanf("%f", &capital);
    printf("Quanto tempo voce deseja investir? (em anos) ");
    scanf("%i", &anos);

    system("cls");
    menuInvestimento();

    do{

        printf("Qual opcao de investimento voce deseja? ");
        scanf("%i", &opcao);

        if(opcao != 1 && opcao != 2 && opcao != 3){
            printf("Opcao invalida! Escolha entre 1, 2 ou 3.\n");
        }
    }while(opcao != 1 && opcao != 2 && opcao != 3);

    if(opcao == 1){
        imprimir(capital, anos, redimentoPoupanca(capital, anos), opcao);
    }
    else if(opcao == 2){
        imprimir(capital, anos, redimentoAcoes(capital, anos), opcao);
    }
    else{
        imprimir(capital, anos, redimentoImoveis(capital, anos), opcao);
    }

    printf("\n\n");
    return 0;
}
