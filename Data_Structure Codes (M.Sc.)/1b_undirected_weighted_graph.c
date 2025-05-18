#include<stdio.h>
#define V 5
int adjMatrix[V][V];
int main()
{
int vertices,i,j,x,y,z;
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
    printf("Enter the edges (start and end) and their weight:");
	scanf("%d %d%d",&x,&y,&z);
	adjMatrix[x][y]=z;
	adjMatrix[y][x]=z;
	}
	printf("The Adjacency Matrix is\n");
	for(i=0;i<vertices;i++)
	{
		for(j=0;j<vertices;j++)
		{
			printf("%d",adjMatrix[i][j]);
		}
     	printf("\n");
	}
     return 0;	
}
