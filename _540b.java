import java.util.Scanner;

public class _540b {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int k = sc.nextInt();
        int p = sc.nextInt();
        int x = sc.nextInt();
        int y = sc.nextInt();

        int[] a = new int[n];

        int m = (n + 1) / 2;
        int l = 0, sum = 0;

        for (int i = 0; i < k; i++) {
            a[i] = sc.nextInt();
            sum += a[i];

            if (a[i] < y) {
                l++;
            }
        }

        if (l >= m) {
            System.out.println(-1);
            return;
        }

        int fill = (m - l - 1) > (n - k) ? (n - k) : (m - l - 1);

        if (x < ((n - k - fill) * y) + fill + sum) {
            System.out.println(-1);
            return;
        }

        for (int i = 0; i < fill; i++) {
            System.out.print("1 ");
        }

        for (int i = 0; i < n - k - fill; i++) {
            System.out.print(y + " ");
        }

        System.out.println("");
    }
}
