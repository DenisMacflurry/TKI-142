#include "4.h"

int main(void) {
    printf("Введите размер массива\n");
    const size_t n = (size_t)pozitiv_input();
    int* array = create_array(n);

    printf("Выберите метод заполнения массива.\n");
    printf("0 - ручной ввод, 1 - случайное заполнение\n");
    int dependent = pozitiv_input();
    switch (dependent) {
        case INPUT:
            user_input(array, n);
            break;
        case RANDOM:
            random_filling(array, n);
            break;
        default:
            printf("Неверный ввод.\n");
            free(array);
            exit(EXIT_FAILURE);
    }

    print_array(array, n);
    
    printf("Пожалуйста введите целочисленное положительное число:\n");
    int number = pozitiv_input();
    int sum = sum_even_numbered_elements(array, n, number);
    printf("Сумма чётных чисел > заданной вами константы = %d\n", sum);

    printf("Программа создаёт новый массив, в котором чётные положительные элементы массива умножаются на последний элемент массива\n");

    int *new_array = array_multiplied_by_the_last_element(array, n);
    print_array(new_array, n);
    free(new_array);

    printf("Номер первой пары, элементы которой имеют разные знаки:\n");
    int first_pairs = pairs(array, n);
    if (first_pairs != -1) {
        printf("Номер такой пары = %d\n", first_pairs);
    } else {
        printf("К сожалению, такой пары нет\n");
    }

    free(array);
    return 0;
}

int input(void) {
    int value;
    if (scanf("%d", &value) != 1) {
        perror("Ошибка ввода");
        exit(EXIT_FAILURE);
    }
    return value;
}

int pozitiv_input(void) {
    int value = input();
    if (value <= 0) {
        perror("Ошибка: введено некорректное число (должно быть > 0)");
        exit(EXIT_FAILURE);
    }
    return value;
}

int* create_array(const size_t n) {
    int* array = (int*)malloc(n * sizeof(int));
    check_array(array);
    return array;
}

void random_filling(int *array, const size_t n) {
    check_array(array);

    printf("Введите минимальное и максимальное значение:\n");
    int min = input();
    int max = input();

    if (min > max) {
        printf("Ошибка: минимальное значение больше максимального.\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < n; ++i) {
        array[i] = rand() % (max - min + 1) + min;
    }
}

void user_input(int *array, const size_t n) {
    for (size_t i = 0; i < n; ++i) {
        printf("Введите %zu-й элемент:\n", i + 1);
        array[i] = input();
    }
}

void print_array(const int *array, const size_t n) {
    printf("Ваш массив: [");
    for (size_t i = 0; i < n; ++i) {
        printf("%d%s", array[i], (i < n - 1) ? ", " : "]\n");
    }
}

void check_array(const int *array) {
    if (!array) {
        perror("Ошибка: массив не выделен");
        exit(EXIT_FAILURE);
    }
}

int* copy_array(const int *array, const size_t n) {
    int* new_array = (int*)malloc(n * sizeof(int));
    check_array(new_array);

    for (size_t i = 0; i < n; ++i) {
        new_array[i] = array[i];
    }
    return new_array;
}

int sum_even_numbered_elements(const int *array, const size_t n, const int number) {
    int sum = 0;
    for (size_t i = 0; i < n; i++) {
        if (array[i] % 2 == 0 && array[i] > number) {
            sum += array[i];
        }
    }
    return sum;
}

int last_element_from_array(const int *array, const size_t n) {
    return array[n - 1];
}

int *array_multiplied_by_the_last_element(int *array, const size_t n) { 
    int last_element = last_element_from_array(array, n);
    int *new_array = copy_array(array, n);
    for (size_t i = 0; i < n; i++) { 
        if (array[i] > 0 && array[i] % 2 == 0) {
            new_array[i] = array[i] * last_element;
        }
    }
    return new_array;
}

int pairs(const int *array, const size_t n) {
    for (size_t i = 0; i < n - 1; i++) 
    {
        if (array[i] * array[i + 1] < 0) 
        { 
            return i + 1; 
        }
    }
    return -1;
}
