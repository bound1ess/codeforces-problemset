import java.io.*;
import java.util.regex.*;

public class c {

  private static final Pattern THROW_EXPR = Pattern.compile("throw\\((.+)\\)");
  private static final Pattern CATCH_EXPR = Pattern.compile("catch\\(([^,]+),\"(.+)\"\\)");

  public static void main(String[] args) throws IOException {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
    int lines = Integer.parseInt(reader.readLine()), blockLevel = 0, throwLevel = -1;
    boolean caught = false;
    String throwToken = null;

    for (int i = 0; i < lines; ++i) {
      String line = smartTrim(reader.readLine());

      if (caught || line.isEmpty()) {
        continue;
      }

      if (line.equals("try")) {
        ++blockLevel;
        continue;
      }

      if (line.startsWith("throw")) {
        throwLevel = blockLevel;
        throwToken = line;
        continue;
      }

      if (throwToken != null
        && getThrownType(throwToken).equals(parseCatchBlock(line, true))) {
        if (blockLevel == throwLevel) {
          writer.write(parseCatchBlock(line, false));
          writer.newLine();
          caught = true;
          continue;
        }
      }

      if (blockLevel == throwLevel) {
        --throwLevel;
      }

      --blockLevel;
    }

    reader.close();

    if ( ! caught) {
      writer.write("Unhandled Exception");
      writer.newLine();
    }

    writer.close();
  }

  private static String parseCatchBlock(String catchToken, boolean returnType) {
    Matcher match = CATCH_EXPR.matcher(catchToken);
    match.find();

    return returnType ? match.group(1) : match.group(2);
  }

  private static String getThrownType(String throwToken) {
    Matcher match = THROW_EXPR.matcher(throwToken);
    match.find();

    return match.group(1);
  }

  private static String smartTrim(String input) {
    StringBuilder output = new StringBuilder();
    boolean skip = true;

    for (int i = 0, n = input.length(); i < n; ++i) {
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
