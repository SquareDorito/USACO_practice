#include <cstdio>
using namespace std;

FILE *fout = fopen("cowrow.out","w");

int n;
int orig[1024];
int ans;
int tempcount;
int tempmax;

void input(){
	FILE *fp = fopen("cowrow.in","r");
	fscanf(fp,"%d",&n);
	for(int i=0;i<n;i++){
		fscanf(fp,"%d",&orig[i]);
	}
	fclose(fp);
}

void process(){
	for(int i=0;i<n;i++) {
		int tracker=-1;
		int counter = 0;
		for(int j=0;j<n;j++) {
			if(orig[j]!=orig[i]) {
				if(tracker==orig[j]) {
					counter++;
				}
				else {
					tracker=orig[j];
					counter=1;
				}
				if(counter>tempmax)
					tempmax=counter;
			}
		}
		if(tempmax>ans)
			ans=tempmax;
		tempmax=0;
	}
	fprintf(fout,"%d\n", ans);
	fclose(fout);
}

int main(){
	input();
	process();
	return 0;
}