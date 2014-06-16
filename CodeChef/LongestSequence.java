//Given a sequence, the objective is to find the longest progressive sequence arranged in ascending order
package Default;

import java.io.IOException;
import java.util.Scanner;

public class First {
	public static void main(String[] args) throws IOException
	{
		int a,large=0,count=0,i,j,k;
		Scanner in=new Scanner(System.in);
		a=in.nextInt();
		int b[]=new int[a];
		for(i=0;i<a;i++) {
		b[i]=in.nextInt();
		}
		
		int c[]=new int[a];
		for(i=0;i<a-1;i++) {
			if(b[i+1]<b[i])
			{
				if(count+1>large) {
					count++;
				large=count;
				 c=new int[a];
				 for(j=0,i=i-count;count>0;count--)
					c[j++]=b[i++];
				}
				count=0;
			}
			else {
				count++;
				if(count==a) {
					large=count;
					for(k=0;k<a;k++)
						c[k]=b[k];
				}
					
			}
		}
		System.out.println(large);
		for(i=0;i<large;i++)
			System.out.println(c[i]);		
	}

}
