#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

FILE *fout = fopen("gifts.out","w");

int n,b;
//int ps[1024][2];
vector<pair<int, pair<int, int> > > ps;

void input(){
	FILE *fp = fopen("gifts.in","r");
	fscanf(fp,"%d%d",&n,&b);
	for(int i=0;i<n;i++){
		int temp1,temp2;
		fscanf(fp,"%d%d",&temp1,&temp2);
		ps.push_back(make_pair(temp1+temp2,make_pair(temp1,temp2)));
	}
	fclose(fp);
	sort(ps.begin(),ps.end());
}

void process(){
	int max=0;
	int count=1;
	int spent=0;
	for(int i=0;i<n;i++){
		count=1;
		spent=0;
		spent=(ps[i].second.first/2)+ps[i].second.second;
		if(spent>=b){
			break;
		}
		for(int j=0;j<n;j++){
			if(i==j)
				continue;
			spent+=ps[j].first;
			if(spent>=b){
				break;
			}
			count++;
		}
		if(count>max)
			max=count;
	}
	fprintf(fout,"%d",max);
}

int main(){
	input();
	process();
	return 0;
}