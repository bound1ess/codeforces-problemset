import java.util.Scanner;
import java.util.HashMap;

public class c {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        in.nextLine();

        HashMap<String, Integer> map = new HashMap<>();

        for (int i = 0; i < n; i++) {
            String name = in.nextLine();

            if ( ! map.containsKey(name)) {
                map.put(name, 0);
                System.out.println("OK");
            } else {
                int id = map.get(name) + 1;

                System.out.println(name + id);
                map.put(name, id);
            }
        }

        in.close();
    }
}
