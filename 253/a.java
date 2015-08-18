import java.util.Scanner;
import java.io.File;
import java.io.PrintStream;
import java.io.FileNotFoundException;

public class a {

  public static void main(String[] args) throws FileNotFoundException {
    Scanner sc = new Scanner(new File("input.txt"));
    PrintStream out = new PrintStream("output.txt");

    int n = sc.nextInt(), m = sc.nextInt();
    int k = (n > m) ? m : n;

    for (int i = 0; i < (n - k); i++) {
      out.print('B');
    }

    for (int i = 0; i < k; i++) {
      out.print("GB");
    }

    for (int i = 0; i < (m - k); i++) {
      out.print('G');
    }

    out.print("\n");
    out.close();
  }
}
