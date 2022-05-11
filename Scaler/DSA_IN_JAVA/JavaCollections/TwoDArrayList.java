
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Set;

public class TwoDArrayList{
        static ArrayList<ArrayList<Integer> >create2DArrayList()
        {
     
            ArrayList<ArrayList<Integer> > x
                = new ArrayList<ArrayList<Integer> >();
            x.add(new ArrayList<Integer>());
            x.get(0).add(0, 3);
            x.add(
                new ArrayList<Integer>(Arrays.asList(3, 4, 6)));
            x.get(1).add(0, 366);
            x.get(1).add(4, 576);
            x.add(2, new ArrayList<>(Arrays.asList(3, 84)));
     
            // Adding values to R3
            x.add(new ArrayList<Integer>(
                Arrays.asList(83, 6684, 776)));
     
            // Adding values to R4
            x.add(new ArrayList<>(Arrays.asList(8)));
     
            // Appending values to R4
            x.get(4).addAll(Arrays.asList(9, 10, 11));
     
            // Appending values to R1, but start appending from
            // C3
            x.get(1).addAll(3, Arrays.asList(22, 1000));
     
            // This method will return 2D array
            return x;
        }

        static LinkedHashSet<LinkedHashSet<String> > create2DLinkedHashSet()
        {
            LinkedHashSet<LinkedHashSet<String> > x
            = new LinkedHashSet<LinkedHashSet<String> >();
 
        // Creating R0
        x.add(new LinkedHashSet<String>(
            Arrays.asList("Apple", "Orange")));
 
        // Creating R1, here "Coffee" will be considered as
        // only one object to maintain uniqueness
        x.add(new LinkedHashSet<String>(Arrays.asList(
            "Tea", "Coffee", "Milk", "Coffee", "Water")));
 
        // Creating R2
        x.add(new LinkedHashSet<String>(
            Arrays.asList("Tomato", "Potato", "Onion")));
 
        // Creating R3 but it will not be added as it
        // contains the same items as R2
 
        // Note: LinkedHashSet inserts only unique items
 
        x.add(new LinkedHashSet<String>(
            Arrays.asList("Tomato", "Potato", "Onion")));
 
        // Returning multidimensional LinkedHashSet
        return x;
        }
          
     
        public static void main(String args[])
        {
            System.out.println("2D ArrayList :");
            System.out.println(create2DArrayList());
            System.out.println("2D LinkedHashSet :");
            System.out.println(create2DLinkedHashSet());
        }
}
