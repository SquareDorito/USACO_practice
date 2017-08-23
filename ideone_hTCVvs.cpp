#include <cstdio>
using namespace std;

FILE *fout = fopen("cowrace.out","w");

int n,m;
int bessie[1024][2];
int btime[1048576];
int etime[1048576];
int el[1024][2];
int maxtime;

void input(){
	FILE *fp = fopen("cowrace.in","r");
	fscanf(fp,"%d%d",&n,&m);
	int temptime=0;
	for(int i=0;i<n;i++){
		fscanf(fp,"%d%d",&bessie[i][0],&bessie[i][1]);
		maxtime+=bessie[i][1];
	}
	for(int i=0;i<m;i++){
		fscanf(fp,"%d%d",&el[i][0],&el[i][1]);
		temptime+=el[i][1];
	}
	if(temptime>maxtime)
		maxtime=temptime;
	int head=0;
	for(int i=0;i<n;i++){
		for(int j=head;j<head+bessie[i][1];j++){
			btime[j]=bessie[i][0];
		}
		head+=bessie[i][1];
	}
	head=0;
	for(int i=0;i<m;i++){
		for(int j=head;j<head+el[i][1];j++){
			etime[j]=el[i][0];
		}
		head+=el[i][1];
	}
	fclose(fp);
}

void process(){
	int bloc=0;
	int eloc=0;
	int tracker=0;
	int lastrack=0;
	int answer=0;
	for(int i=0;i<maxtime;i++){
		bloc+=btime[i];
		eloc+=etime[i];
		if(eloc!=bloc){
			if(bloc>eloc)
				tracker=1;
			else tracker=-1;
		}
		if(lastrack!=tracker){
			answer++;
		}
		lastrack=tracker;
	}
	fprintf(fout,"%d\n",answer-1);
	fclose(fout);
}

int main(){
	input();
	process();
	return 0;
}