#include <stdio.h>

int main() {
    int windows = 0, linux = 0, macos = 0;
    int total_votos = 0;
    char voto;

    printf("Por favor, vote no sistema operacional mais utilizado:\n");
    printf("W para Windows\n");
    printf("L para Linux\n");
    printf("M para MacOS\n");

    for (int i = 0; i < 10; i++) {
        printf("Voto %d: ", i + 1);
        scanf(" %c", &voto);
        switch(voto) {
            case 'W':
            case 'w':
                windows++;
                break;
            case 'L':
            case 'l':
                linux++;
                break;
            case 'M':
            case 'm':
                macos++;
                break;
            default:
                printf("Voto invalido! Por favor, vote novamente.\n");
                i--;
        }
    }

    total_votos = windows + linux + macos;

    printf("\nResultados da pesquisa:\n");
    printf("Windows: %d votos (%.1f%%)\n", windows, (windows * 100.0) / total_votos);
    printf("Linux: %d votos (%.1f%%)\n", linux, (linux * 100.0) / total_votos);
    printf("MacOS: %d votos (%.1f%%)\n", macos, (macos * 100.0) / total_votos);

    return 0;
}
