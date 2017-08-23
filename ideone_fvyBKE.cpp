#include <cstdio>
using namespace std;
 
FILE *fout = fopen("connect.out","w");
 
int n,answer;
int cow[16][2];
int marked[16];

void input(){
    FILE *fp = fopen("connect.in","r");
    fscanf(fp,"%d",&n);
    for(int i=0;i<n;i++){
            int x,y;
            fscanf(fp,"%d%d",&x,&y);
            cow[i][0]=x;
            cow[i][1]=y;
    }
    cow[n][0]=0;
    cow[n][1]=0;
    fclose(fp);
}

int getdir(int idx,int nidx){
	if(cow[idx][0]==cow[nidx][0]){
		//vertical line
		return (cow[idx][1] > cow[nidx][1]) ? 1 : 3;
		//return 3 - 2 * (cow[idx][1] > cow[nidx][1]);
	}
	else{
		//horizontal line
		return (cow[idx][0]>cow[nidx][0]) ? 2: 0;
	}
}

bool isvalid(int pidx,int idx, int nidx){
	//returns 1 if valid
	if(cow[idx][0]!=cow[nidx][0] && cow[idx][1]!=cow[nidx][1]){
		return 0;
	}
	int d1,d2;
	d1=getdir(pidx,idx);
	d2=getdir(idx,nidx);
	if(d1==d2)
		return 0;
	else return 1;
}

void brute(int idx,int depth,int pidx){
	int x=cow[idx][0];
	int y=cow[idx][1];	
	if(depth==n){
		if(x==cow[n][0] || y==cow[n][1]){
			answer++;
		}
		return;
	}
    for(int i=0;i<n;i++){
            if(marked[i]==0){
                    if(isvalid(pidx,idx,i)==1){
							marked[i]=1;
                            brute(i,depth+1,idx);
                            marked[i]=0;
                    }
            }
    }
}
 
void process(){
    for(int i=0;i<n;i++){
            if(marked[i]==0){
				if(cow[i][0]==cow[n][0] || cow[i][1]==cow[n][1]){
					marked[i]=1;
					brute(i,1,n);
					marked[i]=0;
				}
            }
    }
    fprintf(fout,"%d\n",answer);
    fclose(fout);
}
 
int main(){
    input();
    process();
    return 0;
}