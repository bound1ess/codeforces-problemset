import java.util.Scanner;

public class a {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt(), m = sc.nextInt();

        sc.close();

        if (m > n) {
            System.out.println(-1);
            return;
        }

        int steps = (n / 2) + (n % 2);

        while (steps % m != 0 && steps <= n) {
            steps++;
        }

        System.out.println(steps % m == 0 ? steps : -1);
    }
}
