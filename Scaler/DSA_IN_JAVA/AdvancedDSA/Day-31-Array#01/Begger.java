import java.util.ArrayList;
import java.util.Arrays;

public class Begger
{
    public static void main(String args[]){
        ArrayList<String> letters = new ArrayList<>(
            Arrays.asList("A")
        );
        letters.add("A");
        letters.add("B");
        letters.add("C");
        System.out.println(letters);	// [A, B, C]
        ArrayList<String>namesStartWithA = new ArrayList<>();
        namesStartWithA.add("Adel");
        namesStartWithA.add("Ahmed");
        namesStartWithA.add("Ali");
        System.out.println(namesStartWithA);	// [Adel, Ahmed, Ali]
        System.out.println(letters.addAll(1,namesStartWithA)); // true
        System.out.println(letters); // [A, Adel, Ahmed, Ali, B, C]
    }


}
