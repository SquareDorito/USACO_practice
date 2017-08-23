#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

FILE *fout = fopen("folding.out","w");

int n,l;
int knots[128];
int diff[128];
int answer;
int counter;

void input(){
	FILE *fp = fopen("folding.in","r");
	fscanf(fp,"%d%d",&n,&l);
	for(int i=0;i<n;i++){
		fscanf(fp,"%d",&knots[i]);
	}
	fclose(fp);
	sort(knots,knots+n);
}

int valid(int head,int tail){
	if(head==0){
		for(int i=0;i<=tail;i++){
			if(diff[i]!=diff[tail-i]){
				return 0;
			}
		}
		return 1;
	}
	else {
		for(int i=counter-1;i>=head;i--){
			int x=head-i+counter-1;
			//fprintf(fout,"%d %d\n",i,x);
			if(diff[i]!=diff[x]){
				return 0;
			}
		}
		return 1;
	}
}

void process(){
	int flag=0;
	for(int i=0;i<n-1;i++){
		diff[counter]=knots[i+1]-knots[i];
		//fprintf(fout,"%d ",diff[counter]);
		counter++;
	}
	if(counter==1){
		fprintf(fout,"1\n");
		return;
	}
	answer=0;
	for(int i=0;i<counter;i++){
		if(valid(0,i)==1){
			answer++;
			//fprintf(fout,"R %d\n",i);
			if(i==counter-1){
				flag++;
			}
		}
	}
	for(int i=counter-1;i>=0;i--){
		if(valid(i,counter-1)==1){	
			answer++;
			//fprintf(fout,"L %d\n",i);
			if(i==0){
				flag++;
			}
		}
	}
	if(flag==2){
		fprintf(fout,"%d\n",answer-1);
	}
	else fprintf(fout,"%d\n",answer);
	fclose(fout);
}

int main(){
	input();
	process();
	return 0;
}
  