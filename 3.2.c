#include "3.2.h"

int main(void) {
    printf("Введите количество элементов последовательности n:\n");
    const int n = pozitive_int();

    printf("Введите значение e (пороговое значение):\n");
    const double e = pozitive_double();

    printf("Сумма первых %d членов последовательности: %.6lf\n", n, get_sum_first_n(n));
    printf("Сумма всех членов последовательности, не меньших %.6lf: %.10lf\n", e, get_sum_dependent_e(e));

    return 0;
}


int integer_input(void) {
    int value = 0;
    if (scanf("%d", &value) != 1) {
        perror("Ошибка ввода целого числа");
        exit(EXIT_FAILURE);
    }
    return value;
}


int pozitive_int(void) {
    int value = integer_input();
    if (value <= 0) {
        perror("Значение должно быть положительным целым числом");
        exit(EXIT_FAILURE);
    }
    return value;
}

double input(void)
{ 
    double value = NAN;
    int result = scanf("%lf", &value);
    if (result != 1)
    { 
        errno = EIO; 
        perror("Ошибка ввода вещественного числа");
        exit(EXIT_FAILURE);
    }

    return value; 
}

double pozitive_double(void)
{ 
    double value = input(); 
    if(value <= DBL_EPSILON)
    { 
        perror("Число должно быть положительным\n");
        exit(EXIT_FAILURE);
    }

    return value;
}


double get_next_term(double a_k, int k) {
    return -1 * (a_k * (pow(k + 1.0, 3) / k));
}


double get_sum_first_n(int n) {
    double sum = 0.0;
    double a_k = -8.0;

    for (int k = 1; k <= n; k++) {
        sum += a_k;
        a_k = get_next_term(a_k, k);
    }

    return sum;
}


double get_sum_dependent_e(double e) {
    double sum = 0.0;
    double a_k = -8.0; 
    int k = 1;

    while (fabs(a_k) >= e + DBL_EPSILON) {
        sum += a_k;
        a_k = get_next_term(a_k, k); 
        k++;
    }

    return sum;
}
