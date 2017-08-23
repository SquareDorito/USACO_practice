#include <cstdio>
#include <algorithm>
using namespace std;

FILE *fout = fopen("haywire.out","w");

int n;
int orig[16][4];
int marked[16];
int current[16];
int location[16];
int location2[16];
int answer=0;
int stuff[16];

void input(){
	FILE *fp = fopen("haywire.in","r");
	fscanf(fp,"%d",&n);
	for(int i=0;i<n;i++){
		fscanf(fp,"%d%d%d",&orig[i][0],&orig[i][1],&orig[i][2]);
		orig[i][0]-=1;
		orig[i][1]-=1;
		orig[i][2]-=1;
	}
	fclose(fp);
}

void helper(){
	int min1=9999999;
	int g1[16];
	int cost1=0;
	for(int i=0;i<(n/2);i++){
		g1[i]=current[i];
	}
	do{
		for(int i=0;i<n/2;i++){
			location[g1[i]]=i;
		}
		for(int i=0;i<(n/2);i++){
			int x=g1[i];
			//fprintf(fout,"%d\n",x);
			for(int j=0;j<3;j++){
				int y=orig[x][j];
				//fprintf(fout,"%d\n",y);
				if(marked[y]==1){
					cost1+=abs(location[x]-location[y]);
				}
				else{
					cost1+=abs((n-1)-2*(location[x]));
				}
			}
		}
		if(cost1<min1){
			min1=cost1;
			for(int i=0;i<3;i++){
				stuff[i]=g1[i];
			}
		}
		cost1=0;
	}while(next_permutation(g1,g1+(n/2)));



	int min2=9999999;
	int g2[16];
	int cost2=0;
	int counter=0;
	int x2=0;
	int y2=0;
	for(int i=0;i<n;i++){
		if(marked[i]==0){
			g2[counter]=i;
			counter++;
		}
	}
	//fprintf(fout,"%d\n",counter);
	do{
		for(int i=0;i<(n/2);i++){
			location2[g2[i]]=i;
		}
		for(int i=0;i<(n/2);i++){
			int x2=g2[i];
			for(int j=0;j<3;j++){
				int y=orig[x2][j];
				if(marked[y2]==1)
					cost2+=abs(location2[x2]-location2[y2]);
				else{
					cost2+=abs((n-1)-2*((n/2)-location2[x2]));
				}
			}
		}
		if(cost2<min2){
			min2=cost2;
			for(int i=0;i<3;i++){
				stuff[i+3]=g2[i];
			}
		}
		cost2=0;
	}while(next_permutation(g2,g2+(n/2)));
	//fprintf(fout,"%d %d\n",min1,min2);
	answer=min1+min2;
}

void brute(int x, int depth){
	if(depth==(n/2)-1){
		helper();
	}
	for(int i=x+1;i<n;i++){
		if(marked[i]==0){
			marked[i]=1;
			current[depth+1]=i;
			brute(i,depth+1);
			current[depth+1]=0;
			marked[i]=0;
		}
	}
}

void process(){
	for(int i=0;i<n;i++){
		marked[i]=1;
		current[0]=i;
		brute(i,0);
		current[0]=0;
		marked[i]=0;
	}
	fprintf(fout,"%d\n",answer/2);
	fclose(fout);
}

int main(){
	input();
	process();
	return 0;
}