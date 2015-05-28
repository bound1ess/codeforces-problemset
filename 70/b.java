import java.util.ArrayList;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class b {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int len = sc.nextInt();
        sc.nextLine();
        String msg = sc.nextLine();
        sc.close();

        ArrayList<String> parts = new ArrayList<>();
        int maxLen = 0;

        for (String part: split(msg)) {
            maxLen = Math.max(part.length(), maxLen);
            parts.add(part);
            //System.out.println("Added: " + part);
        }

        if (maxLen > len) {
            System.out.println("Impossible");
        } else {
            int count = 0;

            while (parts.size() > 0) {
                int tmpLen = parts.get(0).length(), tmpCount = 1;
                parts.remove(0);

                while (parts.size() > 0 && tmpLen + tmpCount + parts.get(0).length() <= len) {
                    tmpLen += parts.get(0).length();
                    tmpCount++;
                    parts.remove(0);
                }

                //System.out.println("Can send message of length " + (tmpLen + tmpCount - 1));

                count++;
            }

            System.out.println(count);
        }
    }

    private static ArrayList<String> split(final String msg) {
        Matcher matcher = Pattern.compile("([\\sa-zA-Z]+)(\\.|\\!|\\?)").matcher(msg);
        ArrayList<String> parts = new ArrayList<>();

        while (matcher.find()) {
            parts.add(matcher.group(0).trim());
        }

        return parts;
    }
}
