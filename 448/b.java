import java.util.Scanner;
import java.util.Arrays;

public class b {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.nextLine(), t = in.nextLine();
        in.close();

        if (isAutomaton(s, t)) {
            System.out.println("automaton");
        } else if (sort(s).equals(sort(t))) {
            System.out.println("array");
        } else if (isAutomaton(sort(s), sort(t))) {
            System.out.println("both");
        } else {
            System.out.println("need tree");
        }
    }

    private static boolean isAutomaton(final String s, final String t) {
        int j = 0;

        for (int i = 0; i < s.length(); i++) {
            if (t.charAt(j) == s.charAt(i)) {
                j++;
            }

            if (t.length() == j) {
                return true;
            }
        }

        return false;
    }

    private static String sort(final String str) {
        char[] chars = str.toCharArray();
        Arrays.sort(chars);

        return new String(chars);
    }
}
