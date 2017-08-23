/*
ID: kennoh4152
PROG: charms
LANG: C++
*/
#include <cmath>
#include <cstdio>
using namespace std;

FILE *fout = fopen("charms.out","w");

int l,c,n; // length,charms,nail
int s[512]; // s[]
int p[32768]; // p[]
int ans[512];

void input(){
	FILE *fp = fopen("charms.in","r");
	fscanf(fp,"%d%d%d",&l,&c,&n);
	for(int i=0;i<c;i++){
		fscanf(fp,"%d %d",&s[i],&p[i]);
		fprintf(fout,"%d\n",abs(p[i]-n)+s[i]);
	}
	fclose(fp);
	fclose(fout);
}

int main(){
	input();
	return 0;
}