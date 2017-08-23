/*
ID: kennoh4152
PROG: dance2
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

FILE *fout = fopen("dance2.out","w");

int n;
int length[1024];
char arr[1024][1024];

void input(){
	FILE *fp = fopen("dance2.in","r");
	fscanf(fp,"%d",&n);
	for(int i=0;i<n;i++){
		fscanf(fp,"%d",&length[i]);
		fscanf(fp,"%s",arr[i]);
	}
	fclose(fp);
}

int find(int a){
	int x=0;
	for(int i=0;i<length[a];i++){
		if(arr[a][i]=='<')
			x--;
		if(arr[a][i]=='>')
			x++;
		if(x<0)
			return 1;
	}
	if(x==0)
		return 0;
	else return 1;
}

void process(){
	for(int i=0;i<n;i++){
		if(find(i)==0)
			fprintf(fout,"legal\n");
		else
			fprintf(fout,"illegal\n");
	}
	fclose(fout);
}

int main(){
	input();
	process();
	return 0;
}