import java.util.Scanner;

public class b {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String str = in.nextLine();
        in.close();

        StringBuilder ans = new StringBuilder();

        int x = 0;

        for (int i = 0; i < str.length(); i++) {
            x += str.charAt(i) == 'x' ? 1 : -1;
        }

        for (int i = 0; i < Math.abs(x); i++) {
            ans.append(x > 0 ? 'x' : 'y');
        }

        System.out.println(ans.toString());
    }
}
