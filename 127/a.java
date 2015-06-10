import java.util.Scanner;

public class a {

    public static void main(final String[] arguments) {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt(), k = input.nextInt();
        int x = input.nextInt(), y = input.nextInt();

        double distance = 0.0;

        for (int i = 0; i < n - 1; i++) {
            int new_x = input.nextInt(), new_y = input.nextInt();
            distance += findDistance(x, y, new_x, new_y);
            x = new_x; y = new_y;
        }

        input.close();

        System.out.printf("%.9f\n", (distance * k) / 50.0);
    }

    private static double findDistance(int from_x, int from_y, int to_x, int to_y) {
        if (from_x == to_x) {
            return (double) Math.abs(from_y - to_y);
        }

        if (from_y == to_y) {
            return (double) Math.abs(from_x - to_x);
        }

        return Math.sqrt(
            Math.pow(Math.abs(from_x - to_x), 2.0) + Math.pow(Math.abs(from_y - to_y), 2.0)
        );
    }
}
