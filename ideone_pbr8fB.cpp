#include <cstdio>
#include <algorithm>
using namespace std;

int n,k,p;
int deck[1<<20];
int top,bottom;
int playerturn=0;
int answer[65536];
int acount;

void input(){
	scanf("%d%d%d",&n,&k,&p);
	bottom=k-1;
	for(int i=0;i<k;i++){
		deck[i]=i;
	}
}

void process(){
	for(int i=0;i<k;i++){
		if(playerturn==n-1){
			answer[acount]=deck[top];
			acount++;
		}
		deck[top]=0;
		top++;
		//put p cards from top to bottom
		for(int j=0;j<p;j++){
			bottom++;
			deck[bottom]=deck[top];
			deck[top]=0;
			top++;
		}
		playerturn=(playerturn+1)%n;
	}
	sort(answer,answer+(k/n));
	for(int i=0;i<(k/n);i++){
		printf("%d\n",answer[i]+1);
	}
}

int main(){
	freopen("stacking.in","r",stdin);
	freopen("stacking.out","w",stdout);
	input();
	process();
	return 0;
}