#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS_SIZE 20

int char_existe_em_array_char(char c, char array_char[]) {
    int array_char_size = (sizeof(&array_char)) / (sizeof(char));

    for(int i = 0; i < array_char_size; i++) {
        int igual = strcmp(&c, &array_char[i]);
        if(igual) return 1;
    }
    return 0;
}

typedef struct {
    int cod;
    char nome[20];
    int qtd_estoque;
    int qtd_solicitada;
    int qtd_devolvida;
    int qtd_pendente;
} Produto;

enum TipoMovimento {SOLICITACAO, DEVOLUCAO};

typedef struct {
    int cod;
    enum TipoMovimento tipo;
    int qtd_movimento;
} Movimento;

char escolhas_validas_principal[3] = {'m', 's', 'E'};
char escolhas_validas_movimento[3] = {'s', 'd', 'v'};

char menu_principal() {
    char escolha;

    printf("m. Registrar movimento\n");
    printf("s. Gerar saída\n");
    printf("Escolha a operação desejada (E para encerrar): ");
    
    scanf("  %c", &escolha);
    return escolha;
}

char menu_movimento() {
    char escolha;

    printf("s. Solicitacao\n");
    printf("d. Devolucao\n");
    printf("Escolha o tipo de movimento (v para voltar): ");

    scanf("  %c", &escolha);
    return escolha;
}

int validar_escolha_menu_principal(char escolha) {
    return char_existe_em_array_char(escolha, escolhas_validas_principal);
}

int validar_escolha_menu_movimento(char escolha) {
    return char_existe_em_array_char(escolha, escolhas_validas_movimento);
}

void computa_solicitacao(Produto *p, Movimento mov) {
    if(p->qtd_estoque < mov.qtd_movimento) {
        printf("\nQuantidade solicitada maior que quantidade em estoque, criando pendência...\n");
        p->qtd_pendente += mov.qtd_movimento;
    } else {
        p->qtd_solicitada += mov.qtd_movimento;
        p->qtd_estoque -= mov.qtd_movimento;
    }
    printf("Solicitacao computada com sucesso!\n\n");
}

void computa_devolucao(Produto *p, Movimento mov) {
    if(p->qtd_pendente > 0) {
        printf("Abatendo pendências com devolução...\n");
        if(mov.qtd_movimento <= p->qtd_pendente) {
            p->qtd_pendente -= mov.qtd_movimento;
        } else {
            int restante = mov.qtd_movimento -= p->qtd_pendente;
            if(restante > 0) {
                printf("Atualizando estoque com restante...\n");
                p->qtd_devolvida += restante;
                p->qtd_estoque += restante;
            }
            p->qtd_pendente = 0;
        }
    } else {
        p->qtd_devolvida += mov.qtd_movimento;
    }
    printf("Devolucao computada com sucesso!\n\n");
}

int obter_indice_do_produto(Produto produtos[], int codigo) {
    for(int i = 0; i < MAX_PRODUTOS_SIZE; i++) {
        int produto_encontrado = (codigo == produtos[i].cod) != 0;
        if(produto_encontrado) {
            return i;
        }
    }
    return -1;
}

void computa_movimento(Produto produtos[], Movimento mov) {
    int indice_produto = obter_indice_do_produto(produtos, mov.cod);
    if(indice_produto == -1) {
        fprintf(stderr, "ERRO: Produto não encontrado.\n\n");
        return;
    }

    // Obter entrada do produto na lista de produtos ao invés de criar uma cópia
    Produto *p = &produtos[indice_produto];

    switch(mov.tipo) {
        case SOLICITACAO: computa_solicitacao(p, mov); break;
        case DEVOLUCAO: computa_devolucao(p, mov); break;
        default: fprintf(stderr, "ERRO: Tipo de movimento inválido\n\n"); break;
    }
}

void fluxo_movimento(Produto produtos[]) {
    Movimento mov;

    char escolha;
    int escolha_valida = 0;

    do {
        escolha = menu_movimento();
        escolha_valida = validar_escolha_menu_movimento(escolha);
        if(!escolha_valida) {
            fprintf(stderr, "ERRO: Tipo de movimento inválido, tente novamente.\n\n");
        }
    } while(!escolha_valida);

    switch(escolha) {
        case 's': mov.tipo = SOLICITACAO; break;
        case 'd': mov.tipo = DEVOLUCAO; break;
        case 'v': return;
    }
    printf("Código do produto: ");
    scanf("%d", &mov.cod);
    printf("Quantidade movimentada: ");
    scanf("%d", &mov.qtd_movimento);

    computa_movimento(produtos, mov);
}


Produto le_produto() {
    Produto p;

    printf("Nome: ");
    scanf("   %[^\n]c", p.nome);
    printf("Quantidade em estoque: ");
    scanf("   %d", &p.qtd_estoque);

    return p;
}

void le_produtos(Produto produtos[]) {

    printf("==== LEITURA DE DADOS =====\n");
    for(int i = 0; i < MAX_PRODUTOS_SIZE; i++) {
        printf("== Produto %d ==\n", i+1);
        produtos[i] = le_produto();

        produtos[i].cod = i;
        produtos[i].qtd_solicitada = 0;
        produtos[i].qtd_devolvida = 0;
        produtos[i].qtd_pendente = 0;
    }
}

void geraSaida(Produto produtos[]) {
    printf("==== SAIDA ====\n\n");
    for(int i = 0; i < MAX_PRODUTOS_SIZE; i++) {
        printf("=== Produto %d ===\n", i+1);
        printf("Codigo: %d\n", produtos[i].cod);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Quantidade total em estoque: %d\n", produtos[i].qtd_estoque);
        printf("Quantidade solicitada: %d\n", produtos[i].qtd_solicitada);
        printf("Quantidade devolvida: %d\n", produtos[i].qtd_devolvida);
        printf("Quantidade pendente: %d\n\n", produtos[i].qtd_pendente);
    }
}

int main() {
    Produto produtos[MAX_PRODUTOS_SIZE];
    Movimento mov;

    char escolha;
    int escolha_valida = 0;

    le_produtos(produtos);
    do {
        do {
            escolha = menu_principal();
            escolha_valida = validar_escolha_menu_principal(escolha);
            if(!escolha_valida) {
                fprintf(stderr, "ERRO: Escolha inválida. Tente novamente.\n\n");
            }
        } while(!escolha_valida);

        if(escolha != 'E') {
            switch(escolha) {
                case 'm': fluxo_movimento(produtos); break;
                case 's': geraSaida(produtos); break;
                default: break;
            }
        }
    } while(escolha != 'E');
    return 0;
}

