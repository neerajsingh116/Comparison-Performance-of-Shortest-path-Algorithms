#include<stdio.h>
#include<conio.h>
#include<time.h>
# define Infinity 9999
# define Max 100
void dijkastra(int G[Max][Max], int n , int start);
void bellmon(int G[Max][Max],int n,int s);
int main(){
	int G[Max][Max],i,j,n,u;
	printf("Enter number of vertices :");
	scanf("%d",&n);
	printf("ENTER THE ADJACENCY MATRIX\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&G[i][j]);
		}
	}
	printf("Enter the Starting Node (Number) :\n");
	scanf("%d",&u);
	clock_t start,stop;
	start = clock();
	dijkastra(G,n,u);
	stop = clock();
	double runtime= ((double) stop - start)/ CLOCKS_PER_SEC;
	printf("\ncompilation time of Dijkastra is : %f",runtime);
	start = clock();
	bellmon(G,n,u);
	stop = clock();
	double runtime_bellman= ((double) stop - start)/ CLOCKS_PER_SEC;
	printf("\ncompilation time of bellman is : %f",runtime_bellman);
	return 0;
}
void dijkastra(int G[Max][Max], int n,int start){
	int cost[Max][Max], dis[Max],pred[Max];
	int visited[Max],count,mindis,nextnode,i,j;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(G[i][j]==0){
				cost[i][j]=Infinity;
			}
			else{
				cost[i][j]=G[i][j];
			}
		}
	}
	for(i=0;i<n;i++){
		dis[i] = cost[start][i];
		pred[i] = start;
		visited[i] = 0;
	}
	dis[start]=0;
	visited[start]=1;
	count = 1;
	while(count < n-1){
		mindis = Infinity;
		for(i=0; i<n; i++){
			if(dis[i] < mindis &&! visited[i]){
				mindis = dis[i];
				nextnode = i;
			}
		}
			visited[nextnode] = 1;
			for(i=0; i<n; i++){
				if(mindis + cost[nextnode][i]< dis[i]){
					dis[i] = mindis + cost[nextnode][i];
					pred[i] = nextnode;
				}
				count++;
			}
			for(i=0; i<n; i++){
				if(i!= start){
					printf("\n Distance of node %d = %d",i,dis[i]);
					printf("\n Path = %d",i);
					j=1;
					do{
						j = pred[j];
						printf("<-%d",j);
					}while(j!=start);
				}
			}
		}
	}
	int key[100];

void bellmon(int G[Max][Max],int n,int s)
{
	int i,j,k;
	int count =0;
	for(i=0;i<n;i++)
		key[i]=Infinity;
	key[s]=0;
	for(k=0;k<n-1;k++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(G[i][j]!=0 && key[j]>key[i]+G[i][j]){
					key[j]=key[i]+G[i][j];
				}
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(G[i][j]!=0 && key[j]>key[i]+G[i][j]){
				key[j]=key[i]+G[i][j];
				count++;
			}
		}
	}
	if(count!=0)
		puts("Negative Cycle Found");
	else{
		for(i=0;i<n;i++)
			printf("%d\t%d\n",i,key[i]);
	}

}
//https://gist.github.com/PraSoonGosWami/c986eb382786be8fe1277078ae1f9086
//https://thecrazyprogrammer.com/2014/03/dijkstra-algorithm-for-finding-shortest-path-of-a-graph.html

