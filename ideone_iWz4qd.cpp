#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

FILE *fout = fopen("relay.out","w");

int n,answer;
int orig[1024];
//int temp[1024];
int marked[1024];

void input(){
	FILE *fp = fopen("relay.in","r");
	fscanf(fp,"%d",&n);
	for(int i=0;i<n;i++){
		int temp;
		fscanf(fp,"%d",&temp);
		orig[i]=temp;
	}
	fclose(fp);
}

void process(){
	int countround=0;
	for(int i=0;i<n;i++){
		if(orig[i]==0){
			marked[i]=-1;
			answer++;
			//fprintf(fout,"%d\n",i);
		}
	}
	while(true){
		for(int i=0;i<n;i++){
			if(marked[i]==0){
				if(marked[orig[i]-1]==-1){
					marked[i]=-1;
					answer++;
					countround++;
					//fprintf(fout,"%d\n",i);
				}
			}
		}
		if(countround==0)
			break;
		countround=0;
	}
	fprintf(fout,"%d\n",answer);
	fclose(fout);
}

int main(){
	input();
	process();
	return 0;
}