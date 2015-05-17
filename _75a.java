import java.util.Scanner;
import java.util.Vector;

public class _75a {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        long a = scan.nextInt();
        long b = scan.nextInt();
        long sum = a + b;

        System.out.println(change(sum) == change(a) + change(b) ? "YES" : "NO");
    }

    private static long change(long num) {
        Vector<Integer> digits = new Vector<Integer>();

        while (num > 0) {
            if (num % 10 > 0) {
                digits.add((int)(num % 10));
            }

            num /= 10;
        }

        for (int i = digits.size() - 1; i >= 0; i--) {
            num *= 10;
            num += digits.get(i);
        }

        //System.out.println("Produced " + num);
        return num;
    }
}
