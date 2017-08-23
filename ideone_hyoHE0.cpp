/*
ID: kennoh4152
PROG: numgrid
LANG: C++
*/
#include <cstdio>
using namespace std;

FILE *fout = fopen("numgrid.out","w");

int grid[8][8];
int marked[1048576];
int temp[8];
int answer;

void input(){
	FILE *fp = fopen("numgrid.in","r");
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			fscanf(fp,"%d",&grid[i][j]);
		}
	}
	fclose(fp);
}

void dfs(int x, int y, int depth){
	if(depth==6){
		int tempnumber=temp[0]*100000+temp[1]*10000+temp[2]*1000+temp[3]*100+temp[4]*10+temp[5];
			if(marked[tempnumber]==0){
				marked[tempnumber]++;
				answer++;
				//fprintf(fout,"%d\n",tempnumber);
				tempnumber=0;
			}
		return;
	}
	temp[depth]=grid[x][y];
	if(x+1<5){
		dfs(x+1,y,depth+1);
		temp[depth+1]=0;
	}
	if(x-1>=0){
		dfs(x-1,y,depth+1);
		temp[depth+1]=0;
	}
	if(y+1<5){
		dfs(x,y+1,depth+1);
		temp[depth+1]=0;
	}
	if(y-1>=0){
		dfs(x,y-1,depth+1);
		temp[depth+1]=0;
	}
}

void process(){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			dfs(i,j,0);
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