import java.util.Scanner;
import java.util.Vector;

public class a {
    final static private int N = 10;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Vector<String> a = new Vector<String>();

        String s = sc.nextLine();

        for (int i = 0; i < N; i++) {
            a.add(sc.nextLine());
        }

        for (int i = 0; i < (s.length() / N); i++) {
            int l = i * N;
            String sub = s.substring(l, l + N);

            for (int j = 0; j < N; j++) {
                if (a.get(j).equals(sub)) {
                    System.out.print(j);
                    break;
                }
            }
        }

        System.out.println("");
    }
}
