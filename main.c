
#include <stdio.h>

int main() {
    int estado[10];          /* 1 = ativo, 0 = inativo */
    int n = 0;
    int i;
    int ativos = 0;
    int inativos = 0;
    int lido;                /* resultado do scanf: 1 = leu um numero, 0 = digitou letra */
    char lixo;               /* usado para descartar o que sobrou na linha digitada */
    float percentual;

    printf("=== RADAR DE DISPOSITIVOS DA REDE ===\n");

    /* F1: validar N (1 a 10), tambem recusando letras */
    printf("Quantidade de dispositivos (1 a 10): ");
    lido = scanf("%d", &n);
    do {
        scanf("%c", &lixo);
    } while (lixo != '\n');

    while (lido != 1 || n < 1 || n > 10) {
        printf("Valor invalido! Digite um numero entre 1 e 10: ");
        lido = scanf("%d", &n);
        do {
            scanf("%c", &lixo);
        } while (lixo != '\n');
    }

    /* F1 + F2: ler e validar cada estado (somente 0 ou 1) e guardar no vetor */
    for (i = 0; i < n; i++) {
        printf("Estado do dispositivo %d (1 = ativo, 0 = inativo): ", i + 1);
        lido = scanf("%d", &estado[i]);
        do {
            scanf("%c", &lixo);
        } while (lixo != '\n');

        while (lido != 1 || (estado[i] != 0 && estado[i] != 1)) {
            printf("Estado invalido! Digite apenas 0 ou 1: ");
            lido = scanf("%d", &estado[i]);
            do {
                scanf("%c", &lixo);
            } while (lixo != '\n');
        }
    }

    /* F3: percorrer o vetor e contar ativos e inativos */
    for (i = 0; i < n; i++) {
        if (estado[i] == 1) {
            ativos = ativos + 1;
        } else {
            inativos = inativos + 1;
        }
    }

    /* F3: percentual com numero real (evita divisao inteira) */
    percentual = (ativos * 100.0) / n;

    /* F2: listar os N estados armazenados no vetor */
    printf("\n--- PAINEL FINAL ---\n");
    printf("Estados: ");
    for (i = 0; i < n; i++) {
        printf("%d ", estado[i]);
    }
    printf("\n");

    printf("Ativos: %d\n", ativos);
    printf("Inativos: %d\n", inativos);
    printf("Disponibilidade: %.1f%%\n", percentual);

    /* F4: alerta quando houver 2 ou mais dispositivos indisponiveis */
    if (inativos >= 2) {
        printf("ALERTA: 2 ou mais dispositivos indisponiveis!\n");
    } else {
        printf("Situacao normal: sem alerta.\n");
    }

    return 0;
}
