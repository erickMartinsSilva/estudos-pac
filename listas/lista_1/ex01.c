// ex01.c: soma dois números

#include <stdio.h>

int sum(int a, int b) {
    printf("Soma de %d e %d = %d", a, b, a + b);
    return a + b;
}
int main() {
    int numero1, numero2, sum_numero1_numero2;
    printf("Insira dois numeros: ");
    scanf("%d %d", &numero1, &numero2);
    sum_numero1_numero2 = sum(numero1,numero2);
    return 0;
}
