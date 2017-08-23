#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

FILE *fout = fopen("planting.out","w");

int map[128][128];
int marked[128][128];
int queue[1024][2];
int head,tail;
int n;
int answer;

void input(){
	FILE *fp = fopen("planting.in","r");
	fscanf(fp,"%d",&n);
	for(int i=0;i<n;i++){
		int x1,x2,y1,y2;
		fscanf(fp,"%d%d%d%d",&x1,&y1,&x2,&y2);
		for(int j=x1;j<x2;j++){
			for(int k=y2;k<y1;k++){
				map[j][k]=1;
			}
		}
	}
	/*for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			fprintf(fout,"%d",map[i][j]);
		}
		fprintf(fout,"\n");
	}*/
	fclose(fp);
}

void push(int x,int y){
	if(x<0 || y<0 || x>100 || y>100)
		return;
	if(map[x][y]!=1)
		return;
	if(marked[x][y]==1)
		return;
	marked[x][y]=1;
	queue[tail][0]=x;
	queue[tail][1]=y;
	tail++;
	answer++;
}

void process(){
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			if(map[i][j]==1 && marked[i][j]==0){
				push(i,j);
				while(head<tail){
					int x=queue[head][0];
					int y=queue[head][1];
					push(x+1,y);
					push(x-1,y);
					push(x,y+1);
					push(x,y-1);
					head++;
				}
			}
		}
	}
	fprintf(fout,"%d\n",answer);
	fclose(fout);
}

int main(){
	input();
	process();
	return 0;
}