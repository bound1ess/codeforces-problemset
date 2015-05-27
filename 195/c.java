import java.io.*;
import java.util.regex.*;

public class c {
    private static final Pattern THROW_EXPR = Pattern.compile("throw\\((.+)\\)");
    private static final Pattern CATCH_EXPR = Pattern.compile("catch\\(([^,]+),\"(.+)\"\\)");

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        int lines = Integer.parseInt(reader.readLine());
        int blockLevel = 0, throwLevel = -1;
        boolean caught = false;
        String throwToken = null;

        for (int i = 0; i < lines; i++) {
            String line = smartTrim(reader.readLine());

            if (caught) {
                continue;
            }

            if (line.isEmpty()) {
                continue;
            }

            if (line.equals("try")) {
                blockLevel++;
                continue;
            }

            if (line.startsWith("throw")) {
                throwLevel = blockLevel;
                throwToken = line;
                continue;
            }

            if (throwToken != null && getThrownType(throwToken).equals(parseCatchBlock(line, true))) {
                if (blockLevel == throwLevel) {
                    writer.write(parseCatchBlock(line, false) + "\n");
                    caught = true;
                    continue;
                }
            }

            if (blockLevel == throwLevel) {
                throwLevel--;
            }

            blockLevel--;
        }

        reader.close();

        if ( ! caught) {
            writer.write("Unhandled Exception\n");
        }

        writer.close();
    }

    private static String parseCatchBlock(final String catchToken, boolean returnType) {
        Matcher match = CATCH_EXPR.matcher(catchToken);
        match.find();

        //System.out.println(match.group(1) + " " + match.group(2));
        return returnType ? match.group(1) : match.group(2);
    }

    private static String getThrownType(final String throwToken) {
        Matcher match = THROW_EXPR.matcher(throwToken);
        match.find();

        //System.out.println("found " + match.group(1));
        return match.group(1);
    }

    private static String smartTrim(final String input) {
        StringBuilder output = new StringBuilder();
        boolean skip = true;

        for (int i = 0; i < input.length(); i++) {
            char symbol = input.charAt(i);

            if (symbol == '"') {
                skip = ! skip;
            }

            if ((symbol == ' ' && ! skip) || symbol != ' ') {
                output.append(symbol);
            }
        }

        return output.toString();
    }
}
