import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class ReverseArray {
    public static void main(String args []){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        Integer [] A=new Integer[n];
        for(int i=0;i<n;i++){
            A[i]=sc.nextInt();
        }
        sc.close();
        List<Integer>l=Arrays.asList(A);
        l=solve(l);
        for(int a:l){
            System.out.print(a + " ");
            
        }
    }

        public  static ArrayList<Integer> solve(final List<Integer> A) {
            ArrayList<Integer>res=new ArrayList<>();
            res.addAll(A);
            System.out.println("res Array"+" "+res);
           int low=0;
           int high=res.size()-1;
           System.out.println("high"+" "+high);
           while(low<=high){
               Collections.swap(res,low,high);
               low++;
               high--;
           }
           return res;
       }
  
}
