import java.util.Scanner;

public class a {

    public static void main(final String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt(), m = sc.nextInt();
        char[][] map = new char[n][m];

        for (int i = 0; i < n; i++) {
            String row = sc.next();

            for (int j = 0; j < m; j++) {
                map[i][j] = row.charAt(j);
            }
        }

        sc.close();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] != '-') {
                    map[i][j] = (i + j) % 2 == 0 ? 'B' : 'W';
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= m; j++) {
                System.out.print(j != m ? map[i][j] : "\n");
            }
        }
    }
}
