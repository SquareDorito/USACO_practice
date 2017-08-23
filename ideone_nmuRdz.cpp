#include <cstdio>
#include <algorithm>
using namespace std;

FILE *fout = fopen("castle.out","w");

int m,n;
int wall[64][64];
int head,tail;
int queue[2048][2];
int marked[64][64];
int temp,answer,roomcount;

void input(){
	FILE *fp = fopen("castle.in","r");
	fscanf(fp,"%d%d",&m,&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			fscanf(fp,"%d",&wall[i][j]);
		}
	}
	roomcount=0;
	/*for(int i=0;i<n;i++){ 
		for(int j=0;j<m;j++){
			fprintf(fout,"%3d",wall[i][j]);
		}
		fprintf(fout,"\n");
	}*/
	//fprintf(fout,"%d\n",marked[0][0]);
	fclose(fp);
}

void push(int x,int y,int dir){
	//fprintf(fout,"%d,%d: %d\n",x,y,dir);
	if(x<0 || y<0 || x>=n || y>=m)
		return;
	if(marked[x][y]!=0)
		return;
	if(dir==1){
		//right
		if(wall[x][y]==1 
			|| wall[x][y]==3 
			|| wall[x][y]==5 
			|| wall[x][y]==9 
			|| wall[x][y]==7 
			|| wall[x][y]==11 
			|| wall[x][y]==13 
			|| wall[x][y]==15)
			return;
	}
	if(dir==2){
		//down
		if(wall[x][y]==2 
			|| wall[x][y]==3 
			|| wall[x][y]==6 
			|| wall[x][y]==10 
			|| wall[x][y]==7 
			|| wall[x][y]==14 
			|| wall[x][y]==11 
			|| wall[x][y]==15)
			return;
	}
	if(dir==3){
		//left
		if(wall[x][y]==4 
			|| wall[x][y]==5 
			|| wall[x][y]==6 
			|| wall[x][y]==12 
			|| wall[x][y]==7 
			|| wall[x][y]==13 
			|| wall[x][y]==14 
			|| wall[x][y]==15)
			return;
	}
	if(dir==4){
		//up
		if(wall[x][y]==8 
			|| wall[x][y]==9 
			|| wall[x][y]==10 
			|| wall[x][y]==12 
			|| wall[x][y]==13 
			|| wall[x][y]==14 
			|| wall[x][y]==11 
			|| wall[x][y]==15)
			return;
	}
	queue[tail][0]=x;
	queue[tail][1]=y;
	marked[x][y]=1;
	tail++;
	temp++;
}

void process(){
	fprintf(fout,"%d\n",marked[0][0]);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(marked[i][j]==0){
				//fprintf(fout,"%d %d\n",i,j);
				push(i,j,-1);
				roomcount++;
				while(head<tail){
					int xx=queue[head][0];
					int yy=queue[head][1];
					push(xx,yy+1,1);
					push(xx+1,yy,2);
					push(xx,yy-1,3);
					push(xx-1,yy,4);
					head++;
				}
				//fprintf(fout,"%d\n",temp);
				if(temp>answer)
					answer=temp;
				temp=0;
			}
		}
	}
	//fprintf(fout,"%d\n",marked[0][0]);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			fprintf(fout," %d",marked[i][j]);
		}
		fprintf(fout,"\n");
	}
	fprintf(fout,"%d\n",roomcount);
	fprintf(fout,"%d\n",answer);
	fclose(fout);
}

int main(){
	input();
	process();
	return 0;
}