/*
ID: kennoh4152
PROG: cropcir
LANG: C++
*/
#include <cstdio>
#include <cmath>
#include <math.h>
using namespace std;

FILE *fout = fopen("cropcir.out","w");

int n;
int xcor[16384];
int ycor[16384];
int radius[512];

void input(){
	FILE *fp = fopen("cropcir.in","r");
	fscanf(fp,"%d",&n);
	for(int i=0;i<n;i++){
		fscanf(fp,"%d%d%d",&xcor[i],&ycor[i],&radius[i]);
	}
	fclose(fp);
}

void process(){
	int count=0;
	int tempx,tempy;
	double tempdist=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j)
				continue;
			tempx=xcor[i]-xcor[j];
			tempy=ycor[i]-ycor[j];
			tempdist=sqrt((double)(tempx*tempx)+(double)(tempy*tempy));
			if(radius[i]+radius[j]>=tempdist)
				count++;
		}
		fprintf(fout,"%d\n",count);
		count=0;
	}
	fclose(fout);
}

int main(){
	input();
	process();
	return 0;
}