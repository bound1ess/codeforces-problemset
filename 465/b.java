import java.util.Scanner;

public class b {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        int[] a = new int[n], sum = new int[n];

        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
            sum[i] = a[i];

            if (i > 0) {
                sum[i] += sum[i - 1];
            }
        }

        in.close();

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int j = i, streak = 1;

            while (j + 1 < n && a[j] == a[j + 1]) {
                j++;
                streak++;
            }

            if (a[i] < 1) {
                if (i > 0 && (sum[n - 1] - sum[j]) > 0) {
                    ans++;
                }
            } else {
                ans += streak;
            }

            i = j;
        }

        System.out.println(ans);
    }
}
