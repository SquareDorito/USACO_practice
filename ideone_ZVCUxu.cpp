import java.io.*;
import java.util.*;
import java.lang.Math.*;

/*
ID: kennoh4152
LANG: JAVA
TASK: palsquare
*/

public class palsquare {
	static int b;
	
	public static boolean Check(String str){
		for(int i=0;i<str.length();i++){
			if(str.charAt(i)!=str.charAt(str.length()-1-i)){
				return false;
			}
		}
		return true;
	}
	
	public static String ChangeBase(int x, int base,int y){
		int i=0;
		String answer="";
		if(y==1)
			x=x*x;
		while(x>0){
			int r=(x%base);
			if(r>=10){
				r=(55+r);
				char temp=(char)r;
				answer=temp+answer;
			}
			else
				answer = r+answer;
			x=x/base;
			i++;
		}
		return answer;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader f = new BufferedReader(new FileReader("palsquare.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("palsquare.out")));
		StringTokenizer st = new StringTokenizer(f.readLine());
		b = Integer.parseInt(st.nextToken());
		
		for(int i=1;i<=300;i++){
			if(Check(ChangeBase(i,b,1))){
				out.println(ChangeBase(i,b,0)+" "+ChangeBase(i,b,1));
			}
		}
		out.close();
		System.exit(0);
	}
}
