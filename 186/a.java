import java.util.Scanner;
import java.util.Arrays;

public class a {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.nextLine(), b = sc.nextLine();
        sc.close();

        if (a.length() != b.length()) {
            System.out.println("NO");
        } else {
            int diffCount = 0;

            for (int i = 0; i < a.length(); i++) {
                if (a.charAt(i) != b.charAt(i)) {
                    diffCount++;
                }

                if (diffCount == 3) {
                    break;
                }
            }

            char[] aChars = a.toCharArray(), bChars = b.toCharArray();

            Arrays.sort(aChars);
            Arrays.sort(bChars);

            System.out.println(diffCount == 2 && Arrays.equals(aChars, bChars) ? "YES" : "NO");
        }
    }
}
