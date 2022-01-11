#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int adj_matrix[n][n];
    int adj_list[n][n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&adj_matrix[i][j]);
        } 
    }
    
    int max_output=0;
    int max_input=0;
    
    int a1[n];
    int a2[n];

    for(int i=0;i<n;i++)
    {
        int cnt_out=0;
        for (int j=0;j<n;j++)
        {
            if(adj_matrix[i][j]>0)
            {
                cnt_out++;
                printf("%d ",j+1);
            }
        }
        if(cnt_out>max_output)
        {
            max_output=cnt_out;
        }
        printf("\n");
        a1[i]=cnt_out;
    }

    for(int i=0;i<n;i++)
    {
        int cnt_in=0;
        for (int j=0;j<n;j++)
        {
            if(adj_matrix[j][i]>0)
            {
                cnt_in++;
            }
        }
        if(cnt_in>max_input)
        {
            max_input=cnt_in;
        }
        a2[i]=cnt_in;
    }

    for(int i=0;i<n;i++)
    {
        if(a1[i]==max_output)
        printf("%d ",i+1);
    }
    printf("\n");
    for(int i=0;i<n;i++)
    {
        if(a2[i]==max_input)
        printf("%d ",i+1);
    }
    printf("\n");
}