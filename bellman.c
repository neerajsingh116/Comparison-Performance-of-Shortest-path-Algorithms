#include <stdio.h>
#include <string.h>
#include <time.h>
#define Max 100

int key[100];

void bellmon(int G[Max][Max],int n,int s)
{
	int i,j,k;
	int count =0;
	for(i=0;i<n;i++)
		key[i]=9999;
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

int main()
{
	int G[Max][Max],i,j,n,u;
	printf("Enter number of vertices :");
	scanf("%d",&n);
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			scanf("%d",&G[i][j]);
		}
	}
	printf("Enter the Starting Node (Number) :");
	scanf("%d",&u);
	clock_t start,stop;
	start = clock();
	bellmon(G,n,u);
	stop = clock();
	double runtime_bellman= ((double) stop - start)/ CLOCKS_PER_SEC;
	printf("\ncompilation time of bellman is : %f",runtime_bellman);
	return 0;

}

