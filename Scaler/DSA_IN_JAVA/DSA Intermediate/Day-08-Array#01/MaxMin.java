import java.util.Scanner;

import javafx.util.Pair;

public class MaxMin {
    public static int n;
    public static void main(String args[]){
       Scanner sc=new Scanner(System.in);
         n=sc.nextInt();
        int [] arr=new int [n];
        for(int i=0;i<arr.length;i++){
            arr[i]=sc.nextInt();
        }
        MaxMin obj=new MaxMin();
        Pair<Integer,Integer>p1;
        p1=obj.findMinMax(arr);
    }
    public Pair<Integer,Integer> findMinMax(int [] arr){
        Pair<Integer,Integer>ans;
        int min_val=Integer. MAX_VALUE;
        int max_val=Integer.MAX_VALUE;
        for(int i=0;i<n;i++){
            min_val=Math.min(min_val, arr[i]);
            max_val=Math.max(max_val, arr[i]);
        }
        

        return ans;
    }
}
