import java.util.Scanner;

public class a {

  private static final int MOD = 256;

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String input = sc.nextLine();
    int prev = 0, curr, ans;
    sc.close();

    for (int i = 0, n = input.length(); i < n; ++i) {
      StringBuilder tmp = new StringBuilder(Integer.toBinaryString((int) input.charAt(i)))
        .reverse();

      while (tmp.length() != MOD / 32) {
        tmp.append('0');
      }

      curr = Integer.parseInt(tmp.toString(), 2);
      ans = (prev - curr) % MOD;

      if (ans < 0) {
        ans += MOD;
      }

      System.out.println(ans);
      prev = curr;
    }
  }
}
