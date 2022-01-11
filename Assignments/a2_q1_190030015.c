#include <stdio.h>
#include <stdlib.h> 

void check_symmetric(int n, int x[n][n]){
// Write your code below
    int flag=0;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            cnt+=1;
            if(x[i][j]!=x[j][i])
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        break;
    }
    printf("%d\n%d",cnt,flag);
// Write your code above 
}


// Driver code; Do not modify anything below this comment!
int main ( int argc, char *argv[] )
{
    if ( argc != 2 ) /* argc should be 2 for correct execution */
    {
        /* We print argv[0] assuming it is the program name */
        printf( "usage: %s input_filename\n", argv[0] );
    }
    else
    {
        FILE *file = fopen(argv[1], "r");
			
		  /* fopen returns 0, the NULL pointer, on failure */
        if (file == 0)
        {
            printf( "Could not open file\n" );
        }
        else
        {
            int num; 
            
            fscanf (file, "%d", &num);
     			int x[num][num];
     			for(int i=0;i<num;i++){
     				for(int j=0;j<num;j++){
     					fscanf (file, "%d", &x[i][j]);
     				}
     			}
            
            fclose(file);
        		check_symmetric(num,x);
        		
        }
    }
    return 0;
}
