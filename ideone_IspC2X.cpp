#include <cstdio>
#include <algorithm>
using namespace std;

FILE *fout = fopen("paint.out","w");

int n;
int origdist[131072];
char origdire[131072];
int co[131072];
int map[131072];
int howmany;
int stored[131072];

int binsearch(int x){
	int left=0;
	int right=howmany-1;
	while(left<=right){
			int mid=(left+right)/2;
		if(x>co[mid]){
			left=mid+1;
		}
		else if(x==co[mid]){
			return mid;
		}
		else{
			right=mid-1;
		} 
	}
}

void input(){
	//printf("hello.\n");
	int current=0;
	co[0]=0;
	howmany=1;
	FILE *fp = fopen("paint.in","r");
	fscanf(fp,"%d",&n);
	//printf("hello.\n");
	for(int i=0;i<n;i++){
		//fprintf(fout,"%d ",howmany);
		int temp1=0;
		char temp2=0;
		fscanf(fp,"%d %c",&temp1,&temp2);
		//printf("%d %c\n",temp1,temp2);
		origdist[i]=temp1;
		origdire[i]=temp2;
		if(temp2=='R')
			current+=temp1;
		else current-=temp1;
		co[howmany]=current;
		howmany++;
	}
	sort(co,co+howmany);
	fclose(fp);
	
}

void process(){
	int current=0;
	int lastcurrent=0;
	for(int i=0;i<n;i++){
		if(origdire[i]=='R')
			current+=origdist[i];
		else current-=origdist[i];
		if(current>lastcurrent){
			map[binsearch(lastcurrent)]++;
			map[binsearch(current)]--;
		}
		else{
			map[binsearch(lastcurrent)]--;
			map[binsearch(current)]++;
		}
		lastcurrent=current;
	}
	for(int i=0;i<howmany;i++){
		stored[i]=co[i+1]-co[i];
	}
	/*for(int i=0;i<howmany;i++){
		fprintf(fout,"%d\n",map[i]);
	}*/	
	int value=0;
	int answer=0;
	int flag=0;
	for(int i=0;i<=howmany;i++){
		value+=map[i];
		if(value>=2){
			answer+=stored[i];
		}
	}
	fprintf(fout,"%d\n",answer);
	fclose(fout);
}

int main(){
	input();
	//printf("good to go.\n");
	process();
	return 0;
}