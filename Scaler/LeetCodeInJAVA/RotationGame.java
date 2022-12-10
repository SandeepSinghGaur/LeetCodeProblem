import java.util.Scanner;

public class RotationGame {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] A = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = sc.nextInt();
        }
        int k = sc.nextInt();
        sc.close();
        int p=k%n;
        k=n-k;
        reverseArray(A, 0, p-1);
        reverseArray(A, p, n - 1);
        reverseArray(A, 0, n - 1);
        for (int a : A) {
            System.out.print(a + " ");
        }
    }

    public static void reverseArray(int[] A, int s, int e) {
        while (s <= e) {
            int temp = A[s];
            A[s] = A[e];
            A[e] = temp;
            s++;
            e--;
        }
    }
}
