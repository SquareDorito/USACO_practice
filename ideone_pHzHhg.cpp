/*
ID: kennoh4152
LANG: C++
PROG: pathfind
*/

#include <cstdio>
using namespace std;

FILE *fout = fopen("pathfind.out","w");

int m,n;
int C[128][128];
int queue[128];
int mark[128];
int numMoves[128];
int head,tail,count;

void input(){
	FILE *fp =fopen("pathfind.in","r");
	fscanf(fp,"%d%d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			fscanf(fp,"%d",&C[i][j]);
		} 
	}
	fclose(fp);
	m-=1;
	for(int i=0;i<n;i++){
		numMoves[i]=-1;
	}
}

void push(int x,int v){
	if(mark[x]==1)
		return;
	queue[tail]=x;
	numMoves[queue[tail]]=v;
	//fprintf(fout,"%d ",queue[tail]+1);
	mark[x]=1;
	tail++;
	count++;
}

void process(){
	numMoves[m]=0;
	push(m,0);
	//fprintf(fout,"\n");
	while(head<tail){
		for(int i=0;i<n;i++){
			if(C[queue[head]][i]==1){
				push(i,numMoves[queue[head]]+1);
			}
		}
		head++;
	}
	int flag=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(numMoves[j]==i){
				if(flag==0)
					fprintf(fout,"%d",j+1);
				else
					fprintf(fout," %d",j+1);
				flag=1;
			}
		}
		if(flag==1)
			fprintf(fout,"\n");
		flag=0;
	}
	fclose(fout);
}

int main(){
	input();
	process();
	return 0;
}