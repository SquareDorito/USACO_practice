#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

FILE *fout = fopen("proximity.out","w");

int n,k;
int orig[65536];
int marked[1048576];
int answer=-1;
int maxi;

/*int binsearch(int x){
	int left=0;
	int right=n-1;
	while(left<=right){
		int mid=(left+right)/2;
		if(x>orig[mid]){
			left=mid+1;
		}
		else if(x==orig[mid]){
			return mid;
		}
		else{
			right=mid-1;
		} 
	}
}*/

void input(){
	FILE *fp = fopen("proximity.in","r");
	fscanf(fp,"%d%d",&n,&k);
	for(int i=0;i<n;i++){
		fscanf(fp,"%d",&orig[i]);
		if(orig[i]>maxi)
			maxi=orig[i];
	}
	fclose(fp);
}

void process(){
	for (int i=0;i<n;i++){
		marked[orig[i]]++;
		if(k<i)
			marked[orig[i-k-1]]--;
		if(marked[orig[i]]>1){
			if(orig[i]>answer)
				answer=orig[i];
		}
	}
	/*int print=0;
	for(int i=0;i<n;i++){
		if(marked[orig[i]]==0)
			marked[orig[i]]=i;
		else{
			if(marked[orig[i]]-i>0)
				answer[orig[i]]=marked[orig[i]]-i;
			else answer[orig[i]]=i-marked[orig[i]];
		}
	}
	for(int i=maxi;i>=0;i--){
		if(answer[i]==0)
			continue;
		if(answer[i]<=k){
			print=i;
			break;
		}
	}
	if(print==0)
		fprintf(fout,"-1\n");
	else fprintf(fout,"%d\n",print);*/
	fprintf(fout,"%d\n",answer);
	fclose(fout);
}

int main(){
	input();
	process();
	return 0;
}