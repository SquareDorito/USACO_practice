#include <cstdio>
using namespace std;

FILE *fout = fopen("grazing.out","w");

int k;
int coor[32][2];
int grid[8][8];
//int marked[8][8];
int answer;

void input(){
	FILE *fp = fopen("grazing.in","r");
	fscanf(fp,"%d",&k);
	for(int i=0;i<k;i++){
		int x,y;
		fscanf(fp,"%d%d",&x,&y);
		grid[x-1][y-1]=-1;
	}
	/*for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			fprintf(fout,"%2d",grid[i][j]);
		}
		fprintf(fout,"\n");
	}*/
	fclose(fp);
}

void brute(int depth,int x,int y){
	if(x>4 || x<0)
		return;
	if(y>4 || y<0)
		return;
	if(grid[x][y]!=0)
		return;
	depth++;
	//fprintf(fout,"%d\n",depth);
	if(depth==25 && x==4 && y==4){
		//fprintf(fout,"hi\n");
		answer++;
		return;
	}
	grid[x][y]=1;
	brute(depth,x-1,y);
	brute(depth,x+1,y);
	brute(depth,x,y-1);
	brute(depth,x,y+1);
	depth--;
	grid[x][y]=0;
	return;
}

void process(){
	brute(k,0,0);
	fprintf(fout,"%d\n",answer);
	fclose(fout);
}

int main(){
	input();
	process();
	return 0;
}