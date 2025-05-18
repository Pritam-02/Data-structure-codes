/*#include <stdio.h>
void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// finding the partition index for the pivot element
int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (i <= high && A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);
    // swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quicksort(int A[], int low, int high)
{
    int partitionindex;

    if (low < high)
    {
        partitionindex = partition(A, low, high);
        quicksort(A, low, partitionindex - 1);
        quicksort(A, partitionindex + 1, high);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int A[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    
    printf("Original array: ");
    printArray(A, n);
    quicksort(A, 0, n - 1);
    printf("Sorted array: ");
    printArray(A, n);
    
    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to choose a random pivot and partition the array 
int partition(int A[], int low, int high)
{
    // Choose a random pivot and swap with the first element
    //srand(time(NULL));
    int randomIndex = low + rand() % (high - low + 1);
    swap(&A[low], &A[randomIndex]);
    
    int pivot = A[low];
    int i = low ;
    int j = high;

    do
    {
        //while (i <= high && A[i] <= pivot)
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(&A[i], &A[j]);
        }
    } while (i < j);
    
    // Swap A[low] and A[j]
    swap(&A[low], &A[j]);
    return j;
}

void quicksort(int A[], int low, int high)
{
    int partitionindex;

    if (low < high)
    {
        partitionindex = partition(A, low, high);
        quicksort(A, low, partitionindex);
        quicksort(A, partitionindex + 1, high);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int A[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    
    printf("Original array: ");
    printArray(A, n);
    quicksort(A, 0, n - 1);
    printf("Sorted array: ");
    printArray(A, n);
    
    return 0;
}
