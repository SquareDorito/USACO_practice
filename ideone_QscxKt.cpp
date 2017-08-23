#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

FILE *fout = fopen("truth.out","w");

int n,m,answer;
int orig[16384][4];
int flag,flag2;
int multi=1;
int marked[1024];
vector<pair<int,int> > arr[1024];

void input(){
	FILE *fp = fopen("truth.in","r");
	fscanf(fp,"%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int x,y;
		char temp;
		fscanf(fp,"%d %d %c",&x,&y,&temp);
		orig[i][0]=x;
		orig[i][1]=y;
		orig[i][2]=temp;
		if(temp=='L'){
			orig[i][3]=-1;
		}
		else{
			orig[i][3]=1;
		}
	}
	fclose(fp);
}

void brute(int x,int line){
	fprintf(fout,"%d %d %d\n",x,line,multi);
	if(marked[x]==1)
		return;
	if(x==orig[line][1]){
		flag2=1;
		if(orig[line][2]=='L'){
			if(multi>0){
				flag=1;
				return;
			}
		}
		else{
			if(multi<0){
				flag=1;
				return;
			}
		}
		return;
	}
	marked[x]=1;
	for(int i=0;i<arr[x].size();i++){
		multi*=arr[x][i].second;
		//printf("%d %d\n",x,arr[x][i].first);
		brute(arr[x][i].first,line);
		multi*=orig[i][3];
		marked[x]=0;
	}
	marked[x]=0;
}

void process(){
	for(int i=0;i<m;i++){
		multi*=orig[i][3];
		//marked[orig[i][0]]=1;
		brute(orig[i][0],i);
		marked[orig[i][0]]=0;
		multi*=orig[i][3];
		if(flag==1){
			answer=i;
			break;
		}
		if(orig[i][2]=='L'){
			arr[orig[i][0]].push_back(make_pair(orig[i][1],-1));
			arr[orig[i][1]].push_back(make_pair(orig[i][0],-1));
			orig[i][3]=-1;
		}
		else{
			arr[orig[i][0]].push_back(make_pair(orig[i][1],1));
			arr[orig[i][1]].push_back(make_pair(orig[i][0],1));
			orig[i][3]=1;
		}
		multi=1;
		//flag2=0;
	}
	if(flag==0)
		answer=m;
	fprintf(fout,"%d\n",answer);
	fclose(fout);
}

int main(){
	input();
	process();
	return 0;
}