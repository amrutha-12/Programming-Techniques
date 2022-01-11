#include <stdio.h>

double my_cos(double angle){
    // Initialize and assign an epsilon value
    double epsilon=0.01;
    // Convert degree to radians
    double pi=(22.0/7.0);
    angle*=(pi/180);
    //printf("%f ",angle);
    // Write code to the logic "cos x = 1 - x^2/2! + x^4/4! - + ..."
    double newterm=1;
    double cos;
    int j=0;
    while(newterm>=epsilon)
    {
        if(j%4==0)
        {
            cos+=newterm;
        }
        if(j%2==0 && j%4!=0)
        {
            cos-=newterm;
        }
        j++;
        newterm*=(angle/j);
    }
    return cos;
}

int main(){
    double degree;
    scanf("%lf", &degree);
    double result = my_cos(degree);
    printf("%lf", result);
    
    return 0;
}