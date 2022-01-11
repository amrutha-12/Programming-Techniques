#include <stdio.h>
int main()
{
    int x;int y;int z;
    scanf("%d %d %d",&x,&y,&z);
    if(y<=12 & y>=1)
    {
        if(y==2)
        {
            if(x>29 | x<1)
            {
                printf("%d\n",0);
            }        
            else if(x==29)
            {
                if(z%100==0)
                {
                    if(z%400==0)
                    {
                        printf("%d\n",1);
                    }
                    else
                    {
                        printf("%d\n",0);
                    }
                }
                else if(z%4==0)
                {
                    printf("%d\n",1);
                }
                else
                {
                    printf("%d\n",0);
                }
            }
            else
            {
                printf("%d\n",1);
            }
        }
        else if(y%2==1 & y<8)
        {
            if (x>=1 & x<=31)
            {
                printf("%d\n",1);
            }
            else
            {
                printf("%d\n",0);
            }
        }
        else if(y%2==0 & y>=8)
        {
            if (x>=1 & x<=31)
            {
                printf("%d\n",1);
            }
            else
            {
                printf("%d\n",0);
            }
        }
        else
        {
            if (x>=1 & x<=30)
            {
                printf("%d\n",1);
            }
            else
            {
                printf("%d\n",0);
            }
        }
    }
    else
    {
        printf("%d\n",0);
    }
}