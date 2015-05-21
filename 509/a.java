import java.util.Scanner;

public class _509a {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();

        in.close();

        int[][] map = new int[n][n];

        for (int i = 0; i < n; i++) {
            if (i > 0) {
                map[i][0] = 1;
                continue;
            }

            for (int j = 0; j < n; j++) {
                map[0][j] = 1;
            }
        }

        int max = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                map[i][j] = map[i][j - 1] + map[i - 1][j];

                if (map[i][j] > max) {
                    max = map[i][j];
                }
            }
        }

        System.out.println(max);
    }
}
