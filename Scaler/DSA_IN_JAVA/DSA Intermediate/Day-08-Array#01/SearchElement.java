/*
 * Problem Description
   You are given an integer T (number of test cases). You are given array A and an integer B for each test case. You have to tell whether B is present in array A or not.
 
   

 Problem Constraints
1 <= T <= 10

1 <= |A| <= 105

1 <= A[i], B <= 109


Input 1:

 1 
 5 4 1 5 9 1
 5
Input 2:

 1
 3 7 7 2
 1
 * 
 * 
 * 
Output 1:

 1 
Output 2:

 0 
 */

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
