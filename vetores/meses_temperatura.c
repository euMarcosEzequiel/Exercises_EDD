#include <stdio.h>
#include <string.h>

#define MESES 12

struct MesTemperatura {
    char nome[20];
    float temperatura;
};

void ordenarMeses(struct MesTemperatura meses[], int n) {
    int i, j, min_idx;
    struct MesTemperatura temp;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (meses[j].temperatura < meses[min_idx].temperatura)
                min_idx = j;
        temp = meses[min_idx];
        meses[min_idx] = meses[i];
        meses[i] = temp;
    }
}

int main() {
    struct MesTemperatura meses[MESES];

    printf("Digite os meses do ano e suas temperaturas medias:\n");
    for (int i = 0; i < MESES; i++) {
        printf("Mes %d: ", i + 1);
        scanf("%s %f", meses[i].nome, &meses[i].temperatura);
    }

    ordenarMeses(meses, MESES);

    printf("\nMeses ordenados por temperatura:\n");
    for (int i = 0; i < MESES; i++) {
        printf("%s: %.2f°C\n", meses[i].nome, meses[i].temperatura);
    }

    return 0;
}
