/*
ID: kennoh4152
LANG: JAVA
TASK: barn1
*/

import java.io.*;
import java.util.*;

public class barn1 {
	
	public static int m,s,c;
	public static int[] data = new int[256];
	public static int[] map = new int[256];
	public static int[][] gaps = new int[256][4];
	public static int[] answerarr = new int[256];
	
	/*public static void sortdata(){
		for(int i=0;i<data.length;i++){
			int tempmin1=data[i];
			int tempindex1=i;
			for(int j=i;j<data.length;j++){
				if(data[j]<tempmin1){
					tempmin1=data[j];
					tempindex1=j;
				}
			}
			int temp=data[i];
			data[i]=data[tempindex1];
			data[tempindex1]=temp;
		}
	}*/
	
	public static void customsort(int length){
		for(int i=0;i<length;i++){
			int tempmax=gaps[i][0];
			int tempindex=i;
			for(int j=i;j<gaps.length;j++){
				if(gaps[j][0]>tempmax){
					tempmax=gaps[j][0];
					tempindex=j;
				}
			}
			int temp=gaps[i][0];
			gaps[i][0]=gaps[tempindex][0];
			gaps[tempindex][0]=temp;
			temp=gaps[i][1];
			gaps[i][1]=gaps[tempindex][1];
			gaps[tempindex][1]=temp;
			temp=gaps[i][2];
			gaps[i][2]=gaps[tempindex][2];
			gaps[tempindex][2]=temp;
		}
	}
	
	public static void main (String [] args) throws IOException {
	    BufferedReader f = new BufferedReader(new FileReader("barn1.in"));
	    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("barn1.out")));
	    StringTokenizer st = new StringTokenizer(f.readLine());
	    m = Integer.parseInt(st.nextToken()); //max num of boards that can be purchased
	    s = Integer.parseInt(st.nextToken()); //total num of stalls
	    c = Integer.parseInt(st.nextToken()); //num of stalls occupied	    
	    
	    for(int i=0;i<c;i++){
	    	st = new StringTokenizer(f.readLine());
	    	data[i]=Integer.parseInt(st.nextToken())-1;
	    }
	    for(int i=0;i<c;i++){
	    	map[data[i]]=1;
	    }
	    //sortdata();
	    int first=data[0];
	    int last=data[0];
	    for(int i=1;i<c;i++){
	    	if(data[i]<first)
	    		first=data[i];
	    	if(data[i]>last)
	    		last=data[i];
	    }
	    int temptrack=0;
	    int tempcount=0;
	    int tempstart=0;
	    int totalcount=0;
	    for(int i=first;i<=last;i++){
	    	if(map[i]==0){
	    		if(temptrack==0){
	    			temptrack=1;
	    			tempcount++;
	    			tempstart=i;
	    		}
	    		else{
	    			tempcount++;
	    		}
	    	}
	    	else{
	    		if(temptrack==1){
	    			gaps[totalcount][0]=tempcount;
	    			gaps[totalcount][1]=tempstart;
	    			gaps[totalcount][2]=i-1;
	    			temptrack=0;
	    			totalcount++;
	    			tempcount=0;
	    		}
	    		else{}
	    	}
	    }
	    customsort(totalcount);
	    for(int i=0;i<m-1;i++){
	    	
	    	for(int j=gaps[i][1];j<=gaps[i][2];j++){
	    		answerarr[j]=1;
	    	}
	    }
	    int answer=0;
	    for(int i=first;i<=last;i++){
	    	if(answerarr[i]==0)
	    		answer++;
	    }
	    out.println(answer);
	    out.close();
	    System.exit(0);
	  }
}
