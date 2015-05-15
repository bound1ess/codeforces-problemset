import java.util.Scanner;

public class _510a {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt();
        int m = scan.nextInt();
        int end = m - 1;

        for (int i = 0; i < n; i++) {
            boolean print_end = true;

            for (int j = 0; j < m; j++) {
                if (i % 2 == 0) {
                    System.out.print('#');
                } else if (print_end && j == end) {
                    print_end = false;

                    if (end == m - 1) {
                        end = 0;
                    } else {
                        end = m - 1;
                    }

                    System.out.print('#');
                } else {
                    System.out.print('.');
                }
            }

            System.out.println(new String());
        }
    }
}
