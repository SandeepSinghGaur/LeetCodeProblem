import java.util.Scanner;

public class SearchElement {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t > 0) {
            boolean check = true;
            int n = sc.nextInt();
            int[] A = new int[n];
            for (int i = 0; i < n; i++) {
                A[i] = sc.nextInt();
            }
            int B = sc.nextInt();
            for (int i = 0; i < n; i++) {
                if (A[i] == B) {
                    System.out.println(1);
                    check = false;
                    break;
                }
            }
            if (check)
                System.out.println(0);
            t--;
        }
        sc.close();

    }
}
