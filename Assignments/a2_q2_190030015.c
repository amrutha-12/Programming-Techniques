#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int arr_size;
    printf("Enter array size: ");
    scanf("%d", &arr_size);
    int numberArray[arr_size];

    for (i = 0; i < arr_size; i++)
    {
        scanf("%d,", &numberArray[i]);
    }

    // Write you code below
    for(i=0; i< arr_size; i++)
    {
        int j;
        j=i+1;
        while(j<arr_size)
        {
            if(numberArray[i]==numberArray[j])
            {
                for(int k=j;k<(arr_size-1);k++)
                {
                    numberArray[k]=numberArray[k+1];
                }
                arr_size--;
            }
            else
            {
                j++;
            }
        }
    }
    // Write your code above

    for (i = 0; i < arr_size; i++)
    {
        printf("%d ", numberArray[i]);
    }
    printf("\n");
    return 0;
}