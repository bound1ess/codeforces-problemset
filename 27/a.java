import java.util.Scanner;
import java.util.Arrays;

public class a {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        Arrays.sort(arr);

        if (arr[0] > 1) {
            System.out.println(1);
            return;
        }

        for (int i = 0; i < n - 1; i++) {
            if (arr[i] + 1 != arr[i + 1]) {
                System.out.println(arr[i] + 1);
                return;
            }
        }

        System.out.println(arr[n - 1] + 1);
    }
}
