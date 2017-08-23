#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

FILE *fout = fopen("planting.out","w");

int n;
int map[32][32];
int queue[1024][2];
int head,tail;
int awww;
char marked[32][32];
int cox[32];
int coy[32];
bool checkx[32768];
bool checky[32768];
int xcount;
int ycount;
int startx,starty;
int xcounter[32];
int ycounter[32];
int origx[32];
int origy[32];

int binsearch(int x,int y){
	int left=0;
	if(y==0){
		int right=xcount-1;
		while(left<=right){
			int mid=(left+right)/2;
			if(x>cox[mid]){
				left=mid+1;
			}
			else if(x==cox[mid]){
				return mid;
			}
			else{
				right=mid-1;
			}
		}
	}
	else{
		int right=ycount-1;
		while(left<=right){
			int mid=(left+right)/2;
			if(x>coy[mid]){
				left=mid+1;
			}
			else if(x==coy[mid]){
				return mid;
			}
			else{
				right=mid-1;
			}
		}
	}
}

void input(){
	FILE *fp = fopen("planting.in","r");
	fscanf(fp,"%d",&n);
	for(int i=0;i<n;i++){
		int x1,x2,y1,y2;
		fscanf(fp,"%d%d%d%d",&x1,&y1,&x2,&y2);
		origx[2*i]=x1;
		origx[(2*i)+1]=x2;
		origy[2*i]=y1;
		origy[(2*i)+1]=y2;
		if(checkx[x1+10000]==0){
			cox[xcount]=x1;
			checkx[x1+10000]=1;
			xcount++;
		}
		if(checkx[x2+10000]==0){
			cox[xcount]=x2;
			checkx[x2+10000]=1;
			xcount++;
		}
		if(checky[y1+10000]==0){
			coy[ycount]=y1;
			checky[y1+10000]=1;
			ycount++;
		}
		if(checky[y2+10000]==0){
			coy[ycount]=y2;
			checky[y2+10000]=1;
			ycount++;
		}
	}
	sort(cox,cox+xcount);
	sort(coy,coy+ycount);
	for(int i=0;i<xcount-1;i++){
		xcounter[i]=abs(cox[i+1]-cox[i]);
		//fprintf(fout,"%d\n",xcounter[i]);
	}
	for(int i=0;i<ycount-1;i++){
		ycounter[i]=abs(coy[i+1]-coy[i]);
		//fprintf(fout,"%d\n",ycounter[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=binsearch(origx[2*i],0);j<binsearch(origx[(2*i)+1],0);j++){
			for(int k=binsearch(origy[(2*i)+1],1);k<binsearch(origy[2*i],1);k++){
				//fprintf(fout,"%d %d\n",j,k);
				map[j][k]=1;
			}
		}
	}
}

void push(int x,int y){
	if(x<0 || y<0 || x>xcount-1 || y>ycount-1)
		return;
	if(marked[x][y]!=0)
		return;
	if(map[x][y]==1){
		//fprintf(fout,"v: %d x %d = %d\n",xcounter[x],ycounter[y],(xcounter[x]*ycounter[y]));
		awww+=xcounter[x]*ycounter[y];
		//awww++;
		//fprintf(fout,"%d\n",awww);
	}
	marked[x][y]=1;
	queue[tail][0]=x;
	queue[tail][1]=y;
	tail++;
	return;
}

void process(){
	awww=0;
	push(0,0);
	while(head<tail){
		int x=queue[head][0];
		int y=queue[head][1];
		push(x+1,y);
		push(x,y+1);
		push(x-1,y);
		push(x,y-1);
		head++;
	}
	fprintf(fout,"%d\n",awww);
	fclose(fout);
}

int main(){
	input();
	process();
	return 0;
}