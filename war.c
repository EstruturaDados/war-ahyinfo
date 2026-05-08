// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//        
// ============================================================================
//
// OBJETIVOS:
// - Modularizar completamente o código em funções especializadas.
// - Implementar um sistema de missões para um jogador.
// - Criar uma função para verificar se a missão foi cumprida.
// - Utilizar passagem por referência (ponteiros) para modificar dados e
//   passagem por valor/referência constante (const) para apenas ler.
// - Foco em: Design de software, modularização, const correctness, lógica de jogo.
//
// ============================================================================

// Inclusão das bibliotecas padrão necessárias para entrada/saída, alocação de memória, manipulação de strings e tempo.
#include <stdio.h>
#include <string.h>
// --- Constantes Globais ---
// Definem valores fixos para o número de territórios, missões e tamanho máximo de strings, facilitando a manutenção.
#define MAX_TERRITORIOS 5
#define TAM_STRING 30

// --- Estrutura de Dados ---
// Define a estrutura para um território, contendo seu nome, a cor do exército que o domina e o número de tropas.
struct Territorio {
    char nome[TAM_STRING];
    char cor[TAM_STRING];
    int tropas;
};
// --- Protótipos das Funções ---
// Declarações antecipadas de todas as funções que serão usadas no programa, organizadas por categoria.
// Funções de setup e gerenciamento de memória:
void limpabufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
// Funções de interface com o usuário:
// Funções de lógica principal do jogo:
// Inicialmente cadastrar o nome dos territórios, a cor e o número de tropas

// Função utilitária:

// --- Função Principal (main) ---
// Função principal que orquestra o fluxo do jogo, chamando as outras funções em ordem.
int main() {
    // Criação do vetor de structs com o tamanho máximo definido
    struct Territorio zonaDeDefesa[MAX_TERRITORIOS];
    int totTerritorio = 0;
    int opcao;

    // O bloco 'do' engloba todo o menu e o switch-case
    do {
        printf("\n============================\n");
        printf("    CADASTRO DE TERRITÓRIOS   \n");
        printf("1 - CADASTRAR NOVO TERRITÓRIO\n");
        printf("2 - LISTAR TERRITÓRIOS\n");
        printf("3 - SAIR DO PROGRAMA\n");
        printf("============================\n"); 
        printf("Escolha uma opção: ");

        // Lê a opção do menu e limpa o buffer na sequência
        scanf("%d", &opcao);
        limpabufferEntrada();

        switch (opcao) {
            case 1:
                printf("\n-----Cadastro de um Novo Território----\n");
                if (totTerritorio < MAX_TERRITORIOS) {
                    
                    printf("Digite o nome do Território: ");
                    fgets(zonaDeDefesa[totTerritorio].nome, TAM_STRING, stdin);
                    zonaDeDefesa[totTerritorio].nome[strcspn(zonaDeDefesa[totTerritorio].nome, "\n")] = '\0';

                    printf("Digite a cor do Exército: ");
                    fgets(zonaDeDefesa[totTerritorio].cor, TAM_STRING, stdin);
                    zonaDeDefesa[totTerritorio].cor[strcspn(zonaDeDefesa[totTerritorio].cor, "\n")] = '\0';

                    printf("Digite o número de Tropas: ");
                    scanf("%d", &zonaDeDefesa[totTerritorio].tropas);
                    limpabufferEntrada(); // Limpa o buffer após ler o inteiro

                    totTerritorio++; // Incrementa o contador de territórios cadastrados
                    printf("\nTerritório cadastrado com sucesso!\n");
                } else {
                    printf("\nErro: Excedido o número de Territórios!\n");
                }
                break; 

            case 2:
                printf("\n----------Lista de Territórios ---------\n");
                if (totTerritorio == 0) {
                    printf("Nenhum território cadastrado.\n");
                } else {
                    for (int i = 0; i < totTerritorio; i++) {
                        printf("Território %d:\n", i + 1);
                        printf("  Nome: %s\n", zonaDeDefesa[i].nome);
                        printf("  Cor: %s\n", zonaDeDefesa[i].cor);
                        printf("  Tropas: %d\n", zonaDeDefesa[i].tropas);
                    }
                }  
                printf("\nPressione Enter para continuar...\n");
                getchar();
                break;

            case 3:
                printf("Encerrando o programa...\n");
                break;
                
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }

    } while (opcao != 3); 

    return 0;
}



    // 1. Configuração Inicial (Setup):
    // - Define o locale para português.
    // - Inicializa a semente para geração de números aleatórios com base no tempo atual.
    // - Aloca a memória para o mapa do mundo e verifica se a alocação foi bem-sucedida.
    // - Preenche os territórios com seus dados iniciais (tropas, donos, etc.).
    // - Define a cor do jogador e sorteia sua missão secreta.

    // 2. Laço Principal do Jogo (Game Loop):
    // - Roda em um loop 'do-while' que continua até o jogador sair (opção 0) ou vencer.
    // - A cada iteração, exibe o mapa, a missão e o menu de ações.
    // - Lê a escolha do jogador e usa um 'switch' para chamar a função apropriada:
    //   - Opção 1: Inicia a fase de ataque.
    //   - Opção 2: Verifica se a condição de vitória foi alcançada e informa o jogador.
    //   - Opção 0: Encerra o jogo.
    // - Pausa a execução para que o jogador possa ler os resultados antes da próxima rodada.

    // 3. Limpeza:
    // - Ao final do jogo, libera a memória alocada para o mapa para evitar vazamentos de memória.

   
// --- Implementação das Funções ---

// alocarMapa():
// Aloca dinamicamente a memória para o vetor de territórios usando calloc.
// Retorna um ponteiro para a memória alocada ou NULL em caso de falha.

// inicializarTerritorios():
// Preenche os dados iniciais de cada território no mapa (nome, cor do exército, número de tropas).
// Esta função modifica o mapa passado por referência (ponteiro).

// liberarMemoria():
// Libera a memória previamente alocada para o mapa usando free.

// exibirMenuPrincipal():
// Imprime na tela o menu de ações disponíveis para o jogador.

// exibirMapa():
// Mostra o estado atual de todos os territórios no mapa, formatado como uma tabela.
// Usa 'const' para garantir que a função apenas leia os dados do mapa, sem modificá-los.

// exibirMissao():
// Exibe a descrição da missão atual do jogador com base no ID da missão sorteada.

// faseDeAtaque():
// Gerencia a interface para a ação de ataque, solicitando ao jogador os territórios de origem e destino.
// Chama a função simularAtaque() para executar a lógica da batalha.

// simularAtaque():
// Executa a lógica de uma batalha entre dois territórios.
// Realiza validações, rola os dados, compara os resultados e atualiza o número de tropas.
// Se um território for conquistado, atualiza seu dono e move uma tropa.

// sortearMissao():
// Sorteia e retorna um ID de missão aleatório para o jogador.

// verificarVitoria():
// Verifica se o jogador cumpriu os requisitos de sua missão atual.
// Implementa a lógica para cada tipo de missão (destruir um exército ou conquistar um número de territórios).
// Retorna 1 (verdadeiro) se a missão foi cumprida, e 0 (falso) caso contrário.

// limparBufferEntrada():
// Função utilitária para limpar o buffer de entrada do teclado (stdin), evitando problemas com leituras consecutivas de scanf e getchar.
