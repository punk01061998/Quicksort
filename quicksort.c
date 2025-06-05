#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a,int *b);
int partition(int arr[],int low,int high)
{
    int pivot=arr[high];
    int i=low-1,j;
    for(j=low;j<=high-1;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}

void quicksort(int arr[],int low,int high)
{
    if(low<high)
    {
    int pi=partition(arr,low,high);
    quicksort(arr,low,pi-1);
    quicksort(arr,pi+1,high);
    }
}

void swap(int *a,int *b)
{
    int t=*a;
        *a=*b;
        *b=t;
}

void printArray(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

int main()
{
    int i,n;
    clock_t start,end;
    float ftime;
    printf("Enter how many random numbers you want to generate\n");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        arr[i]=rand()%n;
    }
    start=clock();
    printf("Original Array\n");
    printArray(arr,n);

    quicksort(arr,0,n-1);

    printf("Sorted Array\n");
    printArray(arr,n);
    end=clock();

    ftime=((double)end-start)/CLOCKS_PER_SEC;
    printf("Tejas Raijadhav (1AY23CS202)\n");
    printf("Time taken for %d inputs =%f",n,ftime);
    return 0;
}