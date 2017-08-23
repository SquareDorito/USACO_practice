#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

FILE *fout = fopen("mirrors.out","w");
int n,a,b,flag;
set<int> orgx;
set<int> orgy;
int origx[256];
int origy[256];
map<int,int> xmap,ymap;
char origdir[256];
int counter1,counter2;
int sortedx[256];
int sortedy[256];
char grid[256][256];
int marked[256][256][4];

void input(){
	FILE *fp = fopen("mirrors.in","r");
	fscanf(fp,"%d%d%d",&n,&a,&b);
	for(int i=0;i<n;i++){
		int temp1,temp2;
		char temp3;
		fscanf(fp,"%d %d %c",&temp1,&temp2,&temp3);
		origx[i]=temp1;
		origy[i]=temp2;
		orgx.insert(temp1);
		orgy.insert(temp2);
		origdir[i]=temp3;
	}
	orgx.insert(0);
	orgy.insert(0);
	orgx.insert(a);
	orgy.insert(b);
	counter1=orgx.size();
	counter2=orgy.size();
	int tempx=0;
	for(set<int>::iterator it=orgx.begin();it!=orgx.end();it++){
		xmap[*it]=tempx;
		sortedx[tempx++]=*it;
	}
	tempx=0;
	for(set<int>::iterator it=orgy.begin();it!=orgy.end();it++){
		ymap[*it]=tempx;
		sortedy[tempx++]=*it;
	}
	for(int i=0;i<n;i++){
		//fprintf(fout,"%d %d %c\n",xmap[origx[i]],ymap[origy[i]],origdir[i]);
		grid[xmap[origx[i]]][ymap[origy[i]]]=origdir[i];
	}
	grid[xmap[a]][ymap[b]]='/';
	fclose(fp);
	//printf("input cool");
}

void brute(int x,int y,int dir){
	static int count = 0;
	count++;
	if(marked[x][y][dir]==1)
		return;
	marked[x][y][dir]=1;
	//printf("%d %d %d %d\n",count, x,y,dir);
	if(x==xmap[a] && y==ymap[b]){
		flag=1;
		marked[x][y][dir]=0;
		return;
	}
	if(dir==0){ //right
		for(int i=x+1;i<counter1;i++){
			if(grid[i][y]=='\\'){
				dir=3;
				brute(i,y,dir);
				marked[x][y][dir]=0;
				return;
			}
			if(grid[i][y]=='/'){
				dir=1;
				brute(i,y,dir);
				marked[x][y][dir]=0;
				return;
			}
		}
	}
	else if(dir==1){ //up
		for(int i=y+1;i<counter2;i++){
			if(grid[x][i]=='\\'){
				dir=2;
				brute(x,i,dir);
				marked[x][y][dir]=0;
				return;
			}
			if(grid[x][i]=='/'){
				dir=0;
				brute(x,i,dir);
				marked[x][y][dir]=0;
				return;
			}
		}
	}
	else if(dir==2){ //left
		for(int i=x-1;i>=0;i--){
			if(grid[i][y]=='\\'){
				dir=1;
				brute(i,y,dir);
				marked[x][y][dir]=0;
				return;
			}
			if(grid[i][y]=='/'){
				dir=3;
				brute(i,y,dir);
				marked[x][y][dir]=0;
				return;
			}
		}
	}
	else if(dir==3){ //down
		for(int i=y-1;i>=0;i--){
			if(grid[x][i]=='\\'){
				dir=0;
				brute(x,i,dir);
				marked[x][y][dir]=0;
				return;
			}
			if(grid[x][i]=='/'){
				dir=2;
				brute(x,i,dir);
				marked[x][y][dir]=0;
				return;
			}
		}
	}
	marked[x][y][dir]=0;
}

void process(){
	//printf("proc beg");
	memset(marked,0,sizeof(marked));
	brute(xmap[0],ymap[0],0);
	//problem line ^^
	if(flag==1){
		fprintf(fout,"0\n");
	}
	else{
		for(int i=0;i<n;i++){
			//printf("%d\n",i);
			if(grid[xmap[origx[i]]][ymap[origy[i]]]=='/'){
				grid[xmap[origx[i]]][ymap[origy[i]]]='\\';
			}
			else grid[xmap[origx[i]]][ymap[origy[i]]]='/';
			//printf("\n");
			memset(marked,0,sizeof(marked));
			brute(xmap[0],ymap[0],0);
			if(flag==1){
				fprintf(fout,"%d\n",i+1);
				break;
			}
			if(grid[xmap[origx[i]]][ymap[origy[i]]]=='/'){
				grid[xmap[origx[i]]][ymap[origy[i]]]=92;
			}
			else grid[xmap[origx[i]]][ymap[origy[i]]]='/';
		}

	}
	if(flag==0){
		fprintf(fout,"-1\n");
	}
	fclose(fout);
}

int main(){
	input();
	process();
//	while(true);
	return 0;
}