import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;

final public class a {

    final public static void main(final String[] arguments) {
        final Scanner input = new Scanner(System.in);
        final int n = Integer.parseInt(input.nextLine());
        final Map<String, Integer> reposts = new HashMap<>();
        int maxReposts = 0;

        reposts.put("polycarp", 1);

        for (int i = 0; i < n; i++) {
            final String[] words = input.nextLine().toLowerCase().split(" ");
            reposts.put(words[0], reposts.get(words[2]) + 1);
            maxReposts = Math.max(maxReposts, reposts.get(words[0]));
        }

        System.out.println(maxReposts);
    }
}
