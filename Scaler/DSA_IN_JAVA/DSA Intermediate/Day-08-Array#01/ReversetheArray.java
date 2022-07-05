import java.util.Scanner;

public class ReversetheArray {
    public static int n;
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
         n=sc.nextInt();
        int [] arr=new int [n];
        for(int i=0;i<arr.length;i++){
            arr[i]=sc.nextInt();
        }
        int [] res=new int [n];
        ReversetheArray obj = new ReversetheArray();
        res=obj.solve(arr);
        for(int i=0;i<n;i++){
            System.out.println(res[i]);
        }
        sc.close();
    }
    public int[] solve(final int[] A) {
        int [] arr=new int[n];
        arr=A;
        int low=0,high=n-1;
        while(low<high){
            int temp=arr[low];
            arr[low]=arr[high];
            arr[high]=temp;
            low++;
            high--;
        }
        return arr;
    }
}
