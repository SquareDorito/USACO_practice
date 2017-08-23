/*
ID: kennoh4152
TASK: preface
LANG: C++
*/

#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
int counter[256];
string original = " IVXLCDM";
vector <pair<int,string> > data;

FILE *fout = fopen("preface.out","w");

string helper(int num){
    string stuff="";
    for ( int i=0;i!=13;i++)
    {
		while( num >= data[i].first )
        {
			stuff += data[i].second;
            num-=data[i].first;
        }
    }
    return stuff;
}
 
int main(){
	FILE *fp = fopen("preface.in","r");
	data.push_back(make_pair(1000,"M"));
	data.push_back(make_pair(900,"CM"));
	data.push_back(make_pair(500,"D"));
	data.push_back(make_pair(400,"CD"));
	data.push_back(make_pair(100,"C"));
	data.push_back(make_pair(90,"XC"));
	data.push_back(make_pair(50,"L"));
	data.push_back(make_pair(40,"XL"));
	data.push_back(make_pair(10,"X"));
	data.push_back(make_pair(9,"IX"));
	data.push_back(make_pair(5,"V"));
	data.push_back(make_pair(4,"IV"));
	data.push_back(make_pair(1,"I"));
	int n;
    fscanf(fp,"%d",&n);
	fclose(fp);
    for(int i=1;i<=n;i++){
        string temp=helper(i);
        for(int i=0;i!=temp.size();i++){
			counter[temp[i]] ++;
		}
    }
    for(int i=1;i<=7;i++){
        if(counter[original[i]])
			fprintf(fout,"%c %d\n",original[i],counter[original[i]]);
	}
    return 0;
}