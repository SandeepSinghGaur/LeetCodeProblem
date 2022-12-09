import java.util.ArrayList;
import java.util.Arrays;

class RangeSumQuery{
    public static void main(String args[]){
        int[] arr={10,20,30,40};
        NumArray num=new NumArray(arr);
        int res=num.sumRange(0, 3);

    }
}
class NumArray {
     ArrayList<Integer> al=new ArrayList<Integer>();
    public NumArray(int[] nums) {
      al=Arrays.asList(nums);
    }
    
    public int sumRange(int left, int right) {
       
        
    }
}