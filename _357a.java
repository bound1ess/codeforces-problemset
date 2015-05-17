import java.util.Scanner;
import java.util.ArrayList;

public class _357a {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int m = sc.nextInt();
        ArrayList<Integer> b = new ArrayList<Integer>(m);

        for (int i = 0; i < m; i++) {
            if (i < 1) {
                b.add(i, sc.nextInt());
            } else {
                b.add(sc.nextInt() + b.get(i - 1));
            }
        }

        int x = sc.nextInt();
        int y = sc.nextInt();

        //for (int i = 0; i < m; i++) {
        //    System.out.println(i + " => " + b.get(i));
        //}

        for (int i = 0; i < m; i++) {
            if (b.get(i) >= x && y >= b.get(i)) { // <= first group
                //System.out.println("first group has " + b.get(i));

                if (b.get(m - 1) - b.get(i) >= x && y >= b.get(m - 1) - b.get(i)) {
                    System.out.println(i + 2);
                    return;
                }
            }
        }

        System.out.println(0);
    }
}
