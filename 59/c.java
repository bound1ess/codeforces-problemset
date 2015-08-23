import java.util.Scanner;

public class c {

  private static int MAGIC = 128;

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int k = Integer.parseInt(sc.nextLine());
    char[] chars = sc.nextLine().toCharArray();
    boolean[] used = new boolean[MAGIC];
    sc.close();

    for (int i = 0; i < chars.length; ++i) {
      if (chars[i] == '?') {
        continue;
      }

      int j = chars.length - i - 1;

      if (chars[j] == '?') {
        chars[j] = chars[i];
      } else {
        if (chars[i] != chars[j]) {
          System.out.println("IMPOSSIBLE");
          return;
        }
      }
    }

    for (int i = 0; i < chars.length; ++i) {
      used[(int) chars[i]] = true;
    }

    int chr = k - 1 + 'a';

    for (int i = chars.length / 2; i >= 0; --i) {
      while (used[chr] && chr >= 'a') {
        --chr;
      }

      if (chars[i] != '?') {
        continue;
      }

      int j = chars.length - i - 1;

      if (chr >= 'a') {
        chars[i] = (char) chr;
        chars[j] = (char) chr;
        --chr;
      } else {
        chars[i] = 'a';
        chars[j] = 'a';
      }
    }

    while (used[chr] && chr >= 'a') {
      --chr;
    }

    System.out.println(chr >= 'a' ? "IMPOSSIBLE" : new String(chars));
  }
}
