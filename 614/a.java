import java.util.Scanner;
import java.util.ArrayList;
import java.math.BigInteger;

public class a {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    BigInteger l = sc.nextBigInteger(), r = sc.nextBigInteger(), k = sc.nextBigInteger();
    BigInteger n = BigInteger.ONE;
    ArrayList<BigInteger> powers = new ArrayList<>();
    sc.close();
    while (lessOrEqual(n, r)) {
      if (greaterOrEqual(l, n)) {
        powers.add(n);
      }
      n = n.multiply(k);
    }
    if (powers.isEmpty()) {
      System.out.println(-1);
    } else {
      for (int i = 0, m = powers.size(); i < m; ++i) {
        if (i > 0) {
          System.out.print(' ');
        }
        System.out.print(powers.get(i));
      }
      System.out.println();
    }
  }

  private static boolean lessOrEqual(BigInteger l, BigInteger r) {
    return l.compareTo(r) == 0 || l.compareTo(r) == -1;
  }

  private static boolean greaterOrEqual(BigInteger l, BigInteger r) {
    return r.compareTo(l) == 0 || r.compareTo(l) == 1;
  }
}
