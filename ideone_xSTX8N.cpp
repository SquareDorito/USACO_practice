/*
ID: kennoh4152
PROG: hexagon
LANG: C++
*/
#include <cstdio>
#include <algorithm>
using namespace std;

FILE *fout = fopen("hexagon.out","w");

int k,h,l; // k=sidelength ; h = start ; l=distance
int queue[8192][2];
int marked[128][128];
int head,tail;
int coor[8192][2];
int reversecoor[128][128];
int m;
int arr[512];

void input(){
	FILE *fp = fopen("hexagon.in","r");
	fscanf(fp,"%d%d%d",&k,&h,&l);
	fclose(fp);
	m=3*k*(k-1)+1;
}

void convert(){
	int count=1;
	for(int c=0;c<2*k-1;c++){
		if(c<k){
			for(int i=0;i<k+c;i++){
				coor[count][0]=i;
				coor[count][1]=c;
				reversecoor[i][c]=count;
				count++;
			}
		}
		else{
			for(int i=0;i<3*k-c-2;i++){
				coor[count][0]=i;
				coor[count][1]=c;
				reversecoor[i][c]=count;
				count++;
			}
		}
	}
}

bool validate(int x,int y){
	if(y<0 || y>=2*k-1)
		return false;
	if(x<0 || x>=2*k-1)
		return false;
	if(y<k){
		if(x<y+k)
			return true;
		else return false;
	}
	else{
		if(x<3*k-y-2)
			return true;
		else return false;
	}
}
/*
void helper(int p){
	fprintf(fout,"%d\n",p);
	int x=coor[p][0];
	int y=coor[p][1];
	if(coor[p][1]<k-1){
		if(validate(x+1,y)==true)
			fprintf(fout,"%d %d %d\n",x+1,y,reversecoor[x+1][y]);
		if(validate(x-1,y)==true)
			fprintf(fout,"%d %d %d\n",x-1,y,reversecoor[x-1][y]);
		if(validate(x,y+1)==true)
			fprintf(fout,"%d %d %d\n",x,y+1,reversecoor[x][y+1]);
		if(validate(x,y-1)==true)
			fprintf(fout,"%d %d %d\n",x,y-1,reversecoor[x][y-1]);
		if(validate(x-1,y-1)==true)
			fprintf(fout,"%d %d %d\n",x-1,y-1,reversecoor[x-1][y-1]);
		if(validate(x+1,y+1)==true)
			fprintf(fout,"%d %d %d\n",x+1,y+1,reversecoor[x+1][y+1]);
	}
	else if(coor[p][1]==k-1){
		if(validate(x+1,y)==true)
			fprintf(fout,"%d %d %d\n",x+1,y,reversecoor[x+1][y]);
		if(validate(x-1,y)==true)
			fprintf(fout,"%d %d %d\n",x-1,y,reversecoor[x-1][y]);
		if(validate(x,y+1)==true)
			fprintf(fout,"%d %d %d\n",x,y+1,reversecoor[x][y+1]);
		if(validate(x,y-1)==true)
			fprintf(fout,"%d %d %d\n",x,y-1,reversecoor[x][y-1]);
		if(validate(x-1,y+1)==true)
			fprintf(fout,"%d %d %d\n",x,y-1,reversecoor[x-1][y+1]);
		if(validate(x-1,y-1)==true)
			fprintf(fout,"%d %d %d\n",x,y-1,reversecoor[x-1][y-1]);
	}
	else{
		if(validate(x+1,y)==true)
			fprintf(fout,"%d %d %d\n",x+1,y,reversecoor[x+1][y]);
		if(validate(x-1,y)==true)
			fprintf(fout,"%d %d %d\n",x-1,y,reversecoor[x-1][y]);
		if(validate(x,y+1)==true)
			fprintf(fout,"%d %d %d\n",x,y+1,reversecoor[x][y+1]);
		if(validate(x,y-1)==true)
			fprintf(fout,"%d %d %d\n",x,y-1,reversecoor[x][y-1]);
		if(validate(x+1,y-1)==true)
			fprintf(fout,"%d %d %d\n",x,y-1,reversecoor[x+1][y-1]);
		if(validate(x-1,y+1)==true)
			fprintf(fout,"%d %d %d\n",x,y-1,reversecoor[x-1][y+1]);
	}
	fprintf(fout,"\n");
}*/

void push(int x,int y, int depth){
	if(validate(x,y)==false)
		return;
	if(marked[x][y]!=0)
		return;
	queue[tail][0]=x;
	queue[tail][1]=y;
	marked[x][y]=depth;
	tail++;
}

void process(){
	convert();
	push(coor[h][0],coor[h][1],1);
	while(head<tail){
		int x=queue[head][0];
		int y=queue[head][1];
		int depth=marked[x][y]+1;
		push(x+1,y,depth);
		push(x-1,y,depth);
		push(x,y+1,depth);
		push(x,y-1,depth);
		if(y<k-1){
			push(x-1,y-1,depth);
			push(x+1,y+1,depth);
		}
		else if(y==k-1){
			push(x-1,y+1,depth);
			push(x-1,y-1,depth);
		}
		else{
			push(x+1,y-1,depth);
			push(x-1,y+1,depth);
		}
		head++;
		
	}
	int ccount=0;
	int acount=0;
	for(int i=0;i<tail;i++){
		int x1=queue[i][0];
		int y1=queue[i][1];
		if(marked[x1][y1]==l+1){
			ccount++;
		}
	}
	fprintf(fout,"%d\n",ccount);
	for(int i=0;i<tail;i++){
		int x1=queue[i][0];
		int y1=queue[i][1];
		if(marked[x1][y1]==l+1){
			arr[acount]=reversecoor[x1][y1];
			acount++;
		}
	}
	sort(arr,arr+acount);
	for(int i=0;i<acount;i++){
		fprintf(fout,"%d\n",arr[i]);
	}
	fclose(fout);
}

int main(){
	input();
	process();
	return 0;
}