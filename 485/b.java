//import java.math.BigInteger;
import java.util.Scanner;

public class b {

    public static void main(final String[] arguments) {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();

        long x, y;
        long left, right, bottom, top;

        x = input.nextLong();
        y = input.nextLong();

        left = x; right = x;
        bottom = y; top = y;

        for (int i = 0; i < n - 1; i++) {
            x = input.nextLong();
            y = input.nextLong();

            left = Math.min(left, x);
            right = Math.max(right, x);

            bottom = Math.min(bottom, y);
            top = Math.max(top, y);
        }

        input.close();

        long width = findDistance(left, right);
        long height = findDistance(bottom, top);
        long side = Math.max(width, height);

        System.out.println(side * side);
    }

    private static long findDistance(long from, long to) {
        if (from < 0L && to < 0L) {
            // both negative
            return Math.abs(from) - Math.abs(to);
        }

        return to - from;
    }
}
