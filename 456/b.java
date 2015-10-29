import java.util.Scanner;
import java.math.BigInteger;

public class b {
  public static void main(String[] args) {
    BigInteger n = new Scanner(System.in).nextBigInteger().mod(BigInteger.valueOf(4));
    BigInteger sum = BigInteger.ZERO;
    for (int i = 1; i <= 4; ++i) {
      sum = sum.add(BigInteger.valueOf(i).modPow(n, BigInteger.valueOf(5)));
    }
    System.out.println(sum.mod(BigInteger.valueOf(5)));
  }
}
