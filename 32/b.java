import java.util.Scanner;

public class b {

  public static void main(String[] args) {
    String code = new Scanner(System.in).nextLine();
    StringBuilder answer = new StringBuilder();

    for (int i = 0, n = code.length(); i < n; ++i) {
      if (code.charAt(i) == '.') {
        answer.append('0');
        continue;
      }

      if (code.charAt(i + 1) == '-') {
        answer.append('2');
      } else {
        answer.append('1');
      }

      ++i;
    }

    System.out.println(answer.toString());
  }
}
