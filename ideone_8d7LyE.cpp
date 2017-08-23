#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

FILE *fout = fopen("typo.out","w");

char arr[131072];
char arr2[131072];
int l;
int nc,no;
int nci[131072];
int noi[131072];
int ncr[131072];
int nor[131072];
int answer;

void input(){
	FILE *fp = fopen("typo.in","r");
	fscanf(fp,"%s",arr);
	l=strlen(arr);
	for(int i=0;i<l;i++){
		arr2[i]=arr[i];
	}
	fclose(fp);
}

void process(){
	int nccount=0;
	int nocount=0;
	for(int i=0;i<l;i++){
		if(arr[i]=='(')
			no++;
		else nc++;
	}
	if(abs(no-nc)!=2)
		return;
	if(nc<no){
		for(int i=0;i<l;i++){
			if(arr2[l-i-1]='(')
				arr[i]=')';
			else arr[i]='(';
		}
	}
	for(int i=0;i<l;i++){
		nci[i]=nccount;
		noi[i]=nocount;
		if(arr[i]=='(')
			nocount++;
		else nccount++;
	}
	nccount=0;
	nocount=0;
	int flag=0;
	for(int i=l-1;i>=0;i--){
		if(arr[i]=='(')
			nocount++;
		else nccount++;
		if(nocount>nccount){
			flag=i;
			break;
		}
	}
	for(int i=flag;i<l;i++){
		if(nci[i]>noi[i])
			break;
		if(arr[i]==')'){
			answer++;
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