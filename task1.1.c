#include <stdio.h>
#include <math.h>

/**
* @brief рассчитывает выражение A по формуле
* @param x - значение константы х
* @param y - значение константы y
* @param a - значение константы z
* @return рассчитанное значение
*/
double getA(const double x, const double y, const double z);

/**
* @brief рассчитывает выражение B по формуле
* @param x - значение константы х
* @param y - значение константы y
* @param a - значение константы z
* @return рассчитанное значение
*/
double getB(const double x, const double y, const double z);

/**
* @brief Точка входа в программу.
* @return 0, в случае успеха.
*/
int main() {

  const double x = 2.2;
  const double y = 9.2;
  const double z = 10.2;
  printf("%f\n", getA(x, y, z));
  printf("%f", getB(x, y, z));

  return 0;
}

double getA(const double x, const double y, const double z) {
  return log(z+pow(x, 2))+pow(sin(x/y), 2);
}
double getB(const double x, const double y, const double z) {
  return exp(-z) * ((x+sqrt(x+z)) / (x-sqrt(abs(x-y))));
}