#include <stdio.h>

struct Pizza{
    char sabor[100];
    char tamanho[100];
    float preco;
};

struct Setor{
    char nomeSetor[100];
    float valor;
};

struct Venda{
    int numeroVenda;
    struct Pizza pizza;
    struct Setor setor;
    float totalVenda;
};

struct Pizza verificarPizza(int indicePizza, int indiceTamanho){
    struct Pizza pizza;

    if(indicePizza == 1){
        strcpy(pizza.sabor,"Mussarela");
    }
    else if(indicePizza == 2){
        strcpy(pizza.sabor, "Frango");
    }
    else if(indicePizza == 3){
        strcpy(pizza.sabor, "Marguerita");
    }
    else if(indicePizza == 4){
        strcpy(pizza.sabor, "Calabresa");
    }
    else{
        strcpy(pizza.sabor, "Franbacon");
    }

    if(indiceTamanho == 1){
        strcpy(pizza.tamanho, "Individual");
    }
    else if(indiceTamanho == 2){
        strcpy(pizza.tamanho, "8 pedacos");
    }
    else{
        strcpy(pizza.tamanho, "12 pedacos");
    }

    if(indicePizza == 1 && indiceTamanho == 1){
        pizza.preco = 24.90;
    }
    else if(indicePizza == 1 && indiceTamanho == 2){
        pizza.preco = 39.90;
    }
    else if(indicePizza == 1 && indiceTamanho == 3){
        pizza.preco = 49.90;
    }

    else if(indicePizza == 2 && indiceTamanho == 1){
        pizza.preco = 26.90;
    }
    else if(indicePizza == 2 && indiceTamanho == 2){
        pizza.preco = 49.90;
    }
    else if(indicePizza == 2 && indiceTamanho == 3){
        pizza.preco = 59.90;
    }

    else if(indicePizza == 3 && indiceTamanho == 1){
        pizza.preco = 28.90;
    }
    else if(indicePizza == 3 && indiceTamanho == 2){
        pizza.preco = 54.90;
    }
    else if(indicePizza == 3 && indiceTamanho == 3){
        pizza.preco = 64.90;
    }

    else if(indicePizza == 4 && indiceTamanho == 1){
        pizza.preco = 29.90;
    }
    else if(indicePizza == 4 && indiceTamanho == 2){
        pizza.preco = 56.90;
    }
    else if(indicePizza == 4 && indiceTamanho == 3){
        pizza.preco = 66.90;
    }

    else if(indicePizza == 5 && indiceTamanho == 1){
        pizza.preco = 31.90;
    }
    else if(indicePizza == 5 && indiceTamanho == 2){
        pizza.preco = 61.90;
    }
    else if(indicePizza == 5 && indiceTamanho == 3){
        pizza.preco = 71.90;
    }

    return pizza;
};

struct Setor verificarSetor(int indiceSetor){
    struct Setor setor;

    if(indiceSetor == 1){
        strcpy(setor.nomeSetor, "Setor 1");
        setor.valor = 9.90;
    }
    else if(indiceSetor == 2){
        strcpy(setor.nomeSetor, "Setor 2");
        setor.valor = 14.90;
    }
    else if(indiceSetor == 3){
        strcpy(setor.nomeSetor, "Setor 3");
        setor.valor = 17.90;
    }
    else{
        strcpy(setor.nomeSetor, "Setor 4");
        setor.valor = 21.90;
    }

    return setor;
};

