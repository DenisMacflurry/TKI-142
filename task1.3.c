#include <stdio.h>
#include <math.h>
#include <errno.h>
#include<stdlib.h>

/**
* @brief рассчитывает потенциальную энергию пружины
* @param  x - значение растяжения пружины
* @param k - коэффициент жесткости пружины
* @return рассчитанное значение
*/
double getPotentialEnergy(const double x, const double k);
 
/**
* @brief считывает вещественное число
* @return возвращает вещественное число
*/
double input(void);

/**
* @brief Точка входа в программу.
* @return 0, в случае успеха.
*/
int main(void) {
    printf("Введите растяжение пружины (мм): ");
    double x = input();
    printf("Введите коэффициент жесткости: ");
    double k = input();
    printf("Потенциальная энергия пружины: %.2lf", getPotentialEnergy(x,k));

    return 0;
}

double input(void) {   
    double value = 0.0; 
    int result = scanf("%lf", &value);
    if (result != 1) {
        errno = EIO;
        perror("Input error!!!\n");
        exit(EXIT_FAILURE);
    }
    return value;
}

double getPotentialEnergy(const double x, const double k) {
    const double half = 0.5;
    const double millimetersToMeters = 0.001;
    return (k*(pow(x * millimetersToMeters,2)) * half);
}