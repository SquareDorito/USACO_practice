/*
ID: kennoh4152
PROG: spiral
LANG: C++
*/
#include <cstdio>
using namespace std;

FILE *fout = fopen("spiral.out","w");

int n;
int arr[1024][1024];
char dir;

void input(){
	FILE *fp = fopen("spiral.in","r");
	fscanf(fp,"%d",&n);
	fclose(fp);
}

void process(){
	dir='R';
	int x=0;
	int y=0;
	int count=1;
	while(count<=n*n){
		arr[x][y]=count;
		if(dir=='R'){
			if(y+1>=n || arr[x][y+1]!=0){
				dir='D';
				x++;
				count++;
			}
			else{
				count++;
				y++;
			}
		}
		else if(dir=='D'){
			if(x+1>=n || arr[x+1][y]!=0){
				dir='L';
				y--;
				count++;
			}
			else{
				count++;
				x++;
			}	
		}
		else if(dir=='L'){
			if(y-1<0 || arr[x][y-1]!=0){
				dir='U';
				x--;
				count++;
			}
			else{
				count++;
				y--;
			}	
		}
		else if(dir=='U'){
			if(x-1<0 || arr[x-1][y]!=0){
				dir='R';
				y++;
				count++;
			}
			else{
				count++;
				x--;
			}	
		}
	}
	int flag=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(flag==0)
				fprintf(fout,"%d",arr[i][j]);
			else fprintf(fout," %d",arr[i][j]);
			flag=1;
		}
		fprintf(fout,"\n");
		flag=0;
	}
	fclose(fout);
}

int main(){
	input();
	process();
	return 0;
}