/*
ID: kennoh4152
PROG: passwd
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int l,c;
char arr[32];
char temp[16];
int used[32];
int pcount=0;

FILE *fout = fopen("passwd.out","w");

void input(){
	FILE *fp = fopen("passwd.in","r");
	fscanf(fp,"%d%d",&l,&c);
	for(int i=0;i<c;i++){
		fscanf(fp," %c",&arr[i]);
		//printf("%c ",arr[i]);
	}
	fclose(fp);
	sort(arr,arr+c);
}

void permutation(int depth,char i){
	temp[depth]=i;
	if(depth==l-1){
		if(pcount<25000){
			int count=0;
			for(int k=0;k<l;k++){
				if(temp[k]=='a' || temp[k]=='e' || temp[k]=='i' || temp[k]=='o' || temp[k]=='u'){
					count++;
				}
			}
			if(count>0 && count<=l-2){
				pcount++;
				temp[l]=0;
				fprintf(fout,"%s\n",temp);
				if(pcount>=25000){
					fclose(fout);
					exit(0);
				}
			}
		}
		return;
	}
	for(int j=0;j<c;j++){
		if(used[arr[j]-'a']==0){
			if(arr[j]>temp[depth]){
				used[arr[j]-'a']++;
				permutation(depth+1,arr[j]);
				used[arr[j]-'a']--;
			}
		}
	}
}

void process(){
	for(int i=0;i<c;i++){
		used[arr[i]-'a']++;
		permutation(0,arr[i]);
		used[arr[i]-'a']--;
	}
	fclose(fout);
}

int main(){
	input();
	process();
	//while(true);
	return 0;
}