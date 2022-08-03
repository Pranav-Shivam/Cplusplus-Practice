#include<stdio.h>

int main()
{
    int len,i,sum=0,arr[25];
    printf("Enter the length of an array :- ");
    scanf("%d",&len);
    for(i=0;i<len;i++)
    {
        printf("Enter an array elements  ");
        scanf("%d",&arr[i]);
    }
    //sum of elements :-
    for(i=0;i<len;i++)
    {
        sum=sum+arr[i];
    }
    printf("The sum of all elements of an array is %d\n",sum);
    printf("\nThe all elements of an array is \n");
    for(i=0;i<len;i++)
    {
        printf("%d \t",arr[i]);

    }
    return 0;
}