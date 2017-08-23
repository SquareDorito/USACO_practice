#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

FILE *fout = fopen("times17.out","w");

char str[1024];
char str1[1024];
char str2[1024];
char str3[1024];
char answer[1024];
char answer2[1024];
int l,carry;

void input(){
	FILE *fp = fopen("times17.in","r");
	fscanf(fp,"%s\n",str);
	l=strlen(str);
	for(int i=0;i<l;i++){
		str[i]-=48;
		str2[i]=str[i];
	}
	for(int i=l;i<l+4;i++){
		str2[i]=0;
	}
	fclose(fp);
	reverse_copy(str,str+l,str1);
	reverse_copy(str2,str2+l+4,str3);
}

void process(){
	for(int i=0;i<l+4;i++){
		answer[i]=str1[i]+str3[i]+carry;
		
		carry=0;
		if(answer[i]>=2){
			answer[i]-=2;
			carry=1;
		}
		//fprintf(fout,"%d",answer[i]);
	}
	int flag=0;
	if(carry==1){
		answer[l+4]++;
		flag=1;
	}
	//fprintf(fout,"\n");
	if(flag==1)
		reverse_copy(answer,answer+l+5,answer2);
	else reverse_copy(answer,answer+l+4,answer2);
	if(flag==1){
		for(int i=0;i<=l+4;i++){
			fprintf(fout,"%d",answer2[i]);
		}
	}
	else{
		for(int i=0;i<l+4;i++){
			fprintf(fout,"%d",answer2[i]);
		}
	}
	fprintf(fout,"\n");
	fclose(fout);
}

int main(){
	input();
	process();
	return 0;
}