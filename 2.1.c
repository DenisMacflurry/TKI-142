#include <stdio.h> 
#include <errno.h>
#include <math.h> 
#include <float.h>
#include <stdlib.h>

/**
 * @param AREA_FACE площадь одной грани
 * @param TOTAL_AREA площадь полной поверхности
 * @param VOLUME_CUBE обьем куба
 */
enum choice {AREA_FACE = 1, TOTAL_AREA = 2, VOLUME_CUBE = 3};

/**
 * @brief функция печатающая выбор пользователю
 */
void print_menu(void);

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
    print_menu();
    int dependet = (int)input();

    switch (dependet) {
    case AREA_FACE:
            printf("The area of the face: %.3lf\n", area_of_the_face(length));
            break;

        case  TOTAL_AREA :
            printf("The total surface area: %.3lf\n", total_surface_area(length));
            break;

        case VOLUME_CUBE:
            printf("The volume of the cube: %.3lf\n", volume_of_the_cube(length));
            break;

        default:
            perror("Invalid operation selected.\n");
            exit(EXIT_FAILURE);
    }

    return 0;
}

void print_menu(void)
{ 
    printf("Select an operation:\n");
    printf("%d - Area of the face\n", AREA_FACE);
    printf("%d - Total surface area\n", TOTAL_AREA);
    printf("%d - Volume of the cube\n", VOLUME_CUBE);

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
