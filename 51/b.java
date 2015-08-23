import java.util.Scanner;
import java.util.Collections;
import java.util.List;
import java.util.ArrayList;

public class b {

  private static int MAGIC = 5000;

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    StringBuilder input = new StringBuilder();

    while (sc.hasNextLine()) {
      input.append(sc.nextLine());
    }

    sc.close();
    List<Integer> answer = solve(input.toString());
    Collections.sort(answer);

    for (Integer number: answer) {
      System.out.print(number + " ");
    }

    System.out.println();
  }

  private static List<Integer> solve(String input) {
    List<Integer> output = new ArrayList<>();
    int[] tdElems = new int[MAGIC];
    int depth = -1;
    String[] tokens = tokenize(input);

    for (String token: tokens) {
      switch (token) {
        case "td":
          ++tdElems[depth];
          break;

        case "/table":
          output.add(tdElems[depth--]);
          break;

        case "table":
          tdElems[++depth] = 0;
      }
    }

    return output;
  }

  private static String[] tokenize(String input) {
    return input.replaceAll("[\\<\\>]+", " ").split("\\s+");
  }
}
