import java.util.Scanner;
import java.math.BigInteger;

public class a {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    BigInteger n = sc.nextBigInteger(), k = sc.nextBigInteger(), two = BigInteger.valueOf(2);
    sc.close();

    BigInteger j = n.add(BigInteger.ONE).divide(two);

    if (j.compareTo(k) >= 0) {
      System.out.println(k.multiply(two).subtract(BigInteger.ONE));
    } else {
      System.out.println(k.subtract(n.add(BigInteger.ONE).divide(two)).multiply(two));
    }
  }
}
