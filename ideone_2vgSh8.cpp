#include <cstdio>

FILE *fout = fopen("greetings.out","w");

int b,e;
char bmove[1048576];
char emove[1048576];
int maxi,answer;
int counter=0;
int counter2=0;
int tempi;
char tempc;

void input(){
	FILE *fp = fopen("greetings.in","r");
	fscanf(fp,"%d%d",&b,&e);
	for(int i=0;i<b;i++){
		char space;
		fscanf(fp,"%d %c",&tempi,&tempc);
		for(int j=counter;j<counter+tempi;j++){
			bmove[j]=tempc;
		}
		counter+=tempi;
	}
	for(int i=0;i<e;i++){
		char space;
		fscanf(fp,"%d %c",&tempi,&tempc);
		for(int j=counter2;j<counter2+tempi;j++){
			emove[j]=tempc;
		}
		counter2+=tempi;
		
	}
	if(counter>counter2)
		maxi=counter;
	else maxi=counter2;
	fclose(fp);
}

void process(){
	int we=0;
	int flag=1;
	int wb=0;
	for(int i=0;i<maxi;i++){
		//fprintf(fout,"%d %d %d\n",i,wb,we);
		if(bmove[i]=='R')
			wb++;
		else if(bmove[i]=='L')
			wb--;
		if(emove[i]=='R')
			we++;
		else if(emove[i]=='L')
			we--;
		if(wb==we){
			if(flag==0) {
				//fprintf(fout,"%d %d\n", i, wb);
				answer++;
			}
			flag=1;
		}
		else flag=0;
	}
	fprintf(fout,"%d\n",answer);
	fclose(fout);
}

int main(){
	input();
	process();
	return 0;
}