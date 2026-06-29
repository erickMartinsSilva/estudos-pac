#include <stdio.h>

int calcular_diferenca_em_minutos(int hora_prevista, int minutos_previsto, int hora_efetiva, int minutos_efetivo) {
  int total_minutos_previsto = (hora_prevista * 60) + minutos_previsto;
  int total_minutos_efetivo = (hora_efetiva * 60) + minutos_efetivo;
  
  return total_minutos_previsto - total_minutos_efetivo;
}

int main() {
    int horario_previsto, horario_efetivo, hora_prevista, minutos_previsto, hora_efetiva, minutos_efetivo, diferenca_em_minutos;

    printf("Insira o horario previsto de chegada de um voo: ");
    scanf("%d", &horario_previsto);
    printf("Insira o horario efetivo de chegada de um voo: ");
    scanf("%d", &horario_efetivo);

    hora_prevista = horario_previsto / 100;
    minutos_previsto = horario_previsto % 100;
    hora_efetiva = horario_efetivo / 100;
    minutos_efetivo = horario_efetivo % 100;

    diferenca_em_minutos = calcular_diferenca_em_minutos(hora_prevista, minutos_previsto, hora_efetiva, minutos_efetivo);

    printf("Diferenca em minutos entre os horarios: %d min", diferenca_em_minutos);
    return 0;
}
