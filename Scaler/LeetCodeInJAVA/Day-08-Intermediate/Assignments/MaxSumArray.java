
import java.util.*;
public class MaxSumArray{
    public static void main(String args[]){
        Integer [] i={-2, 1, -3, 4, -1, 2, 1, -5, 4};
        List<Integer>l=Arrays.asList(i);
        System.out.println(maxSubArray1(l));
    }

        public static int maxSubArray1(final List<Integer> A) {
            int sum=0; 
          int max_val=Integer.MIN_VALUE;
          for(int a : A){
              sum+=a;
              max_val=Math.max(sum,max_val);
              if(sum<0){
                  sum=0;
              }
          } 
          return max_val;
      }
 }
 