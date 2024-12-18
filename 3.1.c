#include <stdio.h> 
#include <errno.h>
#include <math.h> 
#include <float.h>
#include <stdlib.h>

/** 
 * @brief функция, считывающая число из буфера обмена
 * @return возвращает ошибку и закрывает в случае, если число введено некорректно
 */
double input(void);

/**
 * @brief функция, проверяющая число на положительность
 * @return возвращает ошибку и закрывает программу в случае, если число неположительное
 */
double pozitiv_double(void);

/**
 * @brief функция, рассчитывающая площадь грани куба
 * @param length длинна ребра куба
 * @return возвращает рассчитыанное значение площади грани куба
 */
double area_of_the_face(const double length);

/**
 * @brief функция, рассчитывающая площадь полной поверхности
 * @param length длинна ребра куба
 * @return возвращает рассчитанное значение площади полной поверхности
 */
double total_surface_area(const double length);

/**
 * @brief функция, рассчитыывающая объем куба
 * @param length длинна ребра куба
 * @return возвращает рассчитанное значение объема куба
 */
double volume_of_the_cube(const double length);

/**
 * @brief точка входа в программу
 * @return 0 в случае успеха
 */
int main(void)
{ 
    printf("Please enter сubas length\n");
    const double length = pozitiv_double();
    printf("the program calculates the area of the face\n");
    
    double area1 = area_of_the_face(length);
    printf("The area of the face: %.3lf\n", area1);

    double area2 = total_surface_area(length);
    printf("total surface area: %.3lf\n", area2);
    
    double volume = volume_of_the_cube(length);
    printf("volume of the cube: %.3lf\n", volume);

    return 0;
}

double input(void)
{ 
    double value = NAN;
    int result = scanf("%lf", &value);
    if(result != 1)
    { 
        errno = EIO;
        perror("Error input");
        exit(EXIT_FAILURE);
    }

    return value;
}

double pozitiv_double(void)
{ 
    double value = input();
    if (value < DBL_EPSILON)
    { 
        perror("the value should be > 0\n");
        exit(EXIT_FAILURE);
    }

    return value;
}

double area_of_the_face(const double length)
{ 
    return length * length; 
}

double total_surface_area(const double length)
{ 
    return 6 * pow(length, 2);
}

double volume_of_the_cube(const double length)
{ 
    return pow(length, 3);
}
