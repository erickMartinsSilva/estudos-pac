#include <stdio.h>

float aumentar_em_20_porcento(float valor) {
    return valor * 1.2;
}
int main() {
    float preco_unitario, novo_preco_unitario;
    printf("Insira o preco unitario de um produto: ");
    scanf("%f", &preco_unitario);
    novo_preco_unitario = aumentar_em_20_porcento(preco_unitario);
    printf("Novo preco unitario (c/ aum. de 20 por cento) = %.2f", novo_preco_unitario);
    return 0;
}
