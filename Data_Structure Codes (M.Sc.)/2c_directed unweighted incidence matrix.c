#include<stdio.h>
#define V 10

int adjMatrix[V][V];
int main()
{
 int vertices,edges,i,j,start,end;
 int edgeIndex;
 printf("Enter the number of vertices:");
  scanf("%d",&vertices);
 printf("Enter the number of edges:");
 scanf("%d",&edges);
   for(i=0;i<vertices;i++)
  {
    for(j=0;j<edges;j++)
	 {
		adjMatrix[i][j]=0;
	 }
   }
    for(i=0;i<edges;i++)
	{
     printf("Enter the nodes between which you want to introduce edge(start and end):");
	 scanf("%d %d",&start,&end);
	 	 adjMatrix[end][i]=-1;
		 adjMatrix[start][i]=1;
	 
	}
	printf("The Incidence Matrix is\n");
	for(i=0;i<vertices;i++)
	{
		for(j=0;j<edges;j++)
		{
			printf("%d\t",adjMatrix[i][j]);
		}
     	printf("\n");
	}
     return 0;	
}
