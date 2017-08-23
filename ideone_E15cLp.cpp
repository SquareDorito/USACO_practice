#include <cstdio>
using namespace std;

int n,m,k; //nxk,k flooded
int map[128][128];
int marked[128][128];
int queue[16384][2];
int head,tail;
int tempcount;

void input(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<k;i++){
		int r,c;
		scanf("%d%d",&r,&c);
		map[r-1][c-1]=1;
	}
	/*for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%d",map[i][j]);
		}
		printf("\n");
	}*/
}

void push(int x,int y){
	if(x>=n || y>=m)
		return;
	if(x<0 || y<0)
		return;
	if(marked[x][y]==1)
		return;
	if(map[x][y]!=1)
		return;
	marked[x][y]=1;
	queue[tail][0]=x;
	queue[tail][1]=y;
	tempcount++;
	tail++;
}

void process(){
	int max=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(map[i][j]==1){
				if(marked[i][j]==0){
					push(i,j);
					while(head<tail){
						int r=queue[head][0];
						int c=queue[head][1];
						push(r+1,c);
						push(r-1,c);
						push(r,c+1);
						push(r,c-1);
						head++;
					}
					if(tempcount>max)
						max=tempcount;
					tempcount=0;
				}
			}
		}
	}
	printf("%d\n",max);
}

int main(){
	//freopen("rain.in","r",stdin);
	//freopen("rain.out","w",stdout);
	input();
	process();
	return 0;
}