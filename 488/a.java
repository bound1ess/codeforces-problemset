import java.util.Scanner;

public class a {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt(), ans = 0;
        sc.close();

        do {
            ans++;
            a++;
        }
        while ( ! isLucky(a));

        System.out.println(ans);
    }

    private static boolean isLucky(int a) {
        a = Math.abs(a);

        while (a > 0) {
            if (a % 10 == 8) {
                return true;
            }

            a /= 10;
        }

        return false;
    }
}
