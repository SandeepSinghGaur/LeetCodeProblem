import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class LittlePonny {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Integer[] a = new Integer[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int B = sc.nextInt();
        sc.close();
        List<Integer> A = Arrays.asList(a);
        ArrayList<Integer> l = new ArrayList<>();
        l.addAll(A);
        int res = solve(l, B);
        System.out.println(res);

    }

    public static int solve(ArrayList<Integer> A, int B) {
        boolean check = true;
        int op = 0;
        for (int a : A) {
            if (a > B) {
                op++;
            } else if (a == B) {
                check = false;
            }
        }
        if (check)
            return -1;
        return op;
    }
}
