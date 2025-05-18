#include<stdio.h>
void shellsort(int arr[], int n)
{
    printf("Initial array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    for(int gap = n / 2; gap > 0; gap /= 2)
    {
        printf("\nGap = %d\n", gap);
        
        for(int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            
            printf("Checking element %d at index %d\n", temp, i);
            
            for(j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                printf("Swapping %d (index %d) with %d (index %d)\n", arr[j - gap], j - gap, arr[j], j);
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
            
            printf("Array after step: ");
            for(int k = 0; k < n; k++)
                printf("%d ", arr[k]);
            printf("\n");
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    shellsort(arr, n);
    
    printf("\nSorted array: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
