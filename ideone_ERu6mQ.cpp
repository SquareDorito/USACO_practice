/*
ID: kennoh4152
PROG: ssort
LANG: C++
*/

#include <cstdio>
using namespace std;

FILE *fout = fopen("ssort.out","w");

int n;
int arr[1024];
int temp[1024];
int answer;

void input(){
	FILE *fp = fopen("ssort.in","r");
	fscanf(fp,"%d",&n);
	for(int i=0;i<1<<n;i++){
		fscanf(fp,"%d",&arr[i]);
	}
	fclose(fp);
}

void process(){	
	for(int i=0;i<n;i++){ //distance factor
		for(int j=0;j<(1<<n);j=(1<<(i+1))+j){ //array index
			//fprintf(fout,"%d %d\n",j,j+(1<<i));
			if(arr[j]>arr[j+(1<<i)]){
				//fprintf(fout,"%d %d\n",j,j+(1<<i));
				for(int k=j;k<j+(1<<(i+1));k++){
					if(k<j+1<<i){
						temp[k]=arr[k+(1<<i)];
					}
					if(k>=j+(1<<i)){
						temp[k]=arr[k-(1<<i)];
					}
				}
				for(int k=j;k<j+(1<<(i+1));k++){
					arr[k]=temp[k];
				}
			}
		}
	}
	for(int i=0;i<1<<n;i++){
		fprintf(fout,"%d\n",arr[i]);
	}
}

int main(){
	input();
	process();
	return 0;
}