

import java.util.*;

public class SearchElement {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while(t>0){
             int n=sc.nextInt();
             int [] arr=new int[n+1];
             arr[0]=n;
            for(int i=1;i<arr.length;i++){
            arr[i]=sc.nextInt();
            }
        int B=sc.nextInt();
        boolean k=true;
        for(int i=1;i<arr.length;i++){
            if(arr[i]==B){
                System.out.println(1);
                k=false;
                break;

            }
        }
        if(k)  System.out.println(0);
        t--;
    }
    sc.close();
        
    }
}
