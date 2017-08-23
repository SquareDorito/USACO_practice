/*
ID: your_id_here
LANG: JAVA
TASK: gift1
*/

import java.io.*;
import java.util.*;

public class gift1 {
	public static String[] names = new String[16];
	public static int[] totals=new int[16];
	public static int n;
	public static int helper(String name){
		for(int i=0;i<n;i++){
			if(name.equals(names[i])){
				return i;
			}
		}
		return 0;
	}
	
	public static void main (String [] args) throws IOException {
		String temp;
		int i1;
		int i2;
		String[] receive = new String[16];
		// Use BufferedReader rather than RandomAccessFile; it's much faster
		BufferedReader f = new BufferedReader(new FileReader("gift1.in"));
		                                          // input file name goes above
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("gift1.out")));
		// Use StringTokenizer vs. readLine/split -- lots faster
		StringTokenizer st = new StringTokenizer(f.readLine());
							  // Get line, break into tokens
		n = Integer.parseInt(st.nextToken());    // first integer
		for(int i=0;i<n;i++){
			st = new StringTokenizer(f.readLine());
			names[i]=st.nextToken();
		}
		for(int i=0;i<n;i++){
			st = new StringTokenizer(f.readLine());
			temp=st.nextToken();
			st = new StringTokenizer(f.readLine());
			i1=Integer.parseInt(st.nextToken());
			i2=Integer.parseInt(st.nextToken());
			for(int j=0;j<i2;j++){
				st = new StringTokenizer(f.readLine());
				receive[j]=st.nextToken();
			}
			if(i2==0 || i1==0)
				continue;
			int i3=i1/i2;
			totals[helper(temp)]-=i3*i2;
			for(int j=0;j<i2;j++){
				totals[helper(receive[j])]+=i3;
			}
		}	
		for(int i=0;i<n;i++){
			out.println(names[i]+" "+totals[i]);
		}
		out.close();
		System.exit(0);
	}
}
