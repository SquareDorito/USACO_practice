/*
ID: kennoh4152
PROG: space3d
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

FILE *fout = fopen("space3d.out","w");

char map[128][128][128];
char marked[128][128][128];
char queue[1<<20][4];
int head,tail,answer,n;

void input(){
	FILE *fp = fopen("space3d.in","r");
	fscanf(fp,"%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			fscanf(fp,"%s",map[i][j]);
		}
	}
	fclose(fp);
}

void push(int tx,int ty,int tz){
	if(tx<0 || ty<0 || tz<0)
		return;
	if(tx>=n || ty>=n || tz>=n)
		return;
	if(marked[tx][ty][tz]==1)
		return;
	if(map[tx][ty][tz]!='*')
		return;
	queue[tail][0]=tx;
	queue[tail][1]=ty;
	queue[tail][2]=tz;
	marked[tx][ty][tz]=1;
	tail++;
}

void process(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(map[i][j][k]=='*'){
					if(marked[i][j][k]==0){
						push(i,j,k);
						while(head<tail){
							int x=queue[head][0];
							int y=queue[head][1];
							int z=queue[head][2];
							push(x+1,y,z);
							push(x-1,y,z);
							push(x,y+1,z);
							push(x,y-1,z);
							push(x,y,z+1);
							push(x,y,z-1);
							head++;
						}
						answer++;
					}
				}
			}
		}
	}
	//fprintf(fout,"%d\n",tail);
	fprintf(fout,"%d\n",answer);
	fclose(fout);
}

int main(){
	input();
	process();
	return 0;
}