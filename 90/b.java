import java.util.Scanner;

public class b {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt(), m = sc.nextInt();
        char[][] grid = new char[n][m];
        boolean[][] crossedOut = new boolean[n][m];

        sc.nextLine();

        for (int i = 0; i < n; i++) {
            String line = sc.nextLine();

            for (int j = 0; j < m; j++) {
                grid[i][j] = line.charAt(j);
                crossedOut[i][j] = false;
            }
        }

        sc.close();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (countCharsInColumn(grid[j][i], grid, i) > 1) {
                    crossedOut[j][i] = true;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (countCharsInRow(grid[i][j], grid[i]) > 1) {
                    crossedOut[i][j] = true;
                }
            }
        }

        StringBuilder word = new StringBuilder();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ( ! crossedOut[i][j]) {
                    word.append(grid[i][j]);
                }
            }
        }

        System.out.println(word.toString());
    }

    private static int countCharsInRow(char chr, final char[] chars) {
        int counter = 0;

        for (int i = 0; i < chars.length; i++) {
            if (chars[i] == chr) {
                counter++;
            }
        }

        return counter;
    }

    private static int countCharsInColumn(char chr, final char[][] grid, int column) {
        int counter = 0;

        for (int i = 0; i < grid.length; i++) {
            if (grid[i][column] == chr) {
                counter++;
            }
        }

        return counter;
    }
}
