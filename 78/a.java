import java.util.Scanner;

public class a {
  private static final String vowels = "aeiou";
  private static final int[] format = {5, 7, 5};
  private static final int N = 3;

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    boolean ans = true;

    for (int i = 0; i < N; ++i) {
      String str = in.nextLine();
      int count = 0;

      if ( ! ans) {
        continue;
      }

      for (int j = 0; j < str.length(); ++j) {
        if (vowels.indexOf(str.charAt(j)) >= 0) {
          ++count;
        }

        if (count > format[i]) {
          break;
        }
      }

      if (count != format[i]) {
        ans = false;
      }
    }

    System.out.println(ans ? "YES" : "NO");
  }
}
