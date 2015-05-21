import java.util.Scanner;
import java.util.ArrayList;

public class b {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        ArrayList<Integer> h = new ArrayList<Integer>(n);

        h.add(0); // h0

        for (int i = 0; i < n; i++) {
            h.add(sc.nextInt());
        }

        int energy = 0, buy = 0;

        for (int i = 0; i < n; i++) {
            int jump = h.get(i) - h.get(i + 1);

            while (energy + jump < 0) {
                buy++;
                jump++;
            }

            energy += jump;
        }

        System.out.println(buy);
    }
}
