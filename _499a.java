import java.util.Scanner;

public class _499a {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt(), x = sc.nextInt();
        int[] l = new int[n], r = new int[n];

        for (int i = 0; i < n; i++) {
            l[i] = sc.nextInt();
            r[i] = sc.nextInt();
        }

        int ans = (l[0] - 1) % x;

        for (int i = 0; i < n; i++) {
            ans += (r[i] - l[i]) + 1;
        }

        for (int i = 1; i < n; i++) {
            ans += (l[i] - (1 + r[i - 1])) % x;
        }

        System.out.println(ans);
    }
}
