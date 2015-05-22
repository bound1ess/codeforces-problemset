import java.util.Scanner;
import java.util.ArrayList;

public class b {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        StringBuilder num = new StringBuilder(in.nextLine());
        in.close();

        int len = num.length();
        ArrayList<String> ans = new ArrayList<>();

        while (Integer.parseInt(num.toString()) > 0) {
            StringBuilder newNum = new StringBuilder();

            for (int i = 0; i < len; i++) {
                if (num.charAt(i) - '0' > 0) {
                    newNum.append("1");
                    //System.out.println((char)(num.charAt(i) - '0' - 1 + '0'));
                    num.setCharAt(i, (char)(num.charAt(i) - '0' - 1 + '0'));
                } else if (newNum.length() > 0) {
                    newNum.append("0");
                }
            }

            ans.add(newNum.toString());
        }

        System.out.println(ans.size());

        if (ans.size() > 0) {
            for (int i = 0; i < ans.size(); i++) {
                System.out.print(ans.get(i) + " ");
            }

            System.out.println("");
        }
    }
}
