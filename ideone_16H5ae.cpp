/*
ID: kennoh4152
PROG: satpix
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

FILE *fout = fopen("satpix.out","w");

int w,h;
char map[1024][128];
int queue[131072][2];
int head,tail;
int marked[1024][128];
int tempcount;

void input(){
	FILE *fp = fopen("satpix.in","r");
	fscanf(fp,"%d%d",&w,&h);
	for(int i=0;i<h;i++){
		fscanf(fp,"%s",map[i]);
	}
	fclose(fp);
}

void push(int x,int y){
	if(x<0 || y<0)
		return;
	if(x>=h || y>=w)
		return;
	if(marked[x][y]==1)
		return;
	if(map[x][y]!='*')
		return;
	queue[tail][0]=x;
	queue[tail][1]=y;
	marked[x][y]=1;
	tempcount++;
	tail++;
}

void process(){
	int max=0;
	for(int r=0;r<h;r++){
		for(int c=0;c<w;c++){
			if(map[r][c]=='*'){
				if(marked[r][c]==0){
					push(r,c);
					while(head<tail){
						int tempx=queue[head][0];
						int tempy=queue[head][1];
						push(tempx+1,tempy);
						push(tempx-1,tempy);
						push(tempx,tempy+1);
						push(tempx,tempy-1);
						head++;
					}
					if(tempcount>max){
						max=tempcount;
					}
					tempcount=0;
				}
			}
		}
	}
	/*for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			fprintf(fout,"%d",marked[i][j]);
		}
		fprintf(fout,"\n");
	}*/
	fprintf(fout,"%d\n",max);
	fclose(fout);
}

int main(){
	input();
	process();
	return 0;
}