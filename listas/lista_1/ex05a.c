#include <stdio.h>

int converter_horario_para_minutos(int horas, int minutos) {
    return (horas * 60) + minutos;
}
int main() {
    int horario, horas, minutos;
    printf("Insira um horario (formato: HHMM): ");
    scanf("%d", &horario);
    horas = horario / 100;
    minutos = horario % 100;
    printf("%dh%dmin convertido em minutos = %d min", horas, minutos, converter_horario_para_minutos(horas,minutos));
    return 0;
}
