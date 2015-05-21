import java.util.ArrayList;
import java.util.Scanner;

public class b {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        ArrayList<Integer> l = new ArrayList<>(), r = new ArrayList<>();
        l.add(in.nextInt());
        r.add(in.nextInt());
        int t = in.nextInt(), d = in.nextInt();
        in.close();

        for (int i = 1; i <= t - 1; i++) {
            l.add(d + l.get(i - 1));
            r.add(d + r.get(i - 1));
        }

        int ans = 0;
        for (int i = 0; i < t; i++) {
            ans += Math.min(l.get(i), r.get(r.size() - i - 1));
        }
        System.out.println(ans);
    }
}
