#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

FILE *fout = fopen("islands.out","w");

int n;
vector<pair<int,int>> arr;
int sorted[131072];
int lorw[131072]; //0=land,1=water

void input(){
	FILE *fp = fopen("islands.in","r");
	fscanf(fp,"%d",&n);
	for(int i=0;i<n;i++){
		int x;
		fscanf(fp,"%d",&x);
		arr.push_back(make_pair(x,i));
	}
	sort(arr.begin(),arr.end());
	fclose(fp);
}

/*int binsearch(int x){
    int left=0;
    int right=n-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(x>arr[mid][0]){
            left=mid+1;
        }
        else if(x==arr[mid][0]){
            return mid;
        }
        else{
            right=mid-1;
        } 
    }
}*/

void process(){
	int maxcount=1;
	int islands=1;
	for(int i=0;i<n;i++){
		int loc=arr[i].second;
		lorw[loc]=1;
		if((loc>0 && lorw[loc-1]==0) && (loc<n-1 && lorw[loc+1]==0)){
			islands++;
		}
		if((loc==0 || lorw[loc-1]==1) && (loc==n-1 || lorw[loc+1]==1)){
			islands--;
		}
		if(islands>maxcount)
			maxcount=islands;
	}
	fprintf(fout,"%d\n",maxcount);
}

int main(){
	input();
	process();
	fclose(fout);
	return 0;
}