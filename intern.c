#include <stdio.h>
#include <math.h>
#include <string.h>

double x[] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};
double y[] = {0.91735, 0.8608, 0.81925, 0.7792, 0.71875, 0.6016, 0.37105, -0.056, -0.79505};


#define N (sizeof(y) / sizeof(double))

double a[N - 1] = {};


int factorial(int n)
{
    if(n > 0){
        return n * factorial(n - 1);
    } else {
        return 1;
    }
}


void difference(void)
{
    double buf[N];      
    int i, j, k;      
    

    memcpy(buf, y, (sizeof(double) * N));


    for(j = 0; j < N - 1; j++){
        for(k = 0; k < (N - (1 + j)); k++){
            buf[k] = buf[k + 1] - buf[k];
        }
        a[j] = buf[0];  
    }
}


double newton(double X)
{
    double sum, temp;
    double p;
    
    p = (X - x[0]) / (x[1] - x[0]);
    
    difference();
    
    sum = y[0];
    for(int i = 0; i < N; i++){
        temp = 1;
        for(int j = 0; j < (i + 1); j++){
            temp *= (p - j);
        }
        temp = temp * a[i] / factorial(i + 1);
        sum += temp;
    }
    return sum;
}


int main(void)
{
    printf("y = %f\n", newton(0.43));    
    
    return 0;
}
