import java.util.Scanner;

public class a {

    private enum CellState {
        EVIL, FREE, EATEN
    }

    public static void main(final String[] arguments) {
        final Scanner input = new Scanner(System.in);
        final int n = input.nextInt(), m = input.nextInt();
        CellState[][] cake = new CellState[n][m];

        for (int i = 0; i < n; i++) {
            String row = input.next();

            for (int j = 0; j < m; j++) {
                cake[i][j] = row.charAt(j) == 'S' ? CellState.EVIL : CellState.FREE;
            }
        }

        input.close();

        int cellsToEat = 0;

        // from left to right
        for (int i = 0; i < n; i++) {
            int freeCells = 0;

            for (int j = 0; j < m; j++) {
                if (cake[i][j] == CellState.EVIL) {
                    freeCells = 0;
                    break;
                } else if (cake[i][j] == CellState.FREE) {
                    freeCells++;
                    //cake[i][j] = CellState.EATEN;
                }
            }

            if (freeCells > 0) {
                for (int j = 0; j < m; j++) {
                    if (cake[i][j] == CellState.FREE) {
                        cake[i][j] = CellState.EATEN;
                    }
                }
            }

            cellsToEat += freeCells;
        }

        // from top to bottom
        for (int j = 0; j < m; j++) {
            int freeCells = 0;

            for (int i = 0; i < n; i++) {
                if (cake[i][j] == CellState.EVIL) {
                    freeCells = 0;
                    break;
                } else if (cake[i][j] == CellState.FREE) {
                    freeCells++;
                    //cake[i][j] = CellState.EATEN;
                }
            }

            cellsToEat += freeCells;
        }

        System.out.println(cellsToEat);
    }
}
