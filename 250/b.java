import java.util.Scanner;
import java.util.ArrayList;

public class b {
    private final static int BLOCK_LEN = 4, BLOCKS = 8;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        in.nextLine();

        for (int i = 0; i < n; i++) {
            System.out.println(restore(in.nextLine()));
        }

        in.close();
    }

    private static String restore(final String addr) {
        ArrayList<String> parts = split(addr);
        StringBuilder newAddr = new StringBuilder();

        for (int i = 0; i < parts.size(); i++) {
            String part = parts.get(i);

            if ( ! part.equals("::")) {
                newAddr.append(part.length() == BLOCK_LEN ? part : complete(part));
                newAddr.append(":");
            } else {
                int before = i;
                int after = parts.size() - 1 - before;

                for (int j = 0; j < (BLOCKS - before - after); j++) {
                    newAddr.append("0000:");
                }
            }
        }

        return newAddr.substring(0, (BLOCK_LEN * BLOCKS) + BLOCKS - 1).toString();
    }

    private static ArrayList<String> split(final String addr) {
        ArrayList<String> parts = new ArrayList<>();
        StringBuilder buf = new StringBuilder();

        for (int i = 0; i < addr.length(); i++) {
            if (addr.charAt(i) != ':') {
                buf.append(addr.charAt(i));
                continue;
            }

            if (buf.length() > 0) {
                parts.add(buf.toString());
                buf.setLength(0);
            }

            if (addr.charAt(i + 1) == ':') {
                parts.add("::");
                i++; // jump over
            }
        }

        if (buf.length() > 0) {
            parts.add(buf.toString());
        }

        return parts;
    }

    private static String complete(final String addr) {
        StringBuilder newAddr = new StringBuilder();

        for (int i = 0; i < (BLOCK_LEN - addr.length()); i++) {
            newAddr.append("0");
        }

        return newAddr.append(addr).toString();
    }
}
