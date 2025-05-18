#include<stdio.h>
void heapify(int arr[], int n, int i)
{
    int root = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < n && arr[left] > arr[root])
    {
        root = left;
    }
    if(right < n && arr[right] > arr[root])
    {
        root = right;
    }
    if(root != i)
    {
        printf("Swapping %d and %d\n", arr[i], arr[root]);
        int temp = arr[i];
        arr[i] = arr[root];
        arr[root] = temp;
        
        printf("Array after swap: ");
        for(int k = 0; k < n; k++)
        {
            printf("%d ", arr[k]);
        }
        printf("\n");
        
        heapify(arr, n, root);
    }
}

void heapsort(int arr[], int n)
{
    for(int i = n / 2 ; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for(int i=n-1; i>=0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i]=temp;
        heapify(arr, i, 0);
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
    heapsort(arr, n);
    printf("Sorted array: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