void cadastrarVendas(struct Venda vendas[], int qtdVendas){
    for(int i = 0; i < qtdVendas; i++){
        system("cls");
        cardapio();
        printf("Cadastrar venda %i: \n", i+1);
        menuPizza();
        int indiceSabor;
        do{
            printf("\nQual o sabor da pizza: ");
            scanf("%i", &indiceSabor);
            if(indiceSabor < 1 || indiceSabor > 5){
                printf("Sabor invalido! (Selecione um sabor de 1 a 5)");
            }
        }while(indiceSabor < 1 || indiceSabor > 5);

        menuTamanho();
        int indiceTamanho;
        do{
            printf("\nQual o tamanho da pizza: ");
            scanf("%i", &indiceTamanho);
            if(indiceTamanho < 1 || indiceTamanho > 3){
                printf("Tamanho invalido! (Selecione um tamanho de 1 a 3)");
            }
        }while(indiceTamanho < 1 || indiceTamanho > 3);

        menuSetor();
        int indiceSetor;
        do{
            printf("\nQual o setor de entrega: ");
            scanf("%i", &indiceSetor);
            if(indiceSetor < 1 || indiceSetor > 4){
                printf("Setor invalido! (Selecione um tamanho de 1 a 4)");
            }
        }while(indiceSetor < 1 || indiceSetor > 4);

        struct Pizza novaPizza;
        novaPizza = verificarPizza(indiceSabor, indiceTamanho);

        struct Setor novoSetor;
        novoSetor = verificarSetor(indiceSetor);

        struct Venda novaVenda;
        novaVenda.numeroVenda = i+1;
        novaVenda.pizza = novaPizza;
        novaVenda.setor = novoSetor;
        novaVenda.totalVenda = novaPizza.preco + novoSetor.valor;
        vendas[i] = novaVenda;
    }
}

void imprimirVendas(struct Venda venda){
    printf("\n==========================================");
    printf("\nNumero da venda: %i", venda.numeroVenda);
    printf("\n\n  Sabor\t\t\t|\tTamanho\t\t\t|\tPreco");
    printf("\n  %s\t\t|\t%s\t\t|\tR$ %.2f ", venda.pizza.sabor, venda.pizza.tamanho, venda.pizza.preco);
    printf("\n\n  Setor\t\t\t|\tValor");
    printf("\n  %s\t\t|\t%.2f", venda.setor.nomeSetor, venda.setor.valor);
    printf("\n\n\nTotal: \t\tR$ %.2f", venda.totalVenda);
    printf("\n\n");
}

void cardapio(){
    printf("\n|------------|------------|-----------|------------|  |---------|----------|");
    printf("\n|    Sabor   |  Idividual | 8 pedacos | 12 pedacos |  |  Setor  |   Valor  |");
    printf("\n|------------|------------|-----------|------------|  |---------|----------|");
    printf("\n| Mussarela  |  R$ 24,90  |  R$ 39,90 |  R$ 49,90  |  | Setor 1 | R$ 9,90  |");
    printf("\n| Frango     |  R$ 26,90  |  R$ 49,90 |  R$ 59,90  |  | Setor 2 | R$ 14,90 |");
    printf("\n| Marguerita |  R$ 28,90  |  R$ 54,90 |  R$ 64,90  |  | Setor 3 | R$ 17,90 |");
    printf("\n| Calabresa  |  R$ 29,90  |  R$ 56,90 |  R$ 66,90  |  | Setor 4 | R$ 21,90 |");
    printf("\n| Franbacon  |  R$ 31,90  |  R$ 61,90 |  R$ 71,90  |  |---------|----------|");
    printf("\n|------------|------------|-----------|------------|");
    printf("\n\n");
}

void menuPizza(){
    printf("\n|-----------------|");
    printf("\n|       Sabor     |");
    printf("\n|-----------------|");
    printf("\n|  1 - Mussarela  |");
    printf("\n|  2 - Frango     |");
    printf("\n|  3 - Marguerita |");
    printf("\n|  4 - Calabresa  |");
    printf("\n|  5 - Franbacon  |");
    printf("\n|-----------------|");
}

void menuTamanho(){
    printf("\n|-----------------|");
    printf("\n|     Tamanhos    |");
    printf("\n|-----------------|");
    printf("\n|  1 - Individual |");
    printf("\n|  2 - 8 pedaco   |");
    printf("\n|  3 - 12 pedacos |");
    printf("\n|-----------------|");
}

void menuSetor(){
    printf("\n|-------------|");
    printf("\n|    Setor    |");
    printf("\n|-------------|");
    printf("\n| 1 - Setor 1 |");
    printf("\n| 2 - Setor 2 |");
    printf("\n| 3 - Setor 3 |");
    printf("\n| 4 - Setor 4 |");
    printf("\n|-------------|");
}

main(){
    int qtdVendas;
    printf("Quantas vendas foram realizadas? ");
    scanf("%i", &qtdVendas);

    struct Venda vendas[qtdVendas];

    cadastrarVendas(vendas, qtdVendas);

    system("cls");
    cardapio();
    for(int i = 0; i < qtdVendas; i++){
        imprimirVendas(vendas[i]);
    }

    printf("\n\n");
}
