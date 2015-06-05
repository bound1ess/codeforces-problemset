import java.util.Scanner;

public class a {
    private final static String[] alcohol = {
        "ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA",
        "VODKA", "WHISKEY", "WINE"
    };

    public static void main(final String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt(), ans = 0;

        for (int i = 0; i < n; i++) {
            String input = sc.next();

            try {
                int parsed = Integer.parseInt(input);

                if (18 > parsed) {
                    //System.out.println("Check " + (i + 1) + "-th client");
                    ans++;
                }
            }
            catch (NumberFormatException error) {
                for (int j = 0; j < alcohol.length; j++) {
                    if (alcohol[j].equals(input)) {
                        //System.out.println("Check " + (i + 1) + "-th client");
                        ans++;
                        break;
                    }
                }
            }
        }

        sc.close();

        System.out.println(ans);
    }
}
