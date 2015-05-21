import java.util.Scanner;
import java.io.File;
//import java.io.FileOutputStream;
import java.io.PrintStream;
import java.io.FileNotFoundException;

public class a {

    public static void main(String[] args) throws FileNotFoundException {
        //Scanner sc = new Scanner(System.in);
        Scanner sc = new Scanner(new File("input.txt"));
        //System.setOut(new PrintStream(new FileOutputStream(new File("output.txt"))));
        PrintStream out = new PrintStream("output.txt");

        int n = sc.nextInt();
        int m = sc.nextInt();
        int k = (n > m) ? m : n;

        for (int i = 0; i < (n - k); i++) {
            out.print('B');
        }

        for (int i = 0; i < k; i++) {
            out.print("GB");
        }

        for (int i = 0; i < (m - k); i++) {
            out.print('G');
        }

        out.print("\n");
        out.close();
    }
}
