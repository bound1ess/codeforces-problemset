import java.util.Scanner;

public class b {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int height = n * 2 + 1;
    int step = -2;
    int offset = 2 * n;
    int width = 0;
    sc.close();

    for (int i = 0; i < height; ++i) {
      if (i == n) {
        step = 2;
      }

      for (int j = 0; j < offset; ++j) {
        System.out.print(" ");
      }

      System.out.println(createRange(width));
      offset += step;
      width += -step / 2;
    }
  }

  private static String createRange(int n) {
    StringBuilder range = new StringBuilder();

    for (int i = 0; i <= n; ++i) {
      range.append(i + " ");
    }

    for (int i = n - 1; i >= 0; --i) {
      range.append(i + " ");
    }

    return range.toString().trim();
  }
}
