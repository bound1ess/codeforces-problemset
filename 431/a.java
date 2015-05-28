import java.util.Scanner;

public class a {
    private static final int N = 4;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[] a = new int[N];
        int i = 0;

        for (String val: sc.nextLine().split("\\s")) {
            a[i++] = Integer.parseInt(val);
        }

        int sum = 0;

        for (char val: sc.nextLine().toCharArray()) {
            sum += a[val - '1'];
        }

        sc.close();

        System.out.println(sum);
    }
}
