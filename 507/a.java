import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Map.Entry;
import java.util.AbstractMap.SimpleEntry;
import java.util.Comparator;

public class a {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt(), k = sc.nextInt();
    List<Entry<Integer, Integer>> a = new ArrayList<>();

    for (int i = 0; i < n; ++i) {
      a.add(new SimpleEntry<Integer, Integer>(i + 1, sc.nextInt()));
    }

    sc.close();
    Collections.sort(a, new CustomComparator());
    int upto = 0, sum = 0;

    while (upto < n) {
      if (sum + a.get(upto).getValue() <= k) {
        sum += a.get(upto++).getValue();
      } else {
        break;
      }
    }

    System.out.println(upto);

    if (1 > upto) {
      return;
    }

    for (int i = 0; i < upto; ++i) {
      System.out.print(a.get(i).getKey());
      System.out.print(i + 1 < upto ? " " : System.lineSeparator());
    }
  }

  private static class CustomComparator implements Comparator<Entry<Integer, Integer>> {

    public int compare(Entry<Integer, Integer> one, Entry<Integer, Integer> two) {
      if (one.getValue() == two.getValue()) {
        return 0;
      }

      return one.getValue() > two.getValue() ? 1 : -1;
    }
  }
}
