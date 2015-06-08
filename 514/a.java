public class a {

    public static void main(final String[] args) {
        StringBuilder ans = new StringBuilder(new java.util.Scanner(System.in).nextLine());

        for (int i = 0; i < ans.length(); i++) {
            if (ans.charAt(i) == '9') {
                if (ans.length() == 1 || i == 0) {
                    continue;
                }
            }

            if (ans.charAt(i) - '0' >= 5) {
                ans.setCharAt(i, Integer.toString(9 - (ans.charAt(i) - '0')).charAt(0));
            }
        }

        System.out.println(ans.toString());
    }
}
