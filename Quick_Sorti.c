#include<stdio.h>

void swap(int arr[],int i,int j)
{
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}
int partiton(int arr[],int l, int r)
{
	int pivot=arr[r];
	int i=l-1;
	for(int j=l;j<r;j++)
	{
		if(arr[j]<pivot)
		{
			i++;
			swap(arr,i,j);
		}
	}
	swap(arr,i+1,r);
	return i+1;
}
void quicksort(int arr[], int l, int r)
{
	if(l<r)
	{
		int pi=partiton(arr,l,r);
		quicksort(arr,l,pi-1);
		quicksort(arr,pi+1,r);
	}
}
 
int main()

{

int x,y;

  int arr[] = {4,1,3,9,7};

    int arr_size = sizeof(arr) / sizeof(arr[0]);

  

    printf("The size of the is %d \n",arr_size);
    printf("\nUnsorted array is \n");


    for (x=0;x< arr_size;x++)

{

printf("%d",arr[x]);

}

  
printf("\n");
    quicksort(arr, 0, arr_size - 1);

  

    printf("\nSorted array is \n");

for (y=0;y< arr_size;y++)

{

printf("%d",arr[y]);

}

  return 0;



}