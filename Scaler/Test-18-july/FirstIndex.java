
public class FirstIndex {
    public static void main(String args[]){
        int [] arr={1,2, 2,5, 5, 6, 6, 6, 6, 8, 9, 9, 9,11,12,15};
         int target=9;
         int low=0,high=arr.length-1;
         int left_side_index=-1;
         while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==target){
                left_side_index=mid;
                high=mid-1;
            }else if(arr[mid]>target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
            System.out.println(left_side_index);
      
}
}