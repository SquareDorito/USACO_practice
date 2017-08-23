#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

FILE *fout = fopen("scramble.out","w");

int n;
char arr[65536][32];
vector<string> zs;
vector<string> ys;
char arr1[65536][32];
char arr2[65536][32];
int lowest[65536];
int highest[65536];

void input(){
	FILE *fp = fopen("scramble.in","r");
	fscanf(fp,"%d",&n);
	for(int i=0;i<n;i++){
		fscanf(fp,"%s",arr[i]);
		strcpy(arr1[i],arr[i]);
		sort(arr1[i],arr1[i]+strlen(arr1[i]));
		reverse_copy(arr1[i],arr1[i]+strlen(arr1[i]),arr2[i]);
		//fprintf(fout,"%s %s %s\n",arr1[i],arr[i],arr2[i]);
		zs.push_back(arr2[i]);
		ys.push_back(arr1[i]);
	}
	fclose(fp);
}

void process(){
	int flag=0;
	sort(zs.begin(),zs.end());
	sort(ys.begin(),ys.end());
	for(int i=0;i<n;i++){
		//fprintf(fout,"%s\n",ys[i].c_str());
	}
	for(int i=0;i<n;i++){
		int lp=0;
		int rp=n-1;
		//min
		while(lp<=rp){
			int mp=(lp+rp)/2;
			if(arr1[i]>zs[mp]){
				lp=mp+1;
			}
			else if(arr1[i]==zs[mp]){
				lowest[i]=mp+1;
				flag=1;
				break;
			}
			else{
				rp=mp-1;
			}
		}
		if(flag==0)
			lowest[i]=lp+1;
		flag=0;
		//max
		lp=0;
		rp=n-1;
		while(lp<=rp){
			int mp=(lp+rp)/2;
			if(arr2[i]>ys[mp]){
				lp=mp+1;
			}
			else if(arr2[i]==ys[mp]){
				highest[i]=mp+1;
				//fprintf(fout,"%d %d\n",i,highest[i]);
				flag=1;
				break;
			}
			else{
				rp=mp-1;
			}
		}
		if(flag==0)
			highest[i]=lp;
		flag=0;
		fprintf(fout,"%d %d\n",lowest[i],highest[i]);
	}
	fclose(fout);
}

int main(){
	input();
	process();
	return 0;
}