#include "3.1.h"
int main(void)
{ 
    printf("please enter interval value\n");
    const double start = pozitiv_input();
    const double end = pozitiv_input();
    check_interval(start, end);

    printf("please enter step value\n");
    const double step = pozitiv_input();
    check_step(step);

    for (double x = start; x <= end + DBL_EPSILON; x += step)
    { 
        if(!check_value_x)
        { 
            printf("the function does not exist at this point\n"); 
        }
        else 
        { 
            double result = function(x);
            printf("the function at the point x = %lf\n", result);
        }
    }

    return 0;
}

double input(void)
{ 
    double value = 0.0;
    int result = scanf("%lf", &value);
    if (result != 1)
    { 
        errno = EIO; 
        perror("Error input");
        exit(EXIT_FAILURE);
    }
    
    return value;
}

double pozitiv_input(void)
{ 
    double value = input();
    if (value < DBL_EPSILON)
    { 
        perror("value < 0\n");
        exit(EXIT_FAILURE);
    }

    return value;
}

void check_interval(const double start, const double end)
{ 
    if ((end - start) < DBL_EPSILON)
    {
        perror("interval is set incorrectly\n");
        exit(EXIT_FAILURE);
    }
}

void check_step(const double step)
{ 
    if (step <= DBL_EPSILON)
    { 
        perror("incorrect steз\n");
        exit(EXIT_FAILURE);
    }
}

bool check_value_x(const double x)
{ 
    return x >= DBL_EPSILON;
}


double function(const double x)
{ 
    return x + cos(pow(x, 0.52) + 2);
}
