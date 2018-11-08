=======================================================================================================
/*TIME COMPLEXITY
PRIM'S ALGORITHM*/

#include<stdio.h>
#include<time.h>

int a,b,u,v,n,i,j,ne=1;					//global variables defined
int visited[10]={0},min,mincost=0,cost[10][10];		//global array defined
int main()
{
	 clock_t s,end;
	 float t;
	 printf(" Enter the number of nodes:");			//nodes for the graph
	 scanf("%d",&n);
	 printf(" Enter the adjacency matrix:\n");		//for connection between nodes
	 for(i=1;i<=n;i++)
		  for(j=1;j<=n;j++)				//taking cost between nodes
		  {
			   scanf("%d",&cost[i][j]);
			   if(cost[i][j]==0)
			   cost[i][j]=999;			//initialising all nodes to infinity
		  }
	visited[1]=1;						//selecting base node
 	printf("\n");
	s=clock();					//starting the clock time
 	while(ne<n)
 	{
 	 	for(i=1,min=999;i<=n;i++)
   			for(j=1;j<=n;j++)
   				 if(cost[i][j]<min)
   					if(visited[i]!=0)		//if node is not visited
     					{
     						 min=cost[i][j];	//select minimum cost between i and j
      						 a=u=i;			//store it 
      						 b=v=j;
     					}
  		if(visited[u]==0 || visited[v]==0)			//if any one is visited 
  		{
   			printf("n Edge %d:(%d %d) cost:%d",ne++,a,b,min);	//print
   			mincost+=min;
   			visited[b]=1;
  		}
  		cost[a][b]=cost[b][a]=999;
 	}
	end=clock();					//end clock time
	t=(double)((s-end)/CLOCKS_PER_SEC);		//total time elapsed to perform
	printf("Time taken to perform Prim's alogrithm is : %f",t);
 	printf("\n Minimun cost=%d",mincost);
 	return 0;
}

========================================================================================================================