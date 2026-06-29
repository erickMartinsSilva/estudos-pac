// ex02.c: média
#include <stdio.h>

float average(float number1, float number2) {
    return (number1 + number2)/2;
}
int main() {
    float n1, n2, media;
    printf("Insira as duas notas de um aluno: ");
    scanf("%f %f", &n1, &n2);
    media = average(n1,n2);
    printf("Media = %.2f", media);
    return 0;
}
