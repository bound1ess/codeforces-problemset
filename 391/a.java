import java.util.Scanner;

public class a {

    public static void main(final String[] args) {
        String code = new Scanner(System.in).nextLine();
        int seq = 1, ans = 0;
        char prev = 'Z';
        for (char chr: code.toCharArray()) {
            if (prev == chr) {
                seq++;
            } else {
                //System.out.println(chr + ", lose " + seq);
                if (seq % 2 == 0) {
                    ans++;
                }
                seq = 1;
            }
            prev = chr;
        }
        if (seq % 2 == 0) {
            ans++;
        }
        System.out.println(ans);
    }
}
