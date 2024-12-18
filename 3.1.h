#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <float.h>
#include <stdbool.h>
#include <math.h>

/** 
 * @brief функция, считывающая число из буфера обмена
 * @return вовзращает ошибку и завершает программу в случае, если число введено некорректно
 */
double input(void);

/**
 * @brief функция, считывающая число и проверяющая его на положительность
 * @return возвращает ошибку и зваершает программу в случае, если число отрицательное
 */
double pozitiv_input(void);

/**
 * @brief функция, проверяющая интервал
 * @param start точка начала интервала
 * @param end точка конца интервала
 * @return возвращает ошибку и завершает программу в случае, если интервал задан некорректно
 */
void check_interval(const double start, const double end);

/**
 * @brief функция, проверяющая корректность заданного шага
 * @param step переменная, отвечающая за значение шага
 * @return возвращает ошибку и закрывает программу, в случае, если шаг задан некорректно
 */
void check_step(const double step);

/**
 * @brief проверяет значение заданного параметра x
 * @param x переменная x
 * @return True - если все корректно, в противном случае False
 */
bool check_value_x(const double x);

/**
 * @brief функция, рассчитывающая функцию в точке x
 * @param x переменная x
 * @return возвращает рассчитанное значение функции в точке x
 */
double function(const double x);

/**
 * @brief точка входа в функцию
 * @return 0 в случае успеха
 */
