#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

FILE *fout = fopen("cowfind.out","w");

char grass[65536];
int bbcount[65536];
int n;

void input(){
	FILE *fp = fopen("cowfind.in","r");
	fscanf(fp,"%s",grass);
	n=strlen(grass);
	fclose(fp);
}

void process(){
	int count=0;
	int answer=0;
	for(int i=n-2;i>=0;i--){
		if(grass[i]==')' && grass[i+1]==')'){
			count++;
		}
		bbcount[i]=count;
	}
	for(int i=0;i<n-2;i++){
		if(grass[i]=='(' && grass[i+1]=='('){
			answer+=bbcount[i+2];
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