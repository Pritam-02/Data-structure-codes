#include<stdio.h>
#define V 5
int adjMatrix[V][V];
int main()
{
int vertices,i,j,x,y;
printf("Enter the number of vertices:");
scanf("%d",&vertices);
for(i=0;i<vertices;i++)
 {
	for(j=0;j<vertices;j++)
	{
		adjMatrix[i][j]=0;
	}
 }
  for(i=0;i<vertices;i++)
	{
    printf("Enter the edges (start and end):");
	scanf("%d %d",&x,&y);
	adjMatrix[x][y]=1;
	adjMatrix[y][x]=1;
	}
	printf("The Adjacency Matrix is\n");
	for(i=0;i<vertices;i++)
	{
		for(j=0;j<vertices;j++)
		{
			printf("%d\t",adjMatrix[i][j]);
		}
     	printf("\n");
	}
     return 0;	
}
