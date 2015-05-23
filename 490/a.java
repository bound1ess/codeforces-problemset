import java.util.Scanner;

public class a {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        int[] a = new int[3];
        int[][] t = new int[3][n];

        for (int i = 0; i < n; i++) {
            int val = in.nextInt();

            t[val - 1][a[val - 1]] = i + 1;
            a[val - 1]++;
        }

        in.close();

        int ans = Math.min(Math.min(a[0], a[1]), a[2]);

        System.out.println(ans);

        for (int i = 0; i < ans; i++) {
            System.out.println(t[0][i] + " " + t[1][i] + " " + t[2][i]);
        }
    }
}
