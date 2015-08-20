import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class b {

  public static void main(String[] cliArgs) {
    Scanner in = new Scanner(System.in);
    String cmd = in.nextLine();
    List<String> args = new ArrayList<>();
    boolean asIs = false;
    StringBuilder buf = new StringBuilder();
    in.close();

    for (int i = 0; i < cmd.length(); ++i) {
      if (cmd.charAt(i) == '"') {
        asIs = ! asIs;

        if ( ! asIs) {
          args.add(buf.toString());
          buf.setLength(0);
        }

        continue;
      }

      if ( ! asIs && cmd.charAt(i) == ' ' && buf.length() > 0) {
        args.add(buf.toString());
        buf.setLength(0);
        continue;
      }

      if (asIs || cmd.charAt(i) != ' ') {
        buf.append(cmd.charAt(i));
      }
    }

    if (buf.length() > 0) {
      args.add(buf.toString());
    }

    for (int i = 0; i < args.size(); ++i) {
      System.out.println("<" + args.get(i) + ">");
    }
  }
}
