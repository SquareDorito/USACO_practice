#include <cstdio>
#include <vector>
using namespace std;

int n,m;
vector <int> nei[32768];
int queue[32768];
int marked[32768];
int head,tail;
int length,answer,count;

void input(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int temp1,temp2;
		scanf("%d%d",&temp1,&temp2);
		temp1-=1;
		temp2-=1;
		nei[temp1].push_back(temp2);
		nei[temp2].push_back(temp1);
	}
}

void push(int x, int depth){
	if(marked[x]>0)
		return;
	queue[tail]=x;
	marked[x]=depth;
	if(depth>length){
		length=depth;
		answer=x;
		count=1;
	}
	else if(depth==length){
		if(x<answer)
			answer=x;
		count++;
	}
	tail++;
}

void process(){
	push(0,1);
	while(head<tail){
		int y=queue[head];
		for(int i=0;i<nei[y].size();i++){
			push(nei[y][i],marked[y]+1);
		}
		head++;
	}
	/*for(int i=0;i<n;i++){
		printf("%d: ",nei[i].size());
		for(int j=0;j<nei[i].size();j++){
			printf("%d ",nei[i][j]);
		}
		printf("\n");
	}*/
	printf("%d %d %d",answer+1,length-1,count);
}

int main(){
	//freopen("has.in","r",stdin);
	//freopen("has.out","w",stdout);
	input();
	process();
	return 0;
}