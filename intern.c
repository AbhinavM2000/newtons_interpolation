#include <stdio.h>
#include <math.h>
#include <string.h>

double x[5],y[5];



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


void difference()
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


void main()
{
	double k;
	int i;
	i=0;
	printf("Enter %d x-values\n",N); 
	while(i<N)
	{
		scanf("%lf",&x[i]);
		i++;
	}
	i=0;
	printf("Enter %d y-values\n",N); 
	while(i<N)
	{
		scanf("%lf",&y[i]);
		i++;
	}
	printf("Enter x to find y=f(x)\n"); 
	scanf("%lf",&k);
    printf("f(%lf) = %lf\n", k,newton(k));    
	   
    

}
