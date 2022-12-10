import java.util.Scanner;

public class MaxAndMinOfAnArray {
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int [] A=new int[n];
        for(int i=0;i<n;i++){
            A[i]=sc.nextInt();
        }
        sc.close();
        int max_num=Integer.MIN_VALUE;
        int min_num=Integer.MAX_VALUE;
        for(int i=0;i<n;i++){
            max_num=Math.max(max_num, A[i]);
            min_num=Math.min(min_num, A[i]);
        }
        System.out.println(max_num);
        System.out.println(min_num);

    }
}
