import java.util.Scanner;

public class b {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt(), m = sc.nextInt(), k = sc.nextInt();
    int[][] calls = new int[n][m];

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        calls[i][j] = sc.nextInt();
      }
    }

    sc.close();
    int[] deadlock = new int[n], answer = new int[n];

    for (int i = 0; i < m; ++i) {
      int[] counter = new int[k + 1];

      for (int j = 0; j < n; ++j) {
        if (deadlock[j] > 0) {
          calls[j][i] = deadlock[j];
        }

        ++counter[calls[j][i]];
      }

      for (int j = 0; j < n; ++j) {
        if (calls[j][i] > 0 && counter[calls[j][i]] > 1 && deadlock[j] < 1) {
          answer[j] = i + 1;
          deadlock[j] = calls[j][i];
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      System.out.println(answer[i]);
    }
  }
}
