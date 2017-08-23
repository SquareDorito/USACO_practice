#include <cstdio>
using namespace std;

FILE *fout = fopen("moo.out","w");

int n;
char answer;

void input(){
	FILE *fp = fopen("moo.in","r");
	fscanf(fp,"%d",&n);
	fclose(fp);
}

int find_length(int k){
	if (k==-1){
		return 0;
	}
	int temp;
	temp=find_length(k-1);
	return (2*temp)+k+3;
}


void brute(int n, int x){
	if(n>find_length(x)){
		brute(n,x+1);
		return;
	}
	if(n<=find_length(x-1)){
		brute(n,x-1);
		return;
	}
	n-=find_length(x-1);
	if(n<=x+3){
		if(n==1)
			answer='m';
		else answer='o';
		return;
	}
	n-=(x+3);
	brute(n,x-1); 
	return;
}

void process(){
	brute(n,0);
	fprintf(fout,"%c\n",answer);
	fclose(fout);
}

int main(){
	input();
	process();
	return 0;
}