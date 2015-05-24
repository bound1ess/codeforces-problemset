import java.util.Scanner;

public class a {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt(), m = in.nextInt();
        int[] val = new int[n], inval = new int[m];
        int minTl = 101, maxTl = 0;

        for (int i = 0; i < (n + m); i++) {
            if (i >= n) {
                inval[i - n] = in.nextInt();
                minTl = Math.min(minTl, inval[i - n]);
            } else {
                val[i] = in.nextInt();
                maxTl = Math.max(maxTl, val[i]);
            }
        }

        in.close();

        int tl = minTl - 1;

        if (tl < maxTl) {
            System.out.println(-1);
            return;
        }

        int halfTlCount = 0;

        for (int i = 0; i < n; i++) {
            if (val[i] * 2 <= tl) {
                halfTlCount++;
            }
        }

        if (halfTlCount < 1) {
            System.out.println(-1);
            return;
        }

        while (tl > maxTl && halfTlCount >= 1) {
            int newTl = tl - 1, newCount = 0;

            for (int i = 0; i < n; i++) {
                if (val[i] * 2 <= newTl) {
                    newCount++;
                }
            }

            if (newCount >= 1) {
                halfTlCount = newCount;
                tl = newTl;
            } else {
                break;
            }
        }

        System.out.println(tl);
    }
}
