import java.util.Scanner;

public class a {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    String[] a = new String[n];
    sc.nextLine();

    for (int i = 0; i < n; ++i) {
      a[i] = sc.nextLine();
    }

    sc.close();

    for (int i = 0; i < n; ++i) {
      boolean end = a[i].endsWith("lala."), begin = a[i].startsWith("miao.");

      if (begin && end) {
        System.out.println("OMG>.< I don't know!");
        continue;
      }

      if (end) {
        System.out.println("Freda's");
      }

      if (begin) {
        System.out.println("Rainbow's");
      }

      if ( ! begin && ! end) {
        System.out.println("OMG>.< I don't know!");
      }
    }
  }
}
