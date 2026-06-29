#include <stdio.h>

void dias_para_semanas(int dias) {
    if (dias / 7 == 0 && dias != 1) {
        printf("%d dias", dias);
    }
    else if (dias == 1) {
        printf("1 dia");
    }
    else if (dias % 7 == 0 && dias / 7 != 1) {
        printf("%d semanas", dias / 7);
    }
    else if (dias / 7 == 1) {
        printf("1 semana");
    }
    else {
        printf("%d semanas e %d dias", dias / 7, dias % 7);
    }
}
int main() {
    int dia;
    printf("Insira o numero de dias de determinado evento: ");
    scanf("%d", &dia);
    dias_para_semanas(dia);
    return 0;
}
