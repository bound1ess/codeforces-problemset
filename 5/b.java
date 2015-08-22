import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class b {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    List<String> msg = new ArrayList<>();
    int maxLength = 0;

    while (sc.hasNextLine()) {
      String line = sc.nextLine();
      maxLength = Math.max(maxLength, line.length());
      msg.add(line);
    }

    int blockLength = maxLength + 2;
    int placeLeft = 1;
    System.out.println(repeat('*', blockLength));

    for (String line: msg) {
      int whitespaces = maxLength - line.length();

      if (whitespaces % 2 == 0) {
        System.out.print('*' + repeat(' ', whitespaces / 2));
        System.out.print(line);
        System.out.println(repeat(' ', whitespaces / 2) + '*');
      } else {
        int alignLeft, alignRight;

        if (placeLeft > 0) {
          alignLeft = whitespaces / 2;
          alignRight = whitespaces - alignLeft;
        } else {
          alignRight = whitespaces / 2;
          alignLeft = whitespaces - alignRight;
        }

        System.out.print('*' + repeat(' ', alignLeft));
        System.out.print(line);
        System.out.println(repeat(' ', alignRight) + '*');
        placeLeft = 1 - placeLeft;
      }
    }

    System.out.println(repeat('*', blockLength));
  }

  private static String repeat(char chr, int n) {
    char[] chars = new char[n];

    for (int i = 0; i < n; ++i) {
      chars[i] = chr;
    }

    return new String(chars);
  }
}
