import java.util.Scanner;

public class a {

    public static void main(String[] args) {
        int n = new Scanner(System.in).nextInt();
        int width = 1, step = 2;

        for (int i = 0; i < n; i++) {
            int offset = (n - width) / 2;

            if (i == n / 2) {
                step *= -1;
            }

            for (int j = 0; j < offset; j++) {
                System.out.print('*');
            }

            for (int j = 0; j < width; j++) {
                System.out.print('D');
            }

            for (int j = 0; j <= offset; j++) {
                System.out.print(j != offset ? '*' : "\n");
            }

            width += step;
        }
    }
}
