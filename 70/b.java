import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class b {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    List<String> parts = new ArrayList<>();
    int len = Integer.parseInt(sc.nextLine()), maxLen = 0;
    String msg = sc.nextLine();
    sc.close();

    for (String part: split(msg)) {
      maxLen = Math.max(part.length(), maxLen);
      parts.add(part);
    }

    if (maxLen > len) {
      System.out.println("Impossible");
    } else {
      int count = 0;

      while (parts.size() > 0) {
        int tmpLen = parts.get(0).length(), tmpCount = 1;
        parts.remove(0);

        while (parts.size() > 0 && tmpLen + tmpCount + parts.get(0).length() <= len) {
          tmpLen += parts.get(0).length();
          ++tmpCount;
          parts.remove(0);
        }

        ++count;
      }

      System.out.println(count);
    }
  }

  private static List<String> split(String msg) {
    Matcher matcher = Pattern.compile("([\\sa-zA-Z]+)(\\.|\\!|\\?)").matcher(msg);
    List<String> parts = new ArrayList<>();

    while (matcher.find()) {
      parts.add(matcher.group(0).trim());
    }

    return parts;
  }
}
