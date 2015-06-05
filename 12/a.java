import java.util.Scanner;

public class a {
    private static final int N = 3;

    public static void main(final String[] args) {
        Scanner sc = new Scanner(System.in);
        boolean[][] map = new boolean[N][N];

        for (int i = 0; i < N; i++) {
            String row = sc.nextLine();

            for (int j = 0; j < N; j++) {
                map[i][j] = row.charAt(j) == 'X';
            }
        }

        sc.close();

        for (int i = 0; i <= N / 2; i++) {
            for (int j = 0; j < (i != N / 2 ? N : N / 2); j++) {
                if (map[i][j] != map[N - 1 - i][N - 1 - j]) {
                    System.out.println("NO");
                    return;
                }
            }
        }

        System.out.println("YES");
    }
}
