import java.util.Scanner;

public class a {
  private final static String quality = "6789TJQKA";

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String suit = sc.nextLine();
    String[] cards = sc.nextLine().split("\\s");
    sc.close();

    if (cards[0].substring(1).equals(suit)) {
      if ( ! cards[1].substring(1).equals(suit)) {
        System.out.println("YES");
        return;
      }
    }

    if ( ! cards[0].substring(1).equals(cards[1].substring(1))) {
      System.out.println("NO");
      return;
    }

    int l = quality.indexOf(cards[0].substring(0, 1));
    int r = quality.indexOf(cards[1].substring(0, 1));

    System.out.println(l > r ? "YES" : "NO");
  }
}
