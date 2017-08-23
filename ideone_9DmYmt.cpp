/*
ID: kennoh4152
LANG: C++
PROG: acrobat
*/

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

FILE *fout = fopen("acrobat.out","w");

int n;
/*int w[16384];
int s[16384];
int markedw[16384];*/
int total,maxrisk;
vector< pair <int,int> > cowstack;

void input(){
	FILE *fp = fopen("acrobat.in","r");
	fscanf(fp,"%d",&n);
	for(int i=0;i<n;i++){
		int tempw,temps;
		fscanf(fp,"%d%d",&tempw,&temps);
		cowstack.push_back(make_pair(tempw+temps,tempw));
		/*s[i]=tempw+temps;
		w[i]=tempw;
		markedw[s[i]]=tempw;*/
		total+=tempw;
	}
	//sort(s,s+n);
	sort(cowstack.begin(),cowstack.end());
	fclose(fp);
}

void process(){
	maxrisk=-99999999999;
	int tempmax;
	int temp;
	for(int i=n-1;i>=0;i--){
		tempmax=total-cowstack[i].first;
		if(tempmax>maxrisk){
			maxrisk=tempmax;
		}
		total-=cowstack[i].second;
	}
	fprintf(fout,"%d\n",maxrisk);
}

int main(){
	input();
	process();
	return 0;
}