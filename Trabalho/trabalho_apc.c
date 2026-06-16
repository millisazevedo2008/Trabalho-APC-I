#include <stdio.h>
#include <string.h>

#define TAM_MAX 10

// Codigo desenvolvido por Maria hellenna e Camilla
struct Filme {
    int id;
    char titulo[100];
    char genero[50];
    int ano;
};

int main() {
    struct Filme catalogo[TAM_MAX];
    int qtd_atual = 0; // Controle explícito da quantidade de registros
    int opcao;

    // --- BLOCO DESENVOLVIDO POR: MARIA (Menu Principal e Estrutura) ---
    do {
        printf("\n===================================\n");
        printf("       CINE-REGISTRO v1.0         \n");
        printf("===================================\n");
        printf("1. Cadastrar Filme\n");
        printf("2. Listar Filmes\n");
        printf("3. Atualizar Filme\n");
        printf("4. Remover Filme\n");
        printf("5. Sair\n");
        printf("===================================\n");
        printf("Quantidade atual de filmes: %d/%d\n", qtd_atual, TAM_MAX);
        printf("Escolha uma opcao: ");

        
        if (scanf("%d", &opcao) != 1) {
            printf("\n[ERRO] Entrada invalida! Digite um numero.\n");
            while (getchar() != '\n'); 
            continue;
        }
        while (getchar() != '\n'); 

        switch (opcao) {
            case 1: 
                //  (Funcionalidade: Cadastro) ---
                if (qtd_atual >= TAM_MAX) {
                    printf("\n[ERRO] O catalogo esta cheio (%d filmes). Remova algum para cadastrar.\n", TAM_MAX);
                    break;
                }

                int novo_id;
                printf("\n--- Cadastrar Novo Filme ---\n");
                printf("Digite o ID do filme (inteiro positivo): ");
                if (scanf("%d", &novo_id) != 1 || novo_id <= 0) {
                    printf("[ERRO] ID invalido! Deve ser um numero inteiro positivo.\n");
                    while (getchar() != '\n');
                    break;
                }
                while (getchar() != '\n');

                // Validação de ID duplicado
                int id_duplicado = 0;
                for (int i = 0; i < qtd_atual; i++) {
                    if (catalogo[i].id == novo_id) {
                        id_duplicado = 1;
                        break;
                    }
                }

                if (id_duplicado) {
                    printf("[ERRO] Ja existe um filme cadastrado com o ID %d!\n", novo_id);
                    break;
                }

                catalogo[qtd_atual].id = novo_id;
                printf("Titulo: ");
                fgets(catalogo[qtd_atual].titulo, sizeof(catalogo[qtd_atual].titulo), stdin);
                catalogo[qtd_atual].titulo[strcspn(catalogo[qtd_atual].titulo, "\n")] = '\0';

                printf("Genero: ");
                fgets(catalogo[qtd_atual].genero, sizeof(catalogo[qtd_atual].genero), stdin);
                catalogo[qtd_atual].genero[strcspn(catalogo[qtd_atual].genero, "\n")] = '\0';

                printf("Ano de Lancamento: ");
                if (scanf("%d", &catalogo[qtd_atual].ano) != 1 || catalogo[qtd_atual].ano < 1888) {
                    printf("[ERRO] Ano invalido!\n");
                    while (getchar() != '\n');
                    break;
                }
                while (getchar() != '\n');

                qtd_atual++;
                printf("\n[SUCESSO] Filme cadastrado com sucesso!\n");
                break;