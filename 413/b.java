import java.util.Scanner;

public class b {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt(), m = sc.nextInt(), k = sc.nextInt();
    int[][] membership = new int[n][m];

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        membership[i][j] = sc.nextInt();
      }
    }

    int[] members = new int[n], chats = new int[m];

    for (int i = 0; i < k; ++i) {
      int x = sc.nextInt() - 1, y = sc.nextInt() - 1;
      ++chats[y];
      --members[x];
    }

    sc.close();

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (membership[i][j] > 0) {
          members[i] += chats[j];
        }
      }

      System.out.print(members[i]);
      System.out.print(i + 1 < n ? " " : "\n");
    }
  }
}
