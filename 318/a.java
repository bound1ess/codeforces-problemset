import java.util.Scanner;
import java.math.BigInteger;

public class a {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        BigInteger n = in.nextBigInteger(), k = in.nextBigInteger();

        in.close();

        BigInteger j = n.add(BigInteger.valueOf(1)).divide(BigInteger.valueOf(2));

        if (j.compareTo(k) >= 0) {
            System.out.println(
                k.multiply(BigInteger.valueOf(2)).subtract(BigInteger.valueOf(1))
            );
        } else {
            System.out.println(
                k.subtract(
                    n.add(BigInteger.valueOf(1)).divide(BigInteger.valueOf(2))
                ).multiply(BigInteger.valueOf(2))
            );
        }
    }
}
