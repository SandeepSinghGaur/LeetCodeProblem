import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class SecondLargest {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Integer[] a = new Integer[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        sc.close();
        List<Integer> l = Arrays.asList(a);
        ArrayList<Integer> A = new ArrayList<>();
        A.addAll(l);
        int res = solve(A);
        System.out.println(res);

    }

    public static int solve(ArrayList<Integer> A) {
        int firstMax = -1;
        int secondMax = -1;
        boolean check = true;
        for (int a : A) {
            if (a > firstMax) {
                secondMax = firstMax;
                firstMax = a;
                check = false;
            } else if (a < firstMax && a > secondMax) {
                secondMax = a;
                check = false;
            }
        }
        if (check)
            return -1;
        return secondMax;
    }
}
