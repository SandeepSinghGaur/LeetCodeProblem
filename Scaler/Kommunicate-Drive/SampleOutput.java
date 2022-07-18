
public class SampleOutput {

    public static void main(String args[]) {

        String s1 = "string1";
        String s2 = new String("string2");
        
        if (s1 == s2) {
            System.out.println("print 1");

        } else {

            System.out.println("print 2");
        }
        
        if (s1.equals(s2)) {

            System.out.println("print 3");
        } else {

            System.out.println("print 4");
        }

   }
}
/*
 * print2
 * print4
 */
