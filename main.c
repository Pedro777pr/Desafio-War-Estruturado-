#include <stdio.h>
#include <string.h>

#define MAX_TERRITORIOS 5
#define MAX_NOME 30
#define MAX_COR 10

typedef struct {
    char nome[MAX_NOME];
    char cor[MAX_COR];
    int tropas;
} Territorio;

/* Remove newline deixado por fgets */
void trim_newline(char *s) {
    size_t n = strlen(s);
    if (n > 0 && s[n-1] == '\n') s[n-1] = '\0';
}

/* Cadastro dos territórios */
void cadastrarTerritorios(Territorio mapa[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("\n=== Cadastro do Territorio %d ===\n", i+1);
        printf("Nome: ");
        fgets(mapa[i].nome, MAX_NOME, stdin);
        trim_newline(mapa[i].nome);
        if (strlen(mapa[i].nome) == 0) {
            printf("Nome vazio. Usando 'Territorio%d'.\n", i+1);
            snprintf(mapa[i].nome, MAX_NOME, "Territorio%d", i+1);
        }
        printf("Cor do exército (ex: vermelho, azul): ");
        fgets(mapa[i].cor, MAX_COR, stdin);
        trim_newline(mapa[i].cor);
        if (strlen(mapa[i].cor) == 0) strcpy(mapa[i].cor, "neutro");
        printf("Quantidade de tropas: ");
        while (scanf("%d", &mapa[i].tropas) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF);
            printf("Quantidade inválida. Digite um número: ");
        }
        int c; while ((c = getchar()) != '\n' && c != EOF); // limpar buffer
    }
}

/* Exibe os territórios cadastrados */
void exibirTerritorios(Territorio mapa[], int tamanho) {
    printf("\n=== Territorios Registrados ===\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d) Nome: %s | Cor: %s | Tropas: %d\n", i+1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
}

int main() {
    Territorio mapa[MAX_TERRITORIOS];
    printf("Bem-vindo ao Desafio War Estruturado - Nível Novato.\n");
    printf("Voce ira cadastrar %d territorios.\n", MAX_TERRITORIOS);
    cadastrarTerritorios(mapa, MAX_TERRITORIOS);
    exibirTerritorios(mapa, MAX_TERRITORIOS);
    return 0;
}
