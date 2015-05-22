import java.util.Scanner;

public class a {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt(),
            k = in.nextInt(),
            l = in.nextInt(),
            c = in.nextInt(),
            d = in.nextInt(),
            p = in.nextInt(),
            nl = in.nextInt(),
            np = in.nextInt();

        in.close();

        int tnl = k * l, tnp = p, tl = c * d;
        int ans = 0;

        while (tnl >= nl && tl > 0 && tnp >= np) {
            tnl -= nl;
            tnp -= np;
            tl--;
            ans++;
        }

        while (ans % n != 0) {
            ans--;
        }

        System.out.println(ans / n);
    }
}
