import java.util.Scanner;
import java.util.Collections;
import java.util.ArrayList;

public class b {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StringBuilder input = new StringBuilder();

        while (sc.hasNextLine()) {
            String line = sc.nextLine();

            //if (line.equals("stop")) {
            //    break;
            //}

            input.append(line);
        }

        sc.close();

        ArrayList<Integer> answer = solve(input.toString());

        Collections.sort(answer);

        for (Integer number: answer) {
            System.out.print(number + " ");
        }

        System.out.println("");
    }

    private static ArrayList<Integer> solve(final String input) {
        ArrayList<Integer> output = new ArrayList<>();
        int[] tdElems = new int[5000];
        int depth = -1;
        String[] tokens = tokenize(input);

        for (String token: tokens) {
            //System.out.println(token);
            switch (token) {
                case "td":
                    tdElems[depth]++;
                    break;
                case "/table":
                    output.add(tdElems[depth--]);
                    break;
                case "table":
                    tdElems[++depth] = 0;
                    break;
            }
        }

        return output;
    }

    private static String[] tokenize(final String input) {
        return input.replaceAll("[\\<\\>]+", " ").split("\\s+");
    }
}
