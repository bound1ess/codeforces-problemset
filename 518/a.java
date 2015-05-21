import java.util.Scanner;

public class _518a {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        StringBuilder a = new StringBuilder(scan.nextLine());
        String b = new String(scan.nextLine());

        //System.out.println(a.toString());
        //System.out.println(b);

        scan.close();

        int i = a.length() - 1;

        while (a.charAt(i) == 'z' && i > 0) {
            a.setCharAt(i, 'a');
            i--;
        }

        //System.out.println(a.toString());

        a.setCharAt(i, (char)((int)a.charAt(i) + 1));

        if (b.compareTo(a.toString()) > 0) {
            System.out.println(a);
        } else {
            System.out.println("No such string");
        }
    }
}
