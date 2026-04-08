#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.
#define MAX_CARTAS 2
#define MAX_STRING 30

struct Carta {
    char estado[MAX_STRING];
    char codigo[10];
    char nomeCidade[MAX_STRING];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
};

// Função para limpar buffer a cada scanf
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    struct Carta cartas[MAX_CARTAS];
    int totalCartas = 0;
    int opcao;

    // Laço principal do menu que vai ser exibido pro usuario
    do {
        printf("\n=== MENU ===\n");
        printf("1 - Cadastrar cartas\n");
        printf("2 - Listar e comparar cartas\n");
        printf("3 - Sair\n");

        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao) {
        // =========================
        // CADASTRO
        // =========================
        case 1:
            printf("\n=== CADASTRO DE CARTAS ===\n");

            if (totalCartas < MAX_CARTAS) {

                for (int i = totalCartas; i < MAX_CARTAS; i++) {

                    printf("\nCadastro da Carta %d\n", i + 1);

                    printf("Estado: ");
                    fgets(cartas[i].estado, MAX_STRING, stdin);
                    cartas[i].estado[strcspn(cartas[i].estado, "\n")] = '\0';

                    printf("Codigo: ");
                    fgets(cartas[i].codigo, 10, stdin);
                    cartas[i].codigo[strcspn(cartas[i].codigo, "\n")] = '\0';

                    printf("Nome da cidade: ");
                    fgets(cartas[i].nomeCidade, MAX_STRING, stdin);
                    cartas[i].nomeCidade[strcspn(cartas[i].nomeCidade, "\n")] = '\0';

                    printf("Populacao: ");
                    scanf("%d", &cartas[i].populacao);
                    limparBufferEntrada();

                    printf("Area: ");
                    scanf("%f", &cartas[i].area);
                    limparBufferEntrada();

                    printf("PIB: ");
                    scanf("%f", &cartas[i].pib);
                    limparBufferEntrada();

                    printf("Pontos turisticos: ");
                    scanf("%d", &cartas[i].pontosTuristicos);
                    limparBufferEntrada();

                    totalCartas++;
                }

                printf("\nCartas cadastradas com sucesso!\n");

            } else {
                printf("\nLimite de cartas atingido!\n");
            }

            printf("\nPressione Enter para continuar...");
            getchar();
            break;

        // =========================
        // LISTAR + COMPARAR
        // =========================
        case 2:
            printf("\n=== CARTAS CADASTRADAS ===\n");

            if (totalCartas < 2) {
                printf("Cadastre pelo menos 2 cartas para comparar.\n");
            } else {

                // Exibição
                for (int i = 0; i < totalCartas; i++) {
                    printf("\nCarta %d\n", i + 1);
                    printf("Cidade: %s\n", cartas[i].nomeCidade);
                    printf("Populacao: %d\n", cartas[i].populacao);
                    printf("Area: %.2f\n", cartas[i].area);
                    printf("PIB: %.2f\n", cartas[i].pib);
                    printf("Pontos Turisticos: %d\n", cartas[i].pontosTuristicos);
                    printf("-------------------------\n");
                }

                // Comparação (população)
                printf("\n=== COMPARACAO (POPULACAO) ===\n");

                if (cartas[0].populacao > cartas[1].populacao) {
                    printf("Carta 1 venceu!\n");
                } else if (cartas[1].populacao > cartas[0].populacao) {
                    printf("Carta 2 venceu!\n");
                } else {
                    printf("Empate!\n");
                }
            }

            printf("\nPressione Enter para continuar...");
            getchar();
            break;

        // =========================
        // SAIR
        // =========================
        case 3:
            printf("\nSaindo do sistema...\n");
            break;

        default:
            printf("\nOpcao invalida!\n");
            printf("Pressione Enter para continuar...");
            getchar();
            break;
        }

    } while (opcao != 3);

    return 0;
}
