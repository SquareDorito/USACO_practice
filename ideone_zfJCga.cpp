#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

FILE *fout = fopen("perimeter.out","w");
int hay[16384][2];
int grid[128][128];
int n;

void input(){
	FILE *fp = fopen("perimeter.in","r");
	fscanf(fp,"%d\n",&n);
	for(int i=0;i<n;i++){
		int x,y;
		fscanf(fp,"%d%d",&x,&y);
		hay[i][0]=x-1;
		hay[i][1]=y-1;
		grid[x-1][y-1]=1;
	}
	fclose(fp);
}

void process(){
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			if(grid[i][j]==0){
				if(i+1<100 && j+1<100 && i-1>=0 && j-1>=0){
					if(grid[i+1][j]==1 && grid[i-1][j]==1 && grid[i][j+1]==1 && grid[i][j-1]==1){
						grid[i][j]=-1;
						//hole
					}
				}
			}
		}
	}
	int answer=0;
	for(int i=0;i<n;i++){
		int x=hay[i][0];
		int y=hay[i][1];
		if(grid[x+1][y]==0)
			answer++;
		if(grid[x][y+1]==0)
			answer++;
		if(x-1>=0){
			if(grid[x-1][y]==0)
				answer++;
		}
		if(y-1>=0){
			if(grid[x][y-1]==0)
				answer++;
		}
		if(y==0)
			answer++;
		if(x==0)
			answer++;
	}
	fprintf(fout,"%d\n",answer);
	fclose(fout);
}

int main(){
	input();
	process();
	return 0;
}