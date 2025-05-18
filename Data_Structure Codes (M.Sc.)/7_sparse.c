#include<stdio.h>
#include<stdlib.h>
/*
int **create_matrix(int rA, int cA)
{
    int i,j;
    int **A = (int**)malloc(rA*sizeof(int*));
    for(i=0;i<rA;i++)
    {
        *(A+i)=(int*)malloc(cA*(sizeof(int)));
    }
    printf("\n enter data of matrix:\n");
    
    for(i=0;i<rA;i++)
    {
        for(j=0;j<cA;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    printf("\n original matrix:\n");
    display(A,rA,cA);
    return A;
}

//body of display function
void display(int **A, int rA, int cA)
{
    int i,j;
    for(i=0;i<rA;i++)
    {
        for(j=0;j<cA;j++)
        {
            printf("\t %d ",A[i][j]);
        }
        printf("\n");
    }
}

int **create_triplet(int **A, int rA, int cA)
{
    int i,j,k,count=0;
    int **t;
    for(i=0;i<rA;i++)
    {
        for(j=0;j<cA;j++)
        {
            if(A[i][j]!=0)
            {
                count ++;
            }
        }
    }
    t=(int **)malloc((count+1)*sizeof(int *));
    for(i=0;i<(count+1);i++)
    {
        *(t+i)=(int*)malloc(3*(sizeof(int)));
    }
    t[0][0]=rA;
    t[0][1]=cA;
    t[0][2]=count;
    k=1;
    for(i=0;i<rA;i++)
    {
        for(j=0;j<cA;j++)
        {
            if(A[i][j]!=0)
            {
                t[k][0]=i;
                t[k][1]=j;
                t[k][2]=A[i][j];
                k++;
            }
        }
    }
    printf("\n triplet matrix:\n");
    display(t, count+1, 3);
    return t;
}

void swap(int **Tr_TripA, int a, int b, int c)
{
    int temp;
    temp=Tr_TripA[a][c];
    Tr_TripA[a][c]=Tr_TripA[b][c];
    Tr_TripA[b][c]=temp;
}

int **create_transpose(int** Trip_A)
{
    int i,j;
    int **Tr_TripA;
    int count=Trip_A[0][2];
    Tr_TripA=(int**)malloc((count+1)*sizeof(int*));
    for(i=0;i<(count+1);i++)
    {
        *(Tr_TripA+i)=(int*)malloc(3*(sizeof(int)));
    }
    for(i=0;i<(count+1);i++)
    {
        Tr_TripA[i][0]=Trip_A[i][1];
        Tr_TripA[i][1]=Trip_A[i][0];
        Tr_TripA[i][2]=Trip_A[i][2];     
    }
    //bubble sort

    for(i=0;i<count;i++)
    {
        for(j=1;j<(count-i);j++)
        {
            if(Tr_TripA[j][0]>Tr_TripA[j+1][0])
            {
                swap(Tr_TripA, j, j+1, 0);
                swap(Tr_TripA, j, j+1, 1);
                swap(Tr_TripA, j, j+1, 2);
            }
        }
    }
    printf("\n transpose matrix\n");
    display(Tr_TripA,(count+1),3);
    return Tr_TripA;
}

int main()
{
    int rA,cA,**A,**Trip_A,**Tr_TripA;
    printf("\n enter the size of matrix A:");
    scanf("%d %d",&rA,&cA);
    A=create_matrix(rA,cA);
    Trip_A=create_triplet(A,rA,cA);
    Tr_TripA=create_transpose(Trip_A);
    return 0;
}*/

int main()
{
    int a[3][3], i, j, nz = 0, z = 0;
    
    // Input the matrix
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("\nEnter the number: ");
            scanf("%d", &a[i][j]);
        }
    }
    
    // Display the matrix
    printf("\nThe matrix is:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    
    // Count non-zero and zero elements
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (a[i][j] == 0)
                z++;
            else
                nz++;
        }
    }
    
    if (nz > z)
    {
        printf("\nDense matrix\n");
    }
    else
    {
        // Sparse matrix representation
        int s[nz][3], k = 0;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (a[i][j] != 0)
                {
                    s[k][0] = i;
                    s[k][1] = j;
                    s[k][2] = a[i][j];
                    k++;
                }
            }
        }

        //Print the sparse matrix
        printf("\nSparse Matrix:");
        for (i = 0; i < nz; i++) {
            printf("\n");
            for (j = 0; j < 3; j++) {
                printf("%d\t", s[i][j]);
            }
        }

        // Compute transpose of the sparse matrix
        int t[nz][3];
        for (i = 0; i < nz; i++)
        {
            t[i][0] = s[i][1]; // Swap row and column
            t[i][1] = s[i][0];
            t[i][2] = s[i][2];
        }
        //print the transpose matrix
        printf("\n\nTranspose of Sparse Matrix:");
        for (i = 0; i < nz; i++) {
            printf("\n");
            for (j = 0; j < 3; j++) {
                printf("%d\t", t[i][j]);
            }
        }
    }
    
    return 0;
}
