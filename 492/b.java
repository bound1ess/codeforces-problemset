import java.util.Scanner;
import java.util.Arrays;

public class b {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt(), l = in.nextInt();
        int[] a = new int[n];

        for (int i = 0; i < n; i++) a[i] = in.nextInt();

        in.close();

        Arrays.sort(a);

        double max = Math.max((double)a[0], (double)(l - a[n - 1]));

        for (int i = 1; i < n; i++) {
            max = Math.max((a[i] - a[i - 1]) / 2.0, max);
        }

        System.out.printf("%.10f\n", max);
    }
}
