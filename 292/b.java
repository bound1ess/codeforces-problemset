import java.util.Scanner;

public class b {

    public static void main(final String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt(), m = sc.nextInt();
        int[] a = new int[n];

        for (int i = 0; i < m; i++) {
            a[sc.nextInt() - 1]++;
            a[sc.nextInt() - 1]++;
        }

        sc.close();

        int min = m, minCounter = 0, max = 0, maxCounter = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] > max) {
                max = a[i];
                maxCounter = 1;
            } else if (a[i] == max) {
                maxCounter++;
            }

            if (a[i] < min) {
                min = a[i];
                minCounter = 1;
            } else if (a[i] == min) {
                minCounter++;
            }
        }

        String type = null;

        if (max == 2 && max == min) {
            type = "ring";
        } else if (max == 2 && min == 1 && minCounter == 2 && maxCounter == n - 2) {
            type = "bus";
        } else if (max == n - 1 && min == 1 && minCounter == n - 1 && maxCounter == 1) {
            type = "star";
        }

        System.out.print(type != null ? type : "unknown");
        System.out.println(" topology");
    }
}
