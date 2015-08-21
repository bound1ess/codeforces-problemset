import java.util.Scanner;

public class a {
  private enum CellState {EVIL, FREE, EATEN}

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt(), m = in.nextInt();
    CellState[][] cake = new CellState[n][m];

    for (int i = 0; i < n; ++i) {
      String row = in.next();

      for (int j = 0; j < m; ++j) {
        cake[i][j] = row.charAt(j) == 'S' ? CellState.EVIL : CellState.FREE;
      }
    }

    in.close();
    int cellsToEat = 0;

    for (int i = 0; i < n; ++i) {
      int freeCells = 0;

      for (int j = 0; j < m; ++j) {
        if (cake[i][j] == CellState.EVIL) {
          freeCells = 0;
          break;
        }

        if (cake[i][j] == CellState.FREE) {
          ++freeCells;
        }
      }

      if (freeCells > 0) {
        for (int j = 0; j < m; ++j) {
          if (cake[i][j] == CellState.FREE) {
            cake[i][j] = CellState.EATEN;
          }
        }
      }

      cellsToEat += freeCells;
    }

    for (int j = 0; j < m; ++j) {
      int freeCells = 0;

      for (int i = 0; i < n; ++i) {
        if (cake[i][j] == CellState.EVIL) {
          freeCells = 0;
          break;
        }

        if (cake[i][j] == CellState.FREE) {
          ++freeCells;
        }
      }

      cellsToEat += freeCells;
    }

    System.out.println(cellsToEat);
  }
}
