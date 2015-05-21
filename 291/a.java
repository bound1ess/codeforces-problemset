import java.util.Scanner;
import java.util.Arrays;

public class a {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt();
        int[] id = new int[n];

        for (int i = 0; i < n; i++) {
            id[i] = scan.nextInt();
        }

        Arrays.sort(id);

        int ans = 0, val = id[0], streak = 1;

        for (int i = 1; i < n; i++) {
            if (id[i] == val) {
                streak++;
            } else {
                if (val > 0 && streak > 2) {
                    System.out.println(-1);
                    return;
                }

                if (val > 0 && streak == 2) {
                    ans++;
                }

                val = id[i];
                streak = 1;
            }
        }

        if (val > 0 && streak > 2) {
            System.out.println(-1);
        } else {
            if (val > 0 && streak == 2) {
                //System.out.println(val);
                ans++;
            }

            System.out.println(ans);
        }
    }
}
