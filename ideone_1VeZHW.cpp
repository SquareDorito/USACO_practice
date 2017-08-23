#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
using namespace std;

FILE *fout = fopen("crazy.out","w");

int n,c;
int cows[512][2]; 
int walls[512][4];
set<int> orgx;
set<int> orgy;
map<int,int> xmap,ymap;
int sortedx[2048];
int sortedy[2048];
char mapp[2048][2048]; // 4MB
char wallmap[2048][2048]; //4MB
int head,tail;
int temp;
int hello;
bool marking[2048][2048]; //4MB
int queue[1<<22][2]; //8MB
int counter1,counter2;

void input(){
	FILE *fp = fopen("crazy.in","r");
	fscanf(fp,"%d%d",&n,&c);
	for(int i=0;i<n;i++){
		fscanf(fp,"%d%d%d%d",&walls[i][0],&walls[i][1],&walls[i][2],&walls[i][3]);
	}
	for(int i=0;i<c;i++){
		fscanf(fp,"%d%d",&cows[i][0],&cows[i][1]);
	}
	for(int i=0;i<n;i++){
		int x1=walls[i][0];
		int x2=walls[i][2];
		orgx.insert(x1);
		orgx.insert(x2);
	}
	orgx.insert(-1);
	orgx.insert(1000001);
	orgy.insert(-1);
	orgy.insert(1000001);
	for(int i=0;i<c;i++){
		int x=cows[i][0];
		orgx.insert(x);
	}
	for(int i=0;i<n;i++){
		int y1=walls[i][1];
		int y2=walls[i][3];
		orgy.insert(y1);
		orgy.insert(y2);
	}
	for(int i=0;i<c;i++){
		int y=cows[i][1];
		orgy.insert(y);
	}
	counter1=orgx.size();
	counter2=orgy.size();
	int tempx=0;
	for(set<int>::iterator it=orgx.begin();it!=orgx.end();it++){
		xmap[*it]=tempx;
		sortedx[tempx++]=*it;
	}
	for(int i=0;i<counter1;i++){
		fprintf(fout,"%d ",sortedx[i]);
	}
	tempx=0;
	for(set<int>::iterator it=orgy.begin();it!=orgy.end();it++){
		ymap[*it]=tempx;
		sortedy[tempx++]=*it;
	}
	for(int i=0;i<n;i++){
		//set<int>::iterator it=orgx.find(walls[i][0]);
		walls[i][0]=xmap[walls[i][0]];
		walls[i][2]=xmap[walls[i][2]];
		walls[i][1]=ymap[walls[i][1]];
		walls[i][3]=ymap[walls[i][3]];
	}
	for(int i=0;i<c;i++){
		cows[i][0]=xmap[cows[i][0]];
		cows[i][1]=ymap[cows[i][1]];
		mapp[cows[i][0]][cows[i][1]]=5;
	}
	fclose(fp);
	
	//printf("end of input\n");
}

void push(int a,int b,int dir){
	if(a>counter1-1 || b>counter2-1 || a<0 || b<0)
		return;
	if(marking[a][b]==1)
		return;
	if(dir==2){ //right
		if((wallmap[a][b] & 1)==1)
			return;
	}
	if(dir==1){ //down
		if((wallmap[a][b] & 2)==2)
			return;
	}
	if(dir==4){ //left
		if((wallmap[a][b] & 4)==4)
			return;
	}
	if(dir==3){ //up
		if((wallmap[a][b] & 8)==8)
			return;
	}
	queue[tail][0]=a;
	queue[tail][1]=b;
	marking[a][b]=1;
	if(mapp[a][b]==5){
		temp=temp+1;
	}
	tail++;
}

void process(){
	//printf("begin of process\n");
	for(int i=0;i<n;i++){
		if(walls[i][0]==walls[i][2]){
			//vertical wall (horizontal when printed)
			int miny=min(walls[i][1],walls[i][3]);
			int maxy=max(walls[i][1],walls[i][3]);
			for(int j=miny;j<maxy;j++){
				wallmap[walls[i][0]][j]+=2;
				if(walls[i][0]-1>=0){
					wallmap[walls[i][0]-1][j]+=8;
				}
			}
		}
		else{
			int maxx=max(walls[i][0],walls[i][2]);
			int minx=min(walls[i][0],walls[i][2]);
			for(int j=minx;j<maxx;j++){
				wallmap[j][walls[i][1]]+=1;
				if(walls[i][1]-1>=0){
					wallmap[j][walls[i][1]-1]+=4;
				}
			}
		}
	}
	temp=0;
	for(int i=0;i<c;i++){

		if(marking[cows[i][0]][cows[i][1]]==0){
			head=0;
			tail=0;
			push(cows[i][0],cows[i][1],0);
			while(head<tail){
				int x=queue[head][0];
				int y=queue[head][1];
				push(x+1,y,1);
				push(x,y+1,2);
				push(x-1,y,3);
				push(x,y-1,4);
				head++;
			}
			//fprintf(fout,"%d %d %d %d %d\n",i,cows[i][0],cows[i][1],temp,hello);
			//fflush(stdout);
			if(temp>hello){
				hello=temp;
			}
			temp=0;
		}
	}
	fprintf(fout,"%d\n",hello);
	fclose(fout);
}

int main(){
	input();
	process();
	//printf("very end\n");
	return 0;
}