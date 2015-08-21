import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;

public class a {

  public static void main(final String[] arguments) {
    Scanner input = new Scanner(System.in);
    int n = Integer.parseInt(input.nextLine()), maxReposts = 0;
    Map<String, Integer> reposts = new HashMap<>();
    reposts.put("polycarp", 1);

    for (int i = 0; i < n; ++i) {
      String[] words = input.nextLine().toLowerCase().split(" ");
      reposts.put(words[0], reposts.get(words[2]) + 1);
      maxReposts = Math.max(maxReposts, reposts.get(words[0]));
    }

    System.out.println(maxReposts);
  }
}
