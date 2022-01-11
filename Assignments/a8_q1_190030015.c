#include <stdio.h>
#include <stdlib.h>

int coefficient(int a, int b)
{
    int coeff=1;
    if(b>(a-b))
    {
        b=a-b;
    }
    for(int i=0;i<b;i++)
    {
        coeff*= (a-i);
        coeff/= (i+1);
    }
    return coeff;
}

int main()
{
    int n;
    scanf("%d",&n);
    
    int **ptr_array;
    ptr_array = ((int**)malloc(n+1 * sizeof(int)));
    int *array;

    for(int i=1;i<=n+1;i++)
    {
        array=(int*)malloc(i * sizeof(int));
        for(int j=0;j<i;j++)
        {
            array[j]=coefficient(i-1,j);
        }
        ptr_array[i-1]=array;
    }

    for(int i=1;i<=n+1;i++)
        {
            for(int j=0;j<i;j++)
            {
                printf("%d ",ptr_array[i-1][j]);
            }
            printf("\n");
        }
    free(ptr_array);
}