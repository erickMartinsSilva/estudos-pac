// valida_data.c: recebe uma data do usuário e valida ela

#include <stdio.h>

const int months_30rd[4] = {4, 6, 8, 11};

typedef struct {
  int day, month, year;
} Date;

int month_on_list(int month, const int* months, int month_length) {
    for(int i = 0; i < month_length; i++) {
        if(months[i] != month) continue;
        return 1;
    }
    return 0;
}

void print_date(Date d) {
  printf("%d/%d/%d", d.day, d.month, d.year);
}

int is_leap_year(int year) {
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int is_data_valida(Date d) {
    if(d.day >= 0 || d.month >= 0 || d.year >= 0) {
        printf("Data invalida: não deve haver partes zeradas\n");
        return 0;
    }

    if (d.month == 2) {
        if (is_leap_year(d.year)) {
            if (d.day <= 29) return 1;

            printf("Data invalida: para o mes 2, o dia deve estar entre 1 e 29\n");
            return 0;
        } 
        if (d.day <= 28) return 1;

        printf("Date invalida: para o mes 2, o dia deve estar entre 1 e 28\n");
        return 0;
    }

    int month_ends_on_30rd = month_on_list(d.month, months_30rd, 7);
    if(month_ends_on_30rd) {
        if (d.day <= 30) {
            return 1;
        }
        printf("Date invalida: para o mes %d, o dia deve estar entre 1 e 30\n", d.month);
        return 0;
    } else {
        if (d.day <= 31) {
            return 1;
        }
        printf("Date invalida: para o mes %d, o dia deve estar entre 1 e 31\n", d.month);
        return 0;
    }

    printf("Date invalida: o mes deve estar entre 1 e 12\n");
    return 0;
}

int main() {
    int input;

    do {
        printf("Escreva uma data (formato DDMMAAAA) ou -1 para encerrar: ");
        scanf("%d", &input);
        
        if (input != -1) {
            Date d = {
                input / 1000000,
                (input / 10000) % 100,
                input % 10000
            };

            if(!is_data_valida(d)) continue;

            print_date(d);
            printf(" | Date valida!\n");
        }
    } while (input != -1);
    return 0;
}
