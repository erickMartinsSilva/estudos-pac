#include <stdio.h>

float obter_custo_total(float valor_litro, float quantidade_litros) {
    return valor_litro * quantidade_litros;
}
int main() {
    float valor_litro, quantidade_litros, valor_total;
    printf("Insira o valor do litro de um combustivel: R$");
    scanf("%f", &valor_litro);
    printf("Insira a quantidade de litros abastecida por um cliente: ");
    scanf("%f", &quantidade_litros);
    valor_total = obter_custo_total(valor_litro, quantidade_litros);
    printf("Valor a ser pago: R$%.2f", valor_total);
    return 0;
}
