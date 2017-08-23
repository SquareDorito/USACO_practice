/*
ID: kennoh4152
PROG: space
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

FILE *fout = fopen("space.out","w");

int n;
char arr[1024][1024];
int marked[1024][1024];
int queue[1048576][2];
int head,tail;
int numislands;

void input(){
	FILE *fp = fopen("space.in","r");
	fscanf(fp,"%d",&n);
	for(int i=0;i<n;i++){
		fscanf(fp,"%s",arr[i]);
	}
	fclose(fp);
}

void push(int x, int y){
	if(x>=n || x<0 || y<0 || y>=n)
		return;
	if(arr[x][y]!='*')
		return;
	if(marked[x][y]!=0)
		return;
	queue[tail][0]=x;
	queue[tail][1]=y;
	marked[x][y]=1;
	tail++;
}

void process(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j]=='*' && marked[i][j]==0){
				push(i,j);
				while(head<tail){
					int x=queue[head][0];
					int y=queue[head][1];
					push(x+1,y);
					push(x-1,y);
					push(x,y+1);
					push(x,y-1);
					head++;
				}
				numislands++;
			}
		}
	}
	/*for(int i=0;i<n;i++){
		fprintf(fout,"%s\n",arr[i]);
	}*/
	fprintf(fout,"%d\n",numislands);
	fclose(fout);
}

int main(){
	input();
	process();
	return 0;
}