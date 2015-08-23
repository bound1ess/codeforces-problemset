import java.util.Scanner;

public class b {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    char[] chars = sc.nextLine().toCharArray();
    int m = sc.nextInt();
    int[] rev = new int[chars.length / 2];

    for (int i = 0; i < m; ++i) {
      ++rev[sc.nextInt() - 1];
    }

    sc.close();
    int tmp = 0;

    for (int i = 0; i < chars.length / 2; ++i) {
      tmp = (tmp + rev[i]) % 2;

      if (tmp > 0) {
        char tmpChar = chars[i];
        chars[i] = chars[chars.length - 1 - i];
        chars[chars.length - 1 - i] = tmpChar;
      }
    }

    System.out.println(new String(chars));
  }
}
