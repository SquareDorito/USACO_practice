#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

FILE *fout = fopen("hshoe.out","w");

int n;
char map[8][8];
int maxi;
char queue[32];
int marked[8][8];

void input(){
	FILE *fp = fopen("hshoe.in","r");
	fscanf(fp,"%d",&n);
	for(int i=0;i<n;i++){
		fscanf(fp,"%s",map[i]);
	}
	/*for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			fprintf(fout,"%c",map[i][j]);
		}
		fprintf(fout,"\n");
	}*/
	fclose(fp);
}

int legit(char arr[]){
	int templ=strlen(arr);
	if(templ%2==1)
		return 0;
	int temp1=0;
	for(int i=0;i<templ;i++){
		if(i==(templ/2)){
			if(temp1!=templ/2)
				return 0;
		}
		if(arr[i]=='('){
			temp1++;
		}
		else if(arr[i]==')'){
			temp1--;
		}
	}
	if(temp1==0)
		return 1;
	else return 0;
}

void dfs(int x,int y,int depth){
	//fprintf(fout,"%d %d\n",x,y);
	queue[depth]=map[x][y];
	marked[x][y]=1;
	if(legit(queue)==1){
		//fprintf(fout,"%s\n",queue);
		if(depth+1>maxi){
			maxi=depth+1;
		}
	}
	if(x-1>=0 && marked[x-1][y]==0){
		dfs(x-1,y,depth+1);
		queue[depth+1]=0;
		marked[x-1][y]=0;
	}
	if(x+1<n && marked[x+1][y]==0){
		dfs(x+1,y,depth+1);
		queue[depth+1]=0;
		marked[x+1][y]=0;
	}
	if(y-1>=0 && marked[x][y-1]==0){
		dfs(x,y-1,depth+1);
		queue[depth+1]=0;
		marked[x][y-1]=0;
	}
	if(y+1<n && marked[x][y+1]==0){
		dfs(x,y+1,depth+1);
		queue[depth+1]=0;
		marked[x][y+1]=0;
	}
	return;
}

void process(){
	dfs(0,0,0);
	fprintf(fout,"%d\n",maxi);
	fclose(fout);
}

int main(){
	input();
	process();
	return 0;
}