#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <math.h>
#include <float.h>

/**
 * @brief функция, считывающая число из буфера обмена
 * @return вовзращает ошибку и закрывает программу в случае, если число введено некорректно 
 */
double input(void);

/**
 * @brief функция, рассчитывающая значение первой функции
 * @param a константа a = 0.3
 * @param x переменная x
 * @return возвращает рассчитанное значение функции
 */
double first_function(const double a, const double x);

/**
 * @brief функция, рассчитывающая значение второй функции
 * @param a константа a = 0.3
 * @param x переменная x
 * @return возвращает рассчитанное значение функции
 */
double next_function(const double a, const double x);
 
/**
 * @brief точка входа в программу
 * @return 0 в случае успеха
 */
int main(void) 
{ 
    const double a = 0.3;
    printf("please enter value x:\n");
    const double x = input();
    if (a * x < 1 + DBL_EPSILON)
    { 
        double function_1 = first_function(a, x);
        printf("The value of function in x = %lf\n", function_1);
    }
    else
    { 
        double function_2 = next_function(a, x);
        printf("The value of function in x = %lf\n", function_2);
    }

    
    return 0;
}

double input(void)
{ 
    double value = 0;
    int result = scanf("%lf", &value);
    if (result != 1)
    { 
        errno = EIO; 
        perror("Error input");
        exit(EXIT_FAILURE);
    }

    return value;
}

double first_function(const double a, const double x)
{ 
    return a * sin((pow(x, 2) + 1) / 10);
}

double next_function(const double a, const double x)
{ 
    return a * cos((x - 1) / 10);
}
