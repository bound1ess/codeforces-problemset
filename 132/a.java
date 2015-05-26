import java.util.Scanner;

public class a {
    private static final int MOD = 256;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        sc.close();

        int prev = 0, curr, ans;

        for (int i = 0; i < input.length(); i++) {
            StringBuilder tmp = new StringBuilder(
                Integer.toBinaryString((int) input.charAt(i))
            ).reverse();

            while (tmp.length() != MOD / 32) {
                tmp.append('0');
            }

            curr = Integer.parseInt(tmp.toString(), 2);

            ans = (prev - curr) % MOD;

            if (ans < 0) {
                ans += MOD;
            }

            System.out.println(ans);

            prev = curr;
        }
    }
}
