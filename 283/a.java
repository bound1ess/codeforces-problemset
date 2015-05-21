import java.util.Scanner;
import java.util.ArrayList;

public class _283a {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int sum = 0;

        ArrayList<Integer> arr = new ArrayList<Integer>();

        arr.add(0);

        for (int i = 0; i < n; i++) {
            int t = sc.nextInt();

            if (t == 3) {
                if (arr.size() >= 2) {
                    sum -= arr.get(arr.size() - 1);
                    arr.remove(arr.size() - 1);
                    arr.trimToSize();
                }
            } else if (t == 2) {
                int val = sc.nextInt();

                sum += val;
                arr.add(val);
            } else {
                int a = sc.nextInt();
                int x = sc.nextInt();

                for (int j = 0; j < a; j++) {
                    arr.set(j, arr.get(j) + x);
                }

                sum += a * x;
            }

            //int sum = 0;

            //for (int j = 0; j < arr.size(); j++) {
            //    sum += arr.get(j);
            //}

            //System.out.println("Sum is " + sum + ", size is " + arr.size());
            System.out.printf("%.6f\n", (double)sum / arr.size());
        }
    }
}
