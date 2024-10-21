#include <stdio.h>
#include <math.h>

/**
* @brief рассчитывает среднее арифметическое
* @param a - значение a
* @param b - значение b
* @return рассчитанное значение
*/
double getAverage(const double a, const double b);

/**
* @brief рассчитывает среднее геометрическое
* @param a - значение a
* @param b - значение b
* @return рассчитанное значение
*/
double getGeometric(const double a, const double b);

/**
* @brief считывает вещественное число
* @return возвращает вещественное число
*/
double input();

/**
* @brief Точка входа в программу.
* @return 0, в случае успеха.
*/
int main() {
    printf("Enter a: ");
    double a = Input();
    printf("Enter b: ");
    double b = Input();
    printf("Average - %lf\n", getAverage(a,b));
    printf("Geometric mean - %lf\n", getGeometric(a,b));

    return 0;
}

double getAverage(const double a, const double b) {
    return (pow(a,3)+pow(b,3))/2;
}

double getGeometric(const double a, const double b) {
    return sqrt(fabs(a)*fabs(b));
}

double Input() {
    double value = 0.0;
    int result = scanf_s("%lf", &value);
    if (result != 1) {
        perror("Invalid input!");
    }
    return value;
}
