#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

FILE *fout = fopen("3lines.out","w");

vector<pair<int,int>> arr;
map<int, int> marked;
int counter;
int n;

void input(){
	FILE *fp = fopen("3lines.in","r");
	fscanf(fp,"%d",&n);
	for(int i=0;i<n;i++) {
		int x,y;
		fscanf(fp,"%d%d", &x,&y);
		arr.push_back(make_pair(x,y));
	}
}

int process() {
	sort(arr.begin(),arr.end());
	counter=0;	
	marked.clear();
	for(int i=0;i<n;i++) {
		if(marked[arr[i].second]==0)
			counter++;
		marked[arr[i].second]++;
	}
	if(counter<=3) 
		return 1;
	int i=0;
	int j=0;
	while(i<n){
		while(j<n && arr[i].first==arr[j].first){
			j++;
		}
		for(int k=i;k<j;k++){
			marked[arr[k].second]-=1;
			if(marked[arr[k].second]==0)
				counter--;
		}
		if(counter<=2)
			return 1;
		for(int k=i;k<j;k++){
			if(marked[arr[k].second]==0)
				counter++;
			marked[arr[k].second]++;
		}
		i=j;
	}
	return 0;
}

int main() {
	input();
	if(process()==1)
		fprintf(fout,"1\n");
	else{
		for(int i=0;i<n;i++) {
			swap(arr[i].first,arr[i].second);
		}
		if(process()==1)
			fprintf(fout,"1\n");
		else fprintf(fout,"0\n");
	}
	fclose(fout);
	return 0;
}