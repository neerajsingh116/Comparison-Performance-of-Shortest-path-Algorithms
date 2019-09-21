#include<stdio.h>
#include<conio.h>
# define Infinity 9999
# define Max 10
void dijkastra(int G[Max][Max], int n , int start);
int main(){
	int G[Max][Max],i,j,n,u;
	printf("Enter number of vertices :");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&G[i][j]);
		}
	}
	printf("Enter the Starting Node (Number) :");
	scanf("%d",&u);
	dijkastra(G,n,u);
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
	//https://thecrazyprogrammer.com/2014/03/dijkstra-algorithm-for-finding-shortest-path-of-a-graph.html
