//Codevita 2013 Zombie Problem
import java.util.Scanner;
public class z {
 
 public static void main(String[] args) {
      int a=0,b,c,i;    
      Scanner s= new Scanner(System.in);
      a = Integer.parseInt(s.next().trim());
      b = Integer.parseInt(s.next().trim());
      for (i = 0; i < b;i++) {
      c = Integer.parseInt(sc.next().trim());
      a =- ((a / 2) + (a % 2));
   }
   if(a>0)
   System.out.println("YES");
   else
   System.out.println("NO");
 }
}


