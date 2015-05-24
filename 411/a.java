import java.util.Scanner;

public class a {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String pswd = in.nextLine();
        in.close();

        if (pswd.length() > 4 && ! sameCase(pswd) && containsDigit(pswd)) {
            System.out.println("Correct");
        } else {
            System.out.println("Too weak");
        }
    }

    private static boolean sameCase(final String pswd) {
        int up = 0, down = 0;

        for (int i = 0; i < pswd.length(); i++) {
            int code = (int) pswd.charAt(i);

            if (code > 96) {
                down++;
            } else if (code > 64 && code < 91) {
                up++;
            }
        }

        return up < 1 || down < 1;
    }

    private static boolean containsDigit(final String pswd) {
        for (int i = 0; i < pswd.length(); i++) {
            int code = (int) pswd.charAt(i);

            if (47 < code && code < 58) {
                return true;
            }
        }

        return false;
    }
}
