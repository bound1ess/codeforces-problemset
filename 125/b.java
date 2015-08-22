import java.util.Scanner;

public class b {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String xml = sc.nextLine();
    int level = -1;
    sc.close();

    for (String token: xml.split("<|>")) {
      if (token.isEmpty()) {
        continue;
      }

      if ( ! token.startsWith("/")) {
        ++level;
      }

      for (int i = 0; i < level; ++i) {
        System.out.print("  ");
      }

      System.out.println("<" + token + ">");

      if (token.startsWith("/")) {
        --level;
      }
    }
  }
}
