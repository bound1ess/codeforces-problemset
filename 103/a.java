import java.util.Scanner;
import java.math.BigInteger;

public class a {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    BigInteger ans = BigInteger.ZERO;
    int n = sc.nextInt();

    for (int i = 0; i < n; i++) {
      ans = ans.add(sc.nextBigInteger().multiply(BigInteger.valueOf(i + 1)));
      ans = ans.subtract(BigInteger.valueOf(i));
    }

    sc.close();
    System.out.println(ans);
  }
}
