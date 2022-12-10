import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class GoodPair {
    public static void main(String args[]){
      ArrayList<Integer> l=new ArrayList<>();
      Scanner sc=new Scanner(System.in); 
      int n=sc.nextInt();
      for(int i=0;i<n;i++){
        l.add(sc.nextInt());
      }
      int b=sc.nextInt();
      sc.close();
      Collections.sort(l);
     int low=0;
     int high=n-1;
     while(low<high){
        int x=l.get(low);
        if(l.get(high)+x>b){
            high--;
        }else if(l.get(high)+x<b){
            low++;
        }else{
            System.out.println("Pair Sum is present at index ");
            break;
        }
     }           
    }
}
