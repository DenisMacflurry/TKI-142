#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

/**
 * @param getEdge - выводит площадь грани
 * @param getFullsSurface - выводит площадь полной поверхности
 * @param getVolume - выводит обьем
 */
enum Operation{
    Edge = 1,
    FullSurface = 2,
    Volume = 3
};

/**
 * @brief - выыодит площадь грани
 * @param a сторона куба
 * @return площадь грани
 */
double getEdge(const double a);

/**
 * @brief - выыодит площадь грани
 * @param a сторона куба
 * @return площадь полной поверхности
 */
double getFullSurface(const double a);

/**
 * @brief - выыодит объем
 * @param a сторона куба
 * @return площадь грани
 */
double getVolume(const double a);

/**
 * @brief Считывает вещественное число
 * @return возвращает вещественное число
 */
double input(void);

/**
 * @brief Ввод полученного целого значения
 * @return Возвращает полученное целое значение
 */
int inputOperation(void);

/**
 * @brief точка входа в программу
 * @return 0 в случае успеха
 */
int main(void) {
    printf("Введите сторону куба ");
    const double a = input();
    printf("Что вы хотите узнать?\n Площадь грани куба - 1 \n Площадь полной поверхности - 2\n Объем куба - 3 \n");
    int operation = inputOperation();
    switch(operation) {
        case Edge:{ 
            printf("Площадь грани = %lf\n", getEdge(a));
            break;
        }
        case FullSurface:{
            printf("Площадь полной поверхности = %lf\n", getFullSurface(a));
            break;
        }
        case Volume:{
            printf("Объем = %lf\n", getVolume(a));
            break;
        }
        default: {
            printf("Неверно введена операция");
        }
    
    }

    return 0;
}

double input() {
    double value = 0.0;
    int result = scanf_s("%lf", &value);
    if (result != 1) {
        errno = EIO;
        perror("Invalid input!!!");
        exit(EXIT_FAILURE);
    }
    return value;
}

int inputOperation(void) {
	int i = 0;
	int check = scanf_s("%d", &i);
	if (check != 1) {
		errno = EIO;
		perror("Input error!!!\n");
		exit(EXIT_FAILURE);
	}
	return i;
}

double getEdge(const double a){
    return pow(a,2);
}

double getFullSurface(const double a){
    return 6*pow(a,2);
}

double getVolume(const double a){
    return pow(a,3);
}
