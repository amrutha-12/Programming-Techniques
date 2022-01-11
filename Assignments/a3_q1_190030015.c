#include<stdio.h>


//Write code below  
int is_odd(int n)
{
    //TODO: COMPLETE THIS FUNCTION
    if(n%2==1)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}
  
int is_perfect (int n)
{
   //TODO: COMPLETE THIS FUNCTION
   int i=0;
   while((i*i)<=n)
   {
	   if(i*i==n)
	   {
		   return 1;
	   }
       i++;
   }
   return 0;
}


int count(int a[], int n, int (*pred)(int))
{
	//TODO: COMPLETE THIS FUNCTION
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		cnt+=(pred(a[i]));
	}
    return cnt;
}
//Write code above, do not change code below


int main(int argc, char *argv[])
{
	
	
	
	if (argc!=2) /* argc should be 2 for correct execution */
	{
		/* We print argv[0] assuming it is the program name */
		printf( "usage: %s input_filename\n", argv[0] );
	}
	else
	{
		FILE *file = fopen(argv[1], "r");
			
		/* fopen returns 0, the NULL pointer, on failure */
		
		if (file==0)
		{
			printf( "Could not open file\n" );
		}
		else
		{
			
			int size;
			fscanf (file, "%d", &size);
			int array[size];
     		
     		for(int i=0;i<size;i++){
     			fscanf (file, "%d", &array[i]);
			}
			
			fclose(file);
        		
      	printf("%d\n",count(array, size, is_odd)); //count called with is_odd as an argument
			printf("%d\n",count(array, size, is_perfect)); //count called with is_perfect as an argument
   
		}
	}
	
	return 0;
     
}
