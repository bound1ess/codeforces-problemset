import java.util.Scanner;
import java.util.Arrays;
public class a {
    public static void main(final String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt();
        char[][] grid = new char[n][m];
        for (int i = 0; i < n; i++) {
            String row = sc.next();
            for (int j = 0; j < m; j++) {
                grid[i][j] = row.charAt(j);
            }
        }
        int answer = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m - 1; j++) {
                char[] chars = {
                    grid[i][j], grid[i][j + 1], grid[i + 1][j], grid[i + 1][j + 1]
                };
                Arrays.sort(chars);
                if (new String(chars).equals("acef")) {
                    answer++;
                }
            }
        }
        System.out.println(answer);
    }
}
