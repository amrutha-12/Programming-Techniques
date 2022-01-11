#include <stdio.h>
int checkifprime(int a)
{
    int flag=0;
    for(int i=2;i<(a/2);i++)
    {
        if(a%i==0)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        return(1);
    }
    else
    {
        return(0);
    }
}    
int main()
{
    int n; 
    scanf("%d",&n);
    for(int j=2;j<=n;j++)
    {
        if(checkifprime(j)==1)
        {
            while(n%j==0)
            {
                printf("%d ",j);
                n/=j;
            }
        }
    }
    printf("\n");
}