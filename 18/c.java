import java.util.Scanner;

public class c {

    public static void main(final String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            if (i > 0) {
                a[i] += a[i - 1];
            }
        }
        sc.close();
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] == a[n - 1] - a[i]) {
                ans++;
            }
        }
        System.out.println(ans);
    }
}
